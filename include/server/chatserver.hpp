#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>

using namespace muduo;
using namespace muduo::net;

class ChatServer
{
public:
    //初始化聊天服务器对象
    ChatServer(EventLoop* loop,
            const InetAddress& listenAddr,
            const string& nameArg);

    //启动服务
    void start();

private:
    //连接相关的回调函数
    void onConnect(const TcpConnectionPtr&);

    //消息相关的回调函数
    void onMessage(const TcpConnectionPtr&,Buffer*,Timestamp);

    TcpServer _server;      //服务器对象
    EventLoop* _loop;       //指向 循环事件对象的 指针
};


#endif