#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> P;

int const MAX_N  = 10000;
int N, M;
P piles[MAX_N];

double distance(int x0, int y0, int x1, int y1) {
    return hypot(x1-x0, y1-y0);
}

// O(E*log(V))
struct Edge {
    Edge(int a, int b, double c) {
        u = a; v = b; cost = c;
    }
    int u, v;
    double cost;
};

bool comp(const Edge& e1, const Edge& e2) {
    return e1.cost < e2.cost;
}

struct UF{
    vector<int> par;
    UF(int m) : par(m){
        for(int i = 0; i < m; i++){
            par[i] = i;
        }
    }
    int find(int x){
        return x != par[x] ? par[x] = find(par[x]) : x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void unite(int x, int y){
        // y is above
        if(!same(x, y)) par[find(x)] = find(y);
    }
};

double kruskal(int V, vector<Edge>& es) {
    sort(es.begin(), es.end(), comp);
    UF uf(V);
    double res = 0;
    for(int i = es.size()-1; i >= 0; i--) {
        Edge e = es[i];
        if(!uf.same(e.u, e.v)) {
            uf.unite(e.u, e.v);
        } else {
            res += e.cost;
        }
    }
    return res;
}

vector<Edge> es;

int main() {
    cin >> N >> M;
    int x, y;
    for(int i = 0; i < N; i++) {
        cin >> x >> y;
        piles[i] = P(x, y);
    }
    int j, k;
    double s = 0;
    for(int i = 0; i < M; i++) {
        cin >> j >> k;
        j--; k--;
        P p1 = piles[j], p2 = piles[k];
        double d = distance(p1.first, p1.second, p2.first, p2.second);
        s += d;
        es.push_back(Edge(j, k, d));
    }
    printf("%.5f\n", kruskal(N, es));
    return 0;
}