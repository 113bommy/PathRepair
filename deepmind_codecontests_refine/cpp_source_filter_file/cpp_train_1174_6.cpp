#include <bits/stdc++.h>
using namespace std;
const int maxn = 444444, mod = 998244353;
inline long long read() {
  char ch = getchar();
  long long x = 0, f = 0;
  while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
inline int qpow(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) ans = 1ll * ans * a % mod;
  return ans;
}
int n, el, head[maxn], to[maxn], nxt[maxn], a[maxn], rt, len, col;
inline void add(int u, int v) {
  to[++el] = v;
  nxt[el] = head[u];
  head[u] = el;
}
void dfs(int u, int f, int c, int d) {
  if (d >= len) len = d, rt = u, col = c;
  for (int i = head[u]; i; i = nxt[i]) {
    int v = to[i];
    if (v == f) continue;
    if (!c)
      dfs(v, u, a[v], d);
    else {
      int t = a[v] ? a[v] : c;
      dfs(v, u, t, d + (t != c));
    }
  }
}
void clear() {
  rt = len = col = 0;
  for (int i = (1); i <= (el); i++) to[i] = nxt[i] = 0;
  for (int i = (1); i <= (n); i++) head[i] = a[i] = 0;
  el = 0;
}
void solve() {
  n = read();
  for (int i = (1); i <= (n); i++) a[i] = read();
  for (int i = (1); i <= (n - 1); i++) {
    int u = read(), v = read();
    add(u, v);
    add(v, u);
  }
  dfs(1, 0, a[1], 1);
  len = 0;
  dfs(rt, 0, col, 1);
  printf("%d\n", len / 2 + 1);
  clear();
}
int main() {
  int T = read();
  while (T--) solve();
}
