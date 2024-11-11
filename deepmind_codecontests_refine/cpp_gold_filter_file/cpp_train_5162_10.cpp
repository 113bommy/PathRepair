#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int sign = 1, sum = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') sign = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    sum = (sum << 1) + (sum << 3) + c - '0';
    c = getchar();
  }
  return sign * sum;
}
const int N = 2e5 + 50;
struct Edge {
  int nxt, to;
} edge[N << 1];
int head[N], tot = 0;
inline void add(int u, int v) {
  ++tot;
  edge[tot].to = v;
  edge[tot].nxt = head[u];
  head[u] = tot;
}
inline void addedge(int u, int v) { add(v, u), add(u, v); }
int n, k;
int size[N];
long long f[N][5];
inline void dfs1(int u, int fa) {
  size[u] = 1;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v != fa) {
      dfs1(v, u);
      size[u] += size[v];
      f[u][0] += f[v][k - 1] + size[v];
      for (int j = 1; j < k; ++j) f[u][j] += f[v][j - 1];
    }
  }
}
inline void dfs2(int u, int fa) {
  long long cnt[5] = {0};
  if (fa) {
    cnt[0] = f[fa][0] - f[u][k - 1] - size[u];
    for (int j = 1; j < k; ++j) cnt[j] = f[fa][j] - f[u][j - 1];
  }
  f[u][0] += cnt[k - 1] + n - size[u];
  for (int j = 1; j < k; ++j) f[u][j] += cnt[j - 1];
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v != fa) dfs2(v, u);
  }
}
int main() {
  n = read(), k = read();
  for (int i = 1; i < n; ++i) {
    int u = read(), v = read();
    addedge(u, v);
  }
  dfs1(1, 0);
  dfs2(1, 0);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) ans += f[i][0];
  printf("%lld\n", (ans >> 1));
}
