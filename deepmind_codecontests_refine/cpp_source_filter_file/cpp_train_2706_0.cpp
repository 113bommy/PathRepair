#include <bits/stdc++.h>

using namespace std;

const bool debug = true;
#define dbg(...) if(debug) printf(__VA_ARGS__)
#define print(var) if (debug) cout << #var << " = " << var << endl

namespace {
    using ll = long long;

    int N, M, R, Q;
    vector<tuple<int, int, int>> rules;
    void input() {
        cin >> N >> M >> R >> Q;
        for (int i = 0; i < M; i++) {
            int a, b, c; cin >> a >> b >> c;
            rules.emplace_back(a, b, c);
        }
    }

    const ll INF = 1LL<<52;
    const int MAX_R = 10;
    struct Edge {
        int from, to; ll cost;
        Edge(int from, int to, ll cost) : from(from), to(to), cost(cost) {}
    };
    vector<vector<Edge>> RG;
    vector<ll> dist[MAX_R];
    void constructGraph() {
        RG.clear();
        RG.resize(N + 1 + R);
        for (auto& rule : rules) {
            int from, to; ll cost;
            tie(from, to, cost) = rule;
            RG[to].emplace_back(to, from, cost);
        }
        for (int n = 0; n <= N; n++) {
            RG[N + 1 + n % R].emplace_back(N + 1 + n % R, n, 0);
        }
        struct S {
            int v; ll cost;
            S(int v, ll cost) : v(v), cost(cost) {}
            bool operator<(const S& s) const { return cost > s.cost; }
        };
        auto dijkstra = [&](int src, vector<ll>& dist) {
            priority_queue<S> PQ;
            PQ.emplace(src, 0);
            dist[src] = 0;
            while (not PQ.empty()) {
                auto cur = PQ.top(); PQ.pop();
                for (auto& e : RG[cur.v]) {
                    int next = e.to;
                    if (dist[next] > cur.cost + e.cost) {
                        dist[next] = cur.cost + e.cost;
                        PQ.emplace(next, dist[next]);
                    }
                }
            }
        };
        for (int r = 0; r < R; r++) {
            dist[r].clear();
            dist[r].resize(RG.size(), INF);
            dijkstra(N + 1 + r, dist[r]);
        }
    }

    void solve() {
        constructGraph();
        ll ans = 0;
        for (int q = 0; q < Q; q++) {
            int x, y, z; cin >> x >> y >> z;
            int add = 0;
            for (int r = 0; r < R; r++) {
                ll cost = dist[r][x] + dist[r][y];
                add = max(add, z - cost);
            }
            ans += add;
        }
        cout << ans << endl;
    }
}

int main() {
    input(); solve();
    return 0;
}


