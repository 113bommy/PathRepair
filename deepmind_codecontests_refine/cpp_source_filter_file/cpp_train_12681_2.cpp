#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	string str1,str2;
	cin>>str1>>str2;

	int m=str1.length(),n=str2.length();
	int dp[m+1][n+1];

	memset(dp,0,sizeof(dp));

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(str1[i-1]==str2[j-1])
				dp[i][j]=1+dp[i-1][j-1];

			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}

	string ans="";

	int i=m,j=n;
	while(i>0 && j>0)
	{
		if(str1[i-1]==str2[j-1])
		{
			ans=str1[i-1]+ans;;
			i--;
			j--;a
		}

		else
		{
			if(dp[i-1][j]>dp[i][j-1])
				i--;

			else
				j--;
		}
	}

	cout<<ans;
	return 0;
}