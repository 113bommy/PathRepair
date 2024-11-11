#include<bits/stdc++.h>
using namespace std;
int main(){int n,s=0;cin>>n,for(int i=1;i<=n;i*=10)s+=n/i%10;if(n%s)cout<<"No"<<endl;else cout<<"Yes"<<endl;}