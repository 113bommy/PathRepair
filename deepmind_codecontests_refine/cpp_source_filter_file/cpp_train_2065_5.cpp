#include<bits/stdc++.h>
using namespace std;
int main(){int n,x,p=29;cin>>n;for(int i=0;i<n;i++){cin>>x;for(int j=0;j<=p;j++)if(x%2){p=j;break;}else(x/=2)}cout<<p<<endl;}