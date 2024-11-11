#include<bits/stdc++.h> 
using namespace std;
const int N=2e5+5;
int n,mod1,mod2;
int md1[N],md2[N];
int ans1,ans2,temp;
char s[N];
void solve(int n)
{
	while (n>0)
	{
		int q=n,p=0;
		while (q>0)
		{
			q=q&(q-1);
			p++;
		}
		n=n%p;
		temp++;
	}
}
int main()
{
	cin>>n;
	scanf("%s",&s);
	for (int i=0;i<n;i++) if (s[i]=='1') mod1++;
	mod2=mod1-1,mod1++;
	if (mod2==0)
	{
		md1[n-1]=md2[n-1]=1;
		for (int i=n-2;i>=0;i--) md1[i]=md1[i+1]*2%mod1;
		for (int i=n-1;i>=0;i--) if (s[i]=='1') ans1=(ans1+md1[i])%mod1;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='1') cout<<0<<endl;
			if (s[i]=='0')
			{
				temp=1;
				int tmp=(ans1+md1[i])%mod1;
				solve(tmp);
				cout<<temp<<endl;
			}
		}
		return 0;
	}
	md1[n-1]=md2[n-1]=1;
	for (int i=n-2;i>=0;i--) md1[i]=md1[i+1]*2%mod1,md2[i]=md2[i+1]*2%mod2;
	for (int i=n-1;i>=0;i--) if (s[i]=='1') ans1=(ans1+md1[i])%mod1,ans2=(ans2+md2[i])%mod2;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='1')
		{
			temp=1;
			int tmp=(ans2-md2[i]+mod2)%mod2;
			solve(tmp);
			cout<<temp<<endl;
		}
		if (s[i]=='0')
		{
			temp=1;
			int tmp=(ans1+md1[i])%mod1;
			solve(tmp);
			cout<<temp<<endl;
		}
	}
}