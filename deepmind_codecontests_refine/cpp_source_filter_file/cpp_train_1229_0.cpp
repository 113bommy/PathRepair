#include<bits/stdc++.h>
using naamespace std;
int dp[100007],a[107],n,k;
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<=k;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i<a[j]) break;
			if(!dp[i-a[j]])
			{
				dp[i]=1;
				break;
			}
		}
	}
	if(dp[k]) cout<<"First";
	else cout<<"Second";
}