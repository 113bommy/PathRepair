/***********************
*  Author: xuziyuan    * 
***********************/

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++)
#define LL long long
#define pii pair <LL,LL>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

LL n,d,ans=0;
LL a[200010],par[200010];
vector <pair <LL,pii> > v;

LL FIND(LL pos)//dsu
{
	if(par[pos]!=pos) par[pos]=FIND(par[pos]);
	return par[pos];
}

void UNION(LL pos1,LL pos2)
{
	par[FIND(pos1)]=FIND(pos2);
}

void solve(LL lb,LL ub)//分治
{
	if(lb==ub) return;//只剩一个 
	LL mid=(lb+ub)/2,mn=1e18,lbest,rbest;
	for(LL i=lb;i<=mid;i++)
	{
		if(a[i]-d*i<mn)//左边是编号较小的一组，所以是减 
		{
			mn=a[i]-d*i;
			lbest=i;
		}
	}
	mn=1e18;
	for(LL i=mid+1;i<=ub;i++)
	{
		if(a[i]+d*i<mn)//右边是编号较大的一组，所以是加 
		{
			mn=a[i]+d*i;
			rbest=i;
		}
	}
	for(LL i=lb;i<=mid;i++)
	{
		LL val1=a[i]-d*i,val2=a[rbest]+d*rbest;
		v.pb({val1+val2,{i,rbest}});
	}
	for(LL i=mid+1;i<=ub;i++)
	{
		LL val1=a[i]+d*i,val2=a[lbest]-d*lbest;
		v.pb({val1+val2,{lbest,i}});
	}
	solve(lb,mid);
	solve(mid+1,ub);
} 

int main()
{
	rep(i,200005) par[i]=i;
	cin>>n>>d;
	rep(i,n) scanf("%I64d",&a[i]);
	solve(0,n-1);
	sort(v.begin(),v.end());
	rep(i,v.size())
	{
		if(FIND(v[i].se.fi)==FIND(v[i].se.se)) continue;
		UNION(v[i].se.fi,v[i].se.se);
		ans+=v[i].fi;
	}
	cout<<ans<<endl;
	rt0;
}
/*
在连通两个区域时，只连接两边的最好的点是不行的
比如：
如果只连接两边的最好的点： 
(1,val:200)-(2,val:10)
           /
(3,val:100)-(4,val:200)
这时，总消费是623；
 
如程序中的，连接一边的所有点和另一边的最好的点
(1,val:200)-(2,val:10)
           / |
(3,val:100) (4,val:200)
这时，总消费是534
因为，一开始被分在某一边的某个点不一定连自己这边的某个点是最优的，
可能连另一边的最好的点更佳 
*/