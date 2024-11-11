#include<bits/stdc++.h>
using namespace std;
int n;
int a[101][101],dp[101][101];
int main()
{
	cin>>n;
	for(int i=1;i<=2;i++)
	for(int j=1;j<=n;j++)
    {
    	cin>>dp[i][j];
	}
    
	for(int i=1;i<=2;i++)
	for(int j=1;j<=n;j++)
	{
		dp[i][j]=max(dp[i-1][j],dp[i][j-1])+dp[i][j];
	}
	cout<<dp[n2][n]<<endl;
}