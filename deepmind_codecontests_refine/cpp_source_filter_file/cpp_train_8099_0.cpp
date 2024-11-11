#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const ll MOD=1e9+7; //定义MOD代替1e9+7
int n;
ll dp[101][4][4][4],ans; 
int main()
{
	cin>>n;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			for(k=0;k<4;k++)
				if((i==0&&j==1&&k==2)||(i==0&&j==2&&k==1)||(i==1&&j==0&&k==2))
					dp[3][i][j][k]=0;
				else
					dp[3][i][j][k]=1;

	for (int len=4;len<=n;++len)
		for (int i=0;i<4;++i)
			for (int j=0;j<4;++j)
				for (int k=0;k<4;++k)
					for (int l=0;l<4;++l)
					{
						if (j==0 && k==2 && l==1) continue;
						if (j==2 && k==0 && l==1) continue;
						if (j==0 && k==1 && l==2) continue;
						if (i==0 && k==2 && l==1) continue;
						if (i==0 && j==2 && l==1) continue;
						dp[len][j][k][l]+=dp[len-1][i][j][k];
						dp[len][j][k][l]%=MOD;
					}
	for (int i=0;i<4;++i)
		for (int j=0;j<4;++j)
			for (int k=0;k<4;++k)
				ans+=dp[n][i][j][k],ans%=MOD;//最终求len=n时的总数，累加
	cout<<ans; 
	return 0;
}