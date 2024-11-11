#include <bits/stdc++.h>
using namespace std;
int read() {
  int nm = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) nm = nm * 10 + c - '0';
  return nm * f;
}
using namespace std;
const int N = 13440, INF = 1e9 + 7;
const long long oo = 1e18;
int n, k, a[80], c[80], p[N], rem, m;
long long cost[N];
struct edge {
  int u, v, c, w;
} e[N];
void addEdge(int u, int v, int c, int w) {
  e[rem].u = u;
  e[rem].v = v;
  e[rem].c = c;
  e[rem++].w = w;
  e[rem].u = v;
  e[rem].v = u;
  e[rem].c = 0;
  e[rem++].w = -w;
}
bool getPath() {
  for (int i = 1; i <= 2 * n + 1; i++) cost[i] = oo, p[i] = -1;
  bool did = 1;
  for (int i = 0; i < 2 * n + 1 && did; i++) {
    did = 0;
    for (int j = 0; j < rem; j++)
      if (e[j].c && p[e[j].u] != -1 && cost[e[j].v] > cost[e[j].u] + e[j].w)
        cost[e[j].v] = cost[e[j].u] + e[j].w, p[e[j].v] = j, did = 1;
  }
  return p[2 * n + 1] != -1;
}
int lol;
long long CostFlow() {
  long long ret = 0;
  int flow = 0;
  while (flow < k && getPath()) {
    int mn = 1e9;
    for (int cur = 2 * n + 1; cur; cur = e[p[cur]].u) mn = min(mn, e[p[cur]].c);
    for (int cur = 2 * n + 1; cur; cur = e[p[cur]].u)
      e[p[cur]].c -= mn, e[p[cur] ^ 1].c += mn;
    ret += cost[2 * n + 1];
    flow += mn;
  }
  return ret + 1ll * INF * n;
}
int main() {
  n = read(), k = read(), m = n;
  for (int i = 0; i < m; i++) c[i] = read();
  for (int i = 0; i < n; i++) a[i] = read();
  for (int i = 0; i < n; i++) {
    addEdge(0, i + 1, 1, c[a[i] - 1]);
    addEdge(i + 1, n + i + 1, 1, -INF);
    addEdge(n + i + 1, 2 * n + 1, 1, 0);
    for (int j = i + 1; j < n; j++)
      addEdge(n + i + 1, j + 1, 1, a[j] == a[i] ? 0 : c[a[j] - 1]);
  }
  addEdge(0, 2 * n + 1, k, 0);
  printf("%lld\n", CostFlow());
  return 0;
}
