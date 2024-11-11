#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
string s;

int cnt[3005];
int mx[3005], mn[3005];
int dp[3005][3005];
signed main()
{
	cin>>n>>m>>s;
	for(int i=1; i<=n; i++)
	{
		cnt[i]=cnt[i-1]+(s[i-1]=='1');
		mx[i]=cnt[i], mn[i]=cnt[i];
	}
	for(int i=1; i<=m; i++)
	{
		int l, r;
		cin>>l>>r;

		int lol=mn[r]-mn[l-1], lel=mx[r]-mx[l-1];

		for(int j=l; j<=r; j++)
		{
			mn[j]=min(mn[j], mn[l-1]+max(0, lol-(r-j)));
			mx[j]=max(mx[j], mx[l-1]+min(j-l+1, lel));
		}
	}
	// for(int i=1; i<=n; i++)
	// {
	// 	cout<<mx[i]<<" "<<mn[i]<<endl;
	// }
	dp[0][0]=1;
	for(int i=1; i<=n; i++)
	{
		for(int j=mn[i]; j<=mx[i]; j++)
		{
			if(j>0)
			{
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
			dp[i][j]%=1000000007;
		}
	}
	cout<<dp[n][cnt[n]];
}