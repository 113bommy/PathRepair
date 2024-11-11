#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,dp[200005],last[30],pre[200005],mi;
char ans[200005];
string st;
void print(int x)
{
	cout<<ans[x];
	if (pre[x]<st.length()) print(pre[x]+1);
}
int main()
{
	cin>>st;
	for (i=1;i<=26;i++) last[i]=st.length();
	dp[st.length()]=1;a
	pre[st.length()]=st.length()+1;
	for (i=st.length();i>=0;i--)
	{
		last[st[i]-'a'+1]=i;
		mi=1;
		for (j=1;j<=26;j++) 
		{
			if (dp[last[j]+1]<dp[last[mi]+1])
			{
				mi=j;
			}
		}
		ans[i]=mi+'a'-1;
		dp[i]=dp[last[mi]+1]+1;
		pre[i]=last[mi];
	}
	print(0);
	return 0;
}