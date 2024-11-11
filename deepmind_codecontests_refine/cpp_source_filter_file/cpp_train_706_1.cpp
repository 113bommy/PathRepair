#include<bits/stdc++.h>
using namespace std;
int dp[105][100005]，a[105],n,k;
const int MOD=1e9+7;
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<=a[0];i++)
		dp[0][i]=1;
	for(int i=1;i<n;i++)
	{
		vector<int>vec(k+1);
		vec[0]=dp[i-1][0];
		for(int j=1;j<k+1;j++)
			vec[j]=(vec[j-1]+dp[i-1][j])%MOD;
		for(int j=0;j<k+1;j++)
		{
			if(j>a[i])
				dp[i][j]=(vec[j]+MOD-vec[j-a[i]-1])%MOD;
			else
				dp[i][j]=vec[j];
		}
	}
	cout<<dp[n-1][k];
	return 0;
}