#include <bits/stdc++.h>
using namespace std;
struct EDGE { int from, to, cost; };
bool operator < (const EDGE& a, const EDGE& b) {
    return a.cost < b.cost;
}
 
vector<EDGE> g;
int par[10000];
 
int find(int x)
{
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}
 
bool _union(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return false;
    par[x] = y;
    return true;
}
 
int main()
{
    int V, E;
    scanf("%d %d", &V, &E);
     
    for (int i = 0; i < V; i++) par[i] = i;
     
	for (int i = 0; i < n; i++) {
		int s, t, w;
		cin>>s>>t>>w;
		e.push_back(Edge{ s, t, w });
	}
     
    sort(g.begin(), g.end());
     
    int res = 0;
    for (int i = 0; i < g.size(); i++){
        EDGE &e = g[i];
        if (_union(e.from, e.to)) res += e.cost;
    }
     
    printf("%d\n", res);
     
    return 0;
}