#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
const int MAXN = 100010;
vector<int> G[MAXN];
int indeg[MAXN], outdeg[MAXN];
int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n = read(), m = read();
  for (int _ = (1); _ <= (m); _ += (1)) {
    int u = read(), v = read();
    if (u < v) swap(u, v);
    G[u].push_back(v);
    outdeg[u]++;
    indeg[v]++;
  }
  long long res = 0;
  for (int i = (1); i <= (n); i += (1)) res += indeg[i] * outdeg[i];
  printf("%lld\n", res);
  int q = read();
  for (int _ = (1); _ <= (q); _ += (1)) {
    int u = read();
    res -= indeg[u] * outdeg[u];
    for (auto v : G[u]) {
      res -= indeg[v] * outdeg[v];
      indeg[v]--;
      outdeg[v]++;
      G[v].push_back(u);
      res += indeg[v] * outdeg[v];
    }
    indeg[u] += outdeg[u];
    outdeg[u] = 0;
    G[u].clear();
    printf("%lld\n", res);
  }
  return 0;
}
