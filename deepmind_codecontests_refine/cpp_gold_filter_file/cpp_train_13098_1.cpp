#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, int> pr;

#define MAX (ll)(1e5)
#define INF (1ll<<60)

struct edge{
	int to;
	ll cost;
};

int n, m;
vector<edge> yen[MAX+1], snk[MAX+1];
ll cost_y[MAX+1], cost_s[MAX+1];

void dijkstra(int s, vector<edge> g[], ll d[]){
	priority_queue<pr, vector<pr>, greater<pr>> que;
	fill(d, d+n+1, INF);
	d[s]=0;
	que.push(pr(0, s));

	while(!que.empty()){
		pr p=que.top();
		que.pop();
		int v=p.second;
		if(d[v]<p.first) continue;
		for(int i=0; i<g[v].size(); i++){
			edge e=g[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push(pr(d[e.to], e.to));
			}
		}
	}
	return;
}

int main(){
	int s, t;
	cin >> n >> m >> s >> t;
	for(int i=0; i<m; i++){
		int u, v;
		ll a, b;
		cin >> u >> v >> a >> b;
		yen[u].push_back(edge{v, a});
		yen[v].push_back(edge{u, a});
		snk[u].push_back(edge{v, b});
		snk[v].push_back(edge{u, b});
	}

	dijkstra(s, yen, cost_y);
	dijkstra(t, snk, cost_s);

	vector<ll> ans(n+1);
	ll m_cost=INF;
	for(int i=n; i>0; i--){
		m_cost=min(m_cost, cost_y[i]+cost_s[i]);
		ans[i]=(ll)(1e15)-m_cost;
	}
	for(int i=1; i<=n; i++) cout << ans[i] << endl;
	return 0;
}