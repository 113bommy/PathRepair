#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0, f = 1;
  register char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
  return x * f;
}
namespace Graph {
int head[200005], cnt;
struct edge {
  int v, next;
} e[200005 << 1];
inline void add(int u, int v) { e[++cnt] = (edge){v, head[u]}, head[u] = cnt; }
}  // namespace Graph
int a[200005], n, m, vis[200005], last[200005], b[200005], f[200005],
    val[200005], dp[200005][2];
inline void solve() {
  n = read(), m = read();
  val[0] = val[n + 1] = 1023456789;
  int cnt = 1;
  for (register int i = (1); i <= (n); ++i)
    a[i] = read(), f[a[i]] = i, val[i] = 0;
  for (register int i = (1); i <= (m); ++i) b[i] = read(), val[f[b[i]]] = i;
  for (register int i = (1); i <= (m); ++i) {
    if (!val[i]) continue;
    if (val[i] > val[i - 1] && val[i] > val[i + 1]) cnt = cnt * 2 % 998244353;
    if (val[i] < val[i - 1] && val[i] < val[i + 1]) cnt = 0;
  }
  printf("%d\n", cnt);
}
signed main() {
  int T = read();
  while (T--) solve();
  return 0;
}
