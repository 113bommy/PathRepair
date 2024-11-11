#include<bits/stdc++.h>
using namespace std;
int main(){int n,k,x,d=0;cin>>n>>k;for(int i=0;i<n;i++)cin>>x;if(x*2<k)d+=x*2;else d+=(k-x)*2;}cout<<d<<endl;}