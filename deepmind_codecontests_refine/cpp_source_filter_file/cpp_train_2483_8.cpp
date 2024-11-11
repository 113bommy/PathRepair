#include<stdio.h>
using namespace std;int g[89];int main(){int n,m;cin>>n>>m;for(int i=0;i<m;i++){int a,b;cin>>a>>b;g[a]++;g[b]++;}for(int i=1;i<=n;i++)cout<<g[i]<<endl;}
