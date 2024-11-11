#include<bits/stdc++.h>

using namespace std;

const int maxn=1e5+500;

long long gcd(long long a,long long b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
	long long n,m;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	long long l=n/gcd(n,m)*m;
	int flag=1;
	long long time1=l/m,time2=l/n;
	for(int i=0;i<(int)max(n,m);i++)
    {
		if(s[time1*i%n]!=t[time2*i%m])
		{
			flag=0;
			break;
		}
	}
	cout<<(flag?l:-1);
}
