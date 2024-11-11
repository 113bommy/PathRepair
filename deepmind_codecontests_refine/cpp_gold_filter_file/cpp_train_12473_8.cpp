#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main (){

ll n,a[100009],dp[100009];
cin>>n;
for(int i=0;i<n;i++)cin>>a[i];
dp[n-2]=abs(a[n-1]-a[n-2]);
dp[n-1]=0;
for(int i=n-3;i>=0;i--)
dp[i]=min(abs(a[i+2]-a[i])+dp[i+2],abs(a[i+1]-a[i])+dp[i+1]);

cout<<dp[0]<<endl;
}