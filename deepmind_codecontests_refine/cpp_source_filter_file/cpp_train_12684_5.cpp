#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=2e5+10;

int n;
char a[maxn];
int next[maxn][26];
int dp[maxn];
int last;

void dfs(int p)
{
	if (p>n) 
	{
		printf("a\n");
		return;
	}
	for(int i=0;i<26;i++)
	{
		if (next[p][i]==-1)
		{
			printf("%c",i+'a');
			return;
		}
		if (dp[p]==dp[next[p][i]+1]+1)
		{
			printf("%c",i+'a');
			dfs(next[p][i]+1);
			return;
		}
	}
}

int main() 
{
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=0;i<26;i++)
	{
		last=-1;
		for(int j=n;j>=1;j--)
		{
			if (a[j]-'a'==i) last=j;
			next[j][i]=last;
		}
	}
	
	dp[n+1]=1;
	for(int i=n;i>=1;i--)
	{
		dp[i]=n+1;
		for(int j=0;j<26;j++)
		{
			if (next[i][j]==-1) 
			{
				dp[i]=1;
				break;
			}
			dp[i]=min(dp[i],dp[next[i][j]+1]+1);
		}
	}
	
	dfs(1);
	printf("\n");
	return 0;
}