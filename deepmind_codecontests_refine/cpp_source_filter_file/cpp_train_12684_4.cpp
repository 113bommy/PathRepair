#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 200010
#define INF 9999999
using namespace std;
int n,pos[233],next[maxn][27],dp[maxn],now;
char s[maxn];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	dp[n+1]=1;
	for (int i=0;i<26;++i) pos[i]=-1;
	for (int i=n;i>=1;--i)
	  {
	  	pos[s[i]-'a']=i;
	  	for (int j=0;j<26;++j)
	  	  next[i][j]=pos[j];
	  }
	for (int i=n;i>=1;--i)
	{
		int tmp=INF;
		for (int j=0;j<26;++j) 
		tmp=min(tmp,dp[next[i][j]+1]);
	    dp[i]=tmp+1;
	}
	now=1;
	while (now>0)
	{
		for (int j=0;j<26;++j)
		  if (dp[now]==dp[next[now][j]+1]+1)
		  {
		  	  now=next[now][j]+1;
		  	  printf("%c",'a'+j);
			  break;
		  }
	}
	printf("\n");
	return 0;
}