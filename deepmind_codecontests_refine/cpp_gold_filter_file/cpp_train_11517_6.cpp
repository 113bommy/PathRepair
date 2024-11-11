#include <bits/stdc++.h>
using namespace std;
namespace io {
const int L = (1 << 19) + 1;
char ibuf[L], *iS, *iT, c;
int f;
char gc() {
  if (iS == iT) {
    iT = (iS = ibuf) + fread(ibuf, 1, L, stdin);
    return iS == iT ? EOF : *iS++;
  }
  return *iS++;
}
template <class I>
void gi(I& x) {
  for (f = 1, c = gc(); c < '0' || c > '9'; c = gc())
    if (c == '-') f = -1;
  for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15);
  x *= f;
}
};  // namespace io
using io::gc;
using io::gi;
int n, m, a, b, d[200010], head[200010], to[400010], nxt[400010], tot,
    s[200010];
vector<int> u, v, w;
void add(int a, int b) {
  if (s[b]) {
    u.push_back(a);
    v.push_back(b);
    w.push_back(s[b]);
    s[b] = 0;
  } else
    s[b] = a;
}
void adli(int u, int v) {
  ++tot;
  nxt[tot] = head[u];
  head[u] = tot;
  to[tot] = v;
  ++tot;
  nxt[tot] = head[v];
  head[v] = tot;
  to[tot] = u;
}
void dfs(int u, int fa) {
  for (int i = head[u], v; i; i = nxt[i]) {
    v = to[i];
    if (!d[v]) {
      d[v] = d[u] + 1;
      dfs(v, u);
    }
    if (d[u] < d[v] || v == fa) continue;
    add(u, v);
  }
  if (fa)
    if (s[u])
      add(fa, u);
    else
      add(u, fa);
}
int main() {
  gi(n);
  gi(m);
  for (register int i = 1; i <= m; i++) gi(a), gi(b), adli(a, b);
  for (register int i = 1; i <= n; i++)
    if (!d[i]) {
      d[i] = 1;
      dfs(i, 0);
    }
  m = u.size();
  printf("%d\n", m);
  for (register int i = 0; i <= m - 1; i++)
    printf("%d %d %d\n", u[i], v[i], w[i]);
  return 0;
}
