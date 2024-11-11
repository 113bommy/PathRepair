#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<complex>
#include<string>
#include<cstring>
using namespace std;
#define rep2(x,from,to) for(long long x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
#define INF 100000000
#define debug(x) cout<<#x<<": "<<x<<endl

#define all(x) x.begin(),x.end()
typedef pair<long long,long long> P;
typedef pair<long long,P> PP;

long long n,q;
long long v,u;
long long del;
int main()
{
	cin>>n>>q;
	del=n-2;
	rep(i,q)
	{
		cin>>v>>u;
if(n==1)
{
if(v>u)cout<<u<<endl;
else cout<<v<<endl;
continue;
}
		v+=del;
		u+=del;
		while(1)
		{
			if(u==v)
			{
				cout<<u-del<<endl;
				break;
			}
			if(u>v)
			{
				u/=n;u+=del;
			}
			else
			{
				v/=n;
				v+=del;
			}
		}
	}
	return 0;
}