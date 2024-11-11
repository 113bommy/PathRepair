#include<iostream>
#include<queue>
using namespace std;

int main()
{
priority_queue<int> que;
for(int i=0;i<10;i++)
{
int t;
cin>>t;
que.push_back(t);
}
for(int i=0;i<3;i++)
{
cout<<que.top()<<endl;
que.pop();
}
return 0;
}