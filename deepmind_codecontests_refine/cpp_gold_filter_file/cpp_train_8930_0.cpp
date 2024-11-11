#include <iostream>
#include <vector>
#include <queue>
#define llint long long
#define inf 1e18

using namespace std;

struct edge{
	llint to, cap, rev;
	edge(llint a, llint b, llint c){
		to = a, cap = b, rev = c;
	}
};

int n;
llint p[100005], q[100005];
llint a[100005], b[100005];

vector<edge> G[100005];
int S, T;
llint level[100005], iter[100005];


void bfs(llint s)
{
	for(int i = 1; i <= T; i++) level[i] = inf;
	level[s] = 0;
	
	queue<int> Q;
	Q.push(s);
	while(Q.size()){
		int v = Q.front();
		Q.pop();
		for(int i = 0; i < G[v].size(); i++){
			int u = G[v][i].to;
			if(G[v][i].cap <= 0 || level[u] < inf) continue;
			level[u] = level[v] + 1;
			Q.push(u);
		}
	}
}

llint dfs(int v, llint f)
{
	if(v == T) return f;
	
	llint ret;
	for(llint &i = iter[v]; i < G[v].size(); i++){
		if(level[v] >= level[G[v][i].to] || G[v][i].cap <= 0) continue;
		ret = dfs(G[v][i].to, min(f, G[v][i].cap));
		if(ret > 0){
			G[v][i].cap -= ret;
			G[G[v][i].to][G[v][i].rev].cap += ret;
			return ret;
		}
	}
	return 0;
}

void add_edge(int s, int t, llint cap)
{
	G[s].push_back(edge(t, cap, G[t].size()));
	G[t].push_back(edge(s, 0, G[s].size()-1));
}

llint calc(llint p[], llint a[])
{
	llint ret = 1;
	for(int i = 1; i <= n; i++){
		if(a[i]) continue;
		int v = i;
		do{
			a[v] = ret;
			v = p[v];
		}while(!a[v]);
		ret++;
	}
	return ret-1;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> p[i], p[i]++;
	for(int i = 1; i <= n; i++) cin >> q[i], q[i]++;
	
	llint P = calc(p, a), Q = calc(q, b);
	S = P+Q+1, T = P+Q+2;
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(p[i] == i && q[i] == i) ans++;
		else if(p[i] == i) add_edge(P+b[i], T, 1);
		else if(q[i] == i) add_edge(S, a[i], 1);
		else{
			add_edge(P+b[i], a[i], 1);
			if(p[i] == q[i]) add_edge(a[i], P+b[i], 1);
		}
	}
		
	llint flow;
	while(1){
		bfs(S);
		if(level[T] >= inf) break;
		for(int i = 1; i <= T; i++) iter[i] = 0;
		while(1){
			flow = dfs(S, inf);
			if(flow <= 0) break;
			ans += flow;
		}
	}
	cout << n-ans << endl;
	
	return 0;
}