#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
long long INF=99999999;
namespace MCF {
    // required <string.h> <vector> <queue> <algorithm>
    #define MAXN 1100
    #define MAXM 1010000
    #define wint int
    #define cint long long
    const wint wEPS = 0;
    const wint wINF = 1001001001;
    const cint cEPS = 0;
    const cint cINF = 100100100100100100LL;
    int n, m, ptr[MAXN], next[MAXM], zu[MAXM];
    wint capa[MAXM], tof;
    cint cost[MAXM], toc, d[MAXN], pot[MAXN];
    int vis[MAXN], pree[MAXN];
    void init(int _n) {
        n = _n; m = 0; memset(ptr, ~0, n * 4);
    }
    void ae(int u, int v, wint w, cint c) {
        next[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa[m] = w; cost[m] = +c; ++m;
        next[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa[m] = 0; cost[m] = -c; ++m;
    }
    bool solve(int src, int ink, wint flo = wINF) {
        int i, u, v;
        wint f;
        cint c, cc;
        memset(pot, 0, n * sizeof(cint));
         
        for (bool cont = 1; cont; ) {
            cont = 0;
            for (u = 0; u < n; ++u) for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
                if (pot[zu[i]] > pot[u] + cost[i] + cEPS) {
                    pot[zu[i]] = pot[u] + cost[i]; cont = 1;
                }
            }
        }
        for (toc = 0, tof = 0; tof + wEPS < flo; ) {
            typedef pair<cint,int> node;
            priority_queue< node,vector<node>,greater<node> > q;
            for (u = 0; u < n; ++u) { d[u] = cINF; vis[u] = 0; }
            for (q.push(make_pair(d[src] = 0, src)); !q.empty(); ) {
                c = q.top().first; u = q.top().second; q.pop();
                if (vis[u]++) continue;
                for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
                    cc = c + cost[i] + pot[u] - pot[v = zu[i]];
                    if (d[v] > cc + cEPS) { q.push(make_pair(d[v] = cc, v)); pree[v] = i; }
                }
            }
            if (!vis[ink]) return 0;
            f = flo - tof;
            for (v = ink; v != src; v = zu[i ^ 1]) { i = pree[v]; f=min(f,capa[i]); }
            for (v = ink; v != src; v = zu[i ^ 1]) { i = pree[v]; capa[i] -= f; capa[i ^ 1] += f; }
            tof += f;
            toc += f * (d[ink] - pot[src] + pot[ink]);
            for (u = 0; u < n; ++u) pot[u] += d[u];
        }
        return 1;
    }
}
int in[1100];
int out[1100];
vector<pair<int,int> >g[1100];
int ijk[1100];
int v[1100];
int tp[1100];
int now;
void dfs(int a){
	v[a]=1;
	for(int i=0;i<g[a].size();i++){
		if(v[g[a][i].first])continue;
		dfs(g[a][i].first);
	}
	tp[now--]=a;
}
int main(){
	int a;scanf("%d",&a);
	MCF::init(a+2);
	int sum=0;
	long long ans=0;
	for(int i=0;i<a;i++){
		int p;
		scanf("%d",&p);
		sum+=p;
		out[i]=p;
		for(int j=0;j<p;j++){
			int s,t;scanf("%d%d",&s,&t);
			ans+=t;
			s--;
			g[i].push_back(make_pair(s,t));
			in[s]++;
		}
	}
	int fl=0;
	now=a-1;
	for(int i=0;i<a;i++){
		if(v[i])continue;
		dfs(i);
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<g[i].size();j++){
			MCF::ae(i,g[i][j].first,INF,g[i][j].second);
		}
	}
	for(int i=0;i<a;i++){
		if(i==0||out[i]<in[i]){
			if(i==0)MCF::ae(a,i,INF,0);
			else MCF::ae(a,i,in[i]-out[i],0);
		}
		if(out[i]>in[i]){
			fl+=out[i]-in[i];
			MCF::ae(i,a+1,out[i]-in[i],0);
		}
	}
	MCF::solve(a,a+1,fl);
	
	long long ret=MCF::toc+ans;
	printf("%lld\n",ret);
}