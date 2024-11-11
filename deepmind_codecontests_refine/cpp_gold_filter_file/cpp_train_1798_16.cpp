#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, w = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * w;
}
inline long long min(long long x, long long y) { return x < y ? x : y; }
inline long long max(long long x, long long y) { return x > y ? x : y; }
struct node {
  long long to, nxt;
} edge[200005 << 1];
long long n, tot;
long long w[200005], h[200005], head[200005], f[200005][2];
vector<long long> tmp[200005];
inline void add(long long u, long long v) {
  edge[++tot].nxt = head[u];
  edge[tot].to = v;
  head[u] = tot;
}
inline void addedge(long long u, long long v) { add(u, v), add(v, u); }
void dfs(long long u, long long fath) {
  long long res = 0, otd = 0, ind = 0;
  for (long long i = head[u]; i; i = edge[i].nxt) {
    long long v = edge[i].to;
    if (v == fath) continue;
    dfs(v, u);
    if (h[v] == h[u])
      tmp[u].push_back(f[v][1] - f[v][0]), res += f[v][0], otd++;
    else if (h[v] > h[u])
      ind++, res += f[v][1];
    else
      otd++, res += f[v][0];
  }
  sort(tmp[u].begin(), tmp[u].end());
  for (long long i = 0; i <= tmp[u].size(); i++) {
    f[u][0] = min(f[u][0], res + max(otd, ind + (u != 1)) * w[u]);
    f[u][1] = min(f[u][1], res + max(otd + (u != 1), ind) * w[u]);
    otd--, ind++;
    if (i < tmp[u].size()) res += tmp[u][i];
  }
}
signed main(void) {
  n = read();
  memset(f, 0x3f, sizeof(f));
  for (long long i = 1; i <= n; i++) w[i] = read();
  for (long long i = 1; i <= n; i++) h[i] = read();
  for (long long i = 1; i < n; i++) {
    long long x = read(), y = read();
    addedge(x, y);
  }
  dfs(1, 1);
  printf("%lld\n", min(f[1][0], f[1][1]));
  return 0;
}
