#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a; i<n; i++)
using namespace std;
typedef pair<int, int> pii;
typedef vector< vector<pii> > Graph;

struct Edge {
    int from, to, cost;
    Edge(int a, int b, int c) : from(a), to(b), cost(c) {};
};

int depth[100010];
void getDepth(Graph &G, int point) {
    for(size_t i=0; i<G[point].size(); i++) {
        int to = G[point][i].first;
        if(depth[to] != -1) continue;
        depth[to] = depth[point] + 1;
        getDepth(G, to);
    }
}

int main() {
    double p; cin >> p;
    int n; cin >> n;
    Graph G(n);
    vector<Edge> ve;
    rep(i,0,n-1) {
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        G[x].push_back(pii(y, c));
        G[y].push_back(pii(x, c));
        ve.push_back(Edge(x, y, c));
    }

    memset(depth, -1, sizeof(depth));
    depth[0] = 0;
    getDepth(G, 0);

    double E = 0.0;
    rep(i,0,ve.size()) {
        int x = depth[ ve[i].from ];
        int y = depth[ ve[i].to ];
        int d = max(x, y);
        E += ve[i].cost * pow(p, d);
    }

    double ans = 2 * E;
    rep(i,0,ve.size()) {
        int x = depth[ ve[i].from ];
        int y = depth[ ve[i].to ];
        int d = max(x, y);b
        ans += E * pow(p, d);
    }

    cout << fixed << setprecision(10) << ans << endl;
}