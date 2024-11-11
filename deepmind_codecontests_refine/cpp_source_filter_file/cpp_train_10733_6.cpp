#include <bits/stdc++.h>
using namespace std;
int read() {
  int X = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') X = X * 10 + c - '0', c = getchar();
  return X * w;
}
const int N = 1000 + 10;
int n, k1, k2, a[N], b[N], visa[N], visb[N];
vector<int> E[N];
int dep[N];
void dfs(int u, int f) {
  dep[u] = dep[f] + 1;
  for (int v : E[u])
    if (v != f) dfs(v, u);
}
int main() {
  int T = read();
  while (T--) {
    n = read();
    for (int i = 1; i <= n; ++i) E[i].clear(), visa[i] = visb[i] = 0;
    for (int i = 1; i < n; ++i) {
      int u = read(), v = read();
      E[u].emplace_back(v), E[v].emplace_back(u);
    }
    k1 = read();
    for (int i = 1; i <= k1; ++i) a[i] = read(), visa[i] = 1;
    k2 = read();
    for (int i = 1; i <= k2; ++i) b[i] = read(), visb[i] = 1;
    printf("B %d\n", b[1]), fflush(stdout);
    int u = read();
    if (visa[u]) {
      printf("C %d\n", u), fflush(stdout);
      continue;
    }
    dfs(u, 0);
    int p = a[1];
    for (int i = 2; i <= k1; ++i)
      if (dep[a[i]] < dep[p]) p = a[i];
    printf("A %d\n", p), fflush(stdout);
    u = read();
    if (visb[u])
      printf("C %d\n", p), fflush(stdout);
    else
      puts("C -1"), fflush(stdout);
  }
  return 0;
}
