#include<bits/stdc++.h>
using namespace std;
int main(){int N;cin>>N;vector<int>a(N);for(int i=0;i<N;i++)cin>>a.at(i);
           sort(a.begin(),a.end());int x=0;for(int i=0;i<N;i++){if((i+1)%2)x+=a.at(i);if(i%2)x-=a.at(i);}
x=abs(x);cout<<x<<endl;}