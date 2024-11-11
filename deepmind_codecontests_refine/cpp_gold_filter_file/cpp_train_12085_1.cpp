#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1<<28;

struct Edge {
    int to, cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};
int N;
vector< vector<Edge> > G;
void calcDist(int v, vector<int>& D) {
    D.clear(); D.resize(N, INF);
    D[v] = 0;
    queue<int> Q;
    Q.push(v);
    while (!Q.empty()) {
        int c = Q.front(); Q.pop();
        for (int i = 0; i < G[c].size(); i++) {
            Edge& e = G[c][i];
            if (D[e.to] > D[c] + e.cost) {
                D[e.to] = D[c] + e.cost;
                Q.push(e.to);
            }
        }
    }
}
// vの最遠点のひとつを返す
int farthest(int v) {
    static vector<int> D; calcDist(v, D);
    int ret = -1, dist = -1;
    for (int i = 0; i < N; i++) {
        if (dist < D[i]) {
            ret = i;
            dist = D[i];
        }
    }
    return ret;
}
void calcHeight(vector<int>& H) {
    int x = farthest(0);
    int y = farthest(x);
    vector<int> DX; calcDist(x, DX);
    vector<int> DY; calcDist(y, DY);
    H.clear(); H.resize(N);
    for (int i = 0; i < N; i++) H[i] = max(DX[i], DY[i]);
}
int main() {
    cin >> N;
    G.clear(); G.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int s, t, w; cin >> s >> t >> w;
        G[s].push_back(Edge(t, w));
        G[t].push_back(Edge(s, w));
    }
    vector<int> H;
    calcHeight(H);
    for (int i = 0; i < N; i++) cout << H[i] << endl;
    return 0;
}