#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<vector>
#include<ctime>
#define ll long long
#define pr(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define N 210000
int n,i,a[N],j,last[30],ans[N],dp[N],next[N][30];
char s[N];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (i=1;i<=n;i++)
	a[i]=s[i-1]-'a'+1;
	for (i=1;i<=26;i++) last[i]=n+1;
	for (i=n;i>=1;i--)
	{
		last[a[i]]=i;
		for (j=1;j<=26;j++) next[i][j]=last[j];
	}
	for (i=1;i<=n+1;i++) dp[i]=10000000;
	for (i=n;i>=1;i--)
	{
		for (j=1;j<=26;j++)
		{
			if (dp[next[i][j]+1]+1<dp[i])
			dp[i]=dp[next[i][j]+1]+1,ans[i]=j;
		}
	}
	//printf("%d\n",dp[1]);
	int now=1;
	while (now<=n)
	{
		printf("%c",ans[now]+'a'-1);
		now=next[now][ans[now]]+1;
	}
	return 0;
}