#include<bits/stdc++.h>
using namespace std;
#define N 5005

int n,ans;
int a[3],b[3];
int dp[N*N*2];

int main()
{
	
	cin>>n;
	cin>>a[0]>>a[1]>>a[2];
	cin>>b[0]>>b[1]>>b[2];
	for(int i=0;i<=n;i++)
		dp[i]=i;
	for(int i=0;i<=n;i++)
	for(int j=0;j<3;j++)
		if(i+a[j]<=n) dp[i+a[j]]=max(dp[i+a[j]],dp[i]+b[j]);
	long long mx=0;
	for(int i=0;i<=n;i++)
		mx=max(mx,dp[i]+n-i);
	
	n=mx;
	for(int i=0;i<=n;i++)
		dp[i]=i;
	for(int i=0;i<=n;i++)
	for(int j=0;j<3;j++)
		if(i+b[j]<=n) dp[i+b[j]]=max(dp[i+b[j]],dp[i]+a[j]);
	long long mx2=0;
	for(int i=0;i<=n;i++)
		mx2=max(mx2,dp[i]+n-i);
	cout<<mx2<<'\n';
	
	return 0;
}