#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
typedef int ll;
typedef pair<ll,ll> P;
typedef double db;
const ll INF = 0xfffffff;
ll n,k;
ll c[5000],r[5000];
ll d[5000];
ll a[10000],b[10000];
ll tmax[5000];
vector<ll> G[5000];
priority_queue<P,vector<P>,greater<P> > q;queue<P> q2;
int main()
{
	scanf("%d%d",&n,&k);
	for(ll i=0;i<n;i++) scanf("%d%d",&c[i],&r[i]);
	for(ll i=0;i<k;i++){
		scanf("%d%d",&a[i],&b[i]);
		a[i]--;
		b[i]--;
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	fill(d,d+n,INF);
	d[0]=0;
	tmax[0]=0;
	q.push(P(d[0]+c[0],0));
	while(!q.empty()){
		P p=q.top();
		q.pop();
		if(d[p.second]+c[p.second]<p.first) continue;
		q2.push(P(p.second,r[p.second]));
		while(!q2.empty()){
			P t=q2.front();
			q2.pop();
			if(d[t.first]>p.first){
				d[t.first]=p.first;
				tmax[t.first]=t.second;
				q.push(P(d[t.first]+c[t.first],t.first));
			}
			if(t.second) for(ll i=0;i<G[x].size();++i) if(d[G[t.first][i]]>p.first||tmax[G[t.first][i]]<t.second-1) q2.push(P(G[t.first][i],t.second-1));
		}
	}
	printf("%d\n",d[n-1]);
}