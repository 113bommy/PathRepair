#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, eid, cnt, p[N], h[N], d[N], vis[N], sg[N], sum[N], b[N];
struct edge {
  int V, nxt;
} e[N << 1];
inline void addedge(int u, int v) { e[++eid] = (edge){v, p[u]}, p[u] = eid; }
inline void tuopu() {
  queue<int> q;
  while (!q.empty()) q.pop();
  for (int i = (1); i <= (n); i++)
    if (d[i] == 0) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop(), b[++cnt] = u;
    for (int i = p[u], v = e[i].V; i; i = e[i].nxt, v = e[i].V)
      if (!--d[v]) q.push(v);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); i++) scanf("%d", &h[i]);
  for (int i = (1); i <= (m); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addedge(u, v), d[v]++;
  }
  tuopu();
  for (int i = (cnt); i >= (1); i--) {
    int u = b[i];
    for (int j = p[u], v = e[j].V; j; j = e[j].nxt, v = e[j].V) vis[sg[v]] = u;
    for (int j = (0); j <= (n); j++)
      if (vis[j] ^ u) {
        sum[sg[u] = j] ^= h[u];
        break;
      }
  }
  for (int i = (n - 1); i >= (0); i--)
    if (sum[i]) {
      puts("WIN");
      for (int u = (1); u <= (n); u++)
        if (sg[u] == i && (h[u] ^ sum[i]) < h[u]) {
          h[u] ^= sum[i];
          for (int j = p[u], v = e[j].V; j; j = e[j].nxt, v = e[j].V)
            h[v] ^= sum[sg[v]], sum[sg[v]] = 0;
          for (int j = (1); j <= (n); j++) printf("%d ", h[j]);
          return 0;
        }
    }
  puts("LOSE");
  return 0;
}
