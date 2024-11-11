#include <iostream>
using namespace std;int main(){int a,b,c;cin>>a>>b>>c;int x=0;for(int i=1;i<=a;++i){int d=0,s=i;while(s)d+=s%10,s/=10;if(b<=d&&d<=c)x+=i;}cout<<x<<endl;}