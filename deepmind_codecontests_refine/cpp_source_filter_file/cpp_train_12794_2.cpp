//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define s(x) scanf("%d",&x)
#define rep(i,x) for(int i=0;i<x;i++)
#define geta 100000
vector<int>za[200005];
vector<int>all;
int main()
{
	int n;
	scanf("%d",&n);
	P p[100005];
	int xmi=INF,xma=-INF,ymi=INF,yma=-INF;
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		p[i]=mp(x+y,x-y);
		xmi=min(xmi,x+y);
		xma=max(xma,x+y);
		ymi=min(ymi,x-y);
		yma=max(yma,x-y);
	}
	if(xma-xmi<yma-ymi)
	{
		for(int i=0;i<n;i++)swap(p[i].first,p[i].second);
		swap(xma,yma);
		swap(xmi,ymi);
	}
	for(int i=0;i<n;i++)
	{
		za[p[i].second+geta].pb(p[i].first);
		all.pb(p[i].first);
	}
	sort(all.begin(),all.end());
	for(int  i=0;i<200005;i++) sort(za[i].begin(),za[i].end());
	int lb=0;
	int ub=xma-xmi;
	int ano=yma-ymi;
	while(ub-lb>1)
	{
		int mid=(lb+ub)>>1;
		if(mid>=ano)
		{
			int d=upper_bound(all.begin(),all.end(),all[0]+mid)-all.begin();
			if(d==all.size() || all[all.size()-1]-all[d]<=mid) ub=mid;
			else lb=mid;
		}
		else
		{
			for(int i=yma+geta;i>ymi+mid+geta;i--)
			{
				if(za[i].empty())  continue;
				if(za[i][za[i].size()-1]>xmi+mid) goto next;
			}
			for(int i=ymi+geta;i<yma-mid+geta;i++)
			{
				if(za[i].empty())  continue;
				if(za[i][0]<xma-mid) goto next;
			}
			for(int i=yma-mid+geta;i<=ymi+mid+geta;i++)
			{
				if(za[i].empty())  continue;
				int d=upper_bound(za[i].begin(),za[i].end(),xmi+mid)-za[i].begin();
				int e=lower_bound(za[i].begin(),za[i].end(),xma-mid)-za[i].begin();
				if(d<e) goto next;
			}
			ub=mid;
			continue;
			next:;
			for(int i=yma+geta;i>ymi+mid+geta;i--)
			{
				if(za[i].empty())  continue;
				if(za[i][0]<xma-mid) goto next2;
			}
			for(int i=ymi+geta;i<yma-mid+geta;i++)
			{
				if(za[i].empty())  continue;
				if(za[i][za[i].size()-1]>xmi+mid) goto next2;
			}
			for(int i=yma-mid+geta;i<=ymi+mid+geta;i++)
			{
				if(za[i].empty())  continue;
				int d=upper_bound(za[i].begin(),za[i].end(),xmi+mid)-za[i].begin();
				int e=lower_bound(za[i].begin(),za[i].end(),xma-mid)-za[i].begin();
				if(d<e) goto next2;
			}
			ub=mid;
			continue;
			next2;
			lb=mid;
		}
	}
	printf("%d\n",ub);
}