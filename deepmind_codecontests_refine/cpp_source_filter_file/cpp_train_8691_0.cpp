#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010, MOD = 999119999;
struct edge {
  int u, v, w;
  edge() {}
  edge(int x, int y, int z) : u(x), v(y), w(z) {}
};
edge E[MAXN];
list<pair<int, int> > adj1[MAXN], adj2[MAXN];
long long Ds[MAXN], Dt[MAXN];
int Cs[MAXN], Ct[MAXN], N, M, s, t;
void dijkstra(int src, long long D[], int C[], list<pair<int, int> > adj[]) {
  set<pair<long long, int> > S;
  for (int i = 1; i <= N; i++) D[i] = 1000000000000;
  S.insert(pair<long long, int>(0, src));
  D[src] = 0, C[src] = 1;
  while (!S.empty()) {
    int u = S.begin()->second, d = S.begin()->first;
    S.erase(S.begin());
    for (list<pair<int, int> >::iterator it = adj[u].begin();
         it != adj[u].end(); it++) {
      int v = it->first, w = it->second;
      if (D[v] > D[u] + w) {
        S.erase(pair<int, int>(D[v], v));
        D[v] = D[u] + w, C[v] = C[u];
        S.insert(pair<int, int>(D[v], v));
      } else if (D[v] == D[u] + w)
        C[v] = (C[v] + C[u]) % MOD;
    }
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> N >> M >> s >> t;
  for (int u, v, w, i = 1; i <= M; ++i) {
    cin >> u >> v >> w;
    E[i] = edge(u, v, w);
    adj1[u].push_back(pair<int, int>(v, w));
    adj2[v].push_back(pair<int, int>(u, w));
  }
  dijkstra(s, Ds, Cs, adj1);
  dijkstra(t, Dt, Ct, adj2);
  for (int i = 1; i <= M; ++i) {
    int u = E[i].u, v = E[i].v, w = E[i].w;
    if (Ds[u] + Dt[v] + w == Ds[t] && (1LL * Cs[u] * Ct[v]) % MOD == Cs[t])
      cout << "YES\n";
    else if (Ds[u] + Dt[v] + 1 < Ds[t])
      cout << "CAN " << Ds[u] + Dt[v] + w + 1 - Ds[t] << "\n";
    else
      cout << "NO\n";
  }
  return 0;
}
