#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long f[2005][2005],ny[4000005],s[4000005],t[4000005];
long long f(long long n,long long m)
{
	return s[n]*t[m]%mod*t[n-m]%mod;
}
int main()
{
	long long n,k,i,j;
	cin>>n>>k;
	if(k==1)
	{
		puts("1");
		return 0;
	}
	ny[1]=1;
	for(i=2;i<=4000000;i++)
	{
		ny[i]=(mod-mod/i)*ny[mod%i]%mod;
	}
	s[0]=1,t[0]=1;
	for(i=1;i<=4000000;i++)
	{
		s[i]=s[i-1]*i%mod;
		t[i]=t[i-1]*ny[i]%mod;
	}
	for(i=0;i<=n;i++)
		f[i][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=i;j++)
		{
			f[i][j]=f[i-1][j]+f[i][j-1]*(n-j+1)%mod*f(n*k-i-1-(j-1)*(k-1),k-2)%mod;
			f[i][j]%=mod;
		}
	}
	cout<<f[n][n]%mod<<endl;
	return 0;

}