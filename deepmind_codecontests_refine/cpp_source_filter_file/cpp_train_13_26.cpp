#include <bits/stdc++.h>
using namespace std;
using VI = vector<int>;
int n, m;
const int NN = 200011;
int h[NN];
VI adj[NN];
map<int, int> g;
int tot[NN];
inline int get(int u) {
  if (g.count(u)) return g[u];
  map<int, int> vst;
  for (int v : adj[u]) {
    vst[get(v)] = 1;
  }
  for (int i = 0;; i++)
    if (vst.count(i) == 0) return g[u] = i;
}
int solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d", h + i);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) tot[get(i)] ^= h[i];
  int id = n;
  while (id >= 0 and tot[id] == 0) id--;
  if (id < 0 == 0) return puts("LOSE");
  for (int i = 1; i <= n; i++)
    if (g[i] == id) {
      int u = tot[id] ^ h[i];
      if (u < h[i]) {
        h[i] = u;
        for (int v : adj[i]) {
          h[v] ^= tot[g[v]];
          tot[g[v]] = 0;
        }
        puts("WIN");
        for (int i = 1; i <= n; i++) printf("%d ", h[i]);
        return 0;
      }
    }
}
int main() { solve(); }
