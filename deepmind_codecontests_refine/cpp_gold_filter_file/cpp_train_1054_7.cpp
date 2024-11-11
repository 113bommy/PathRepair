#include <bits/stdc++.h>
const int N = 5e5 + 10, Nt = 1 << 20;
const long long inf = 1e18;
int ri() {
  char c = getchar();
  int x = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c;
  return x * f;
}
int l[N], r[N], pr[N], nx[N], w[N], m, n, Q;
long long T[Nt], ans[N], D[N];
struct Data {
  int l, r, id;
};
std::vector<Data> q[N];
void Dfs1(int u) {
  l[u] = r[u] = u;
  for (int i = pr[u]; i; i = nx[i]) {
    D[i] = D[u] + w[i];
    Dfs1(i);
    l[u] = std::min(l[u], l[i]);
    r[u] = std::max(r[u], r[i]);
  }
  if (!pr[u])
    T[u + m] = D[u];
  else
    T[u + m] = inf;
}
void Up(int s) {
  long long A = std::min(T[s], T[s ^ 1]);
  T[s] -= A;
  T[s ^ 1] -= A;
  T[s >> 1] += A;
}
void Add(int s, int t, int x) {
  if (s > t) return;
  s += m, t += m;
  if (s == t) {
    for (T[s] += x; s > 1; s >>= 1) Up(s);
    return;
  }
  for (T[s] += x, T[t] += x; s ^ t ^ 1; s >>= 1, t >>= 1) {
    if (~s & 1) T[s ^ 1] += x;
    if (t & 1) T[t ^ 1] += x;
    Up(s);
    Up(t);
  }
  for (; s > 1; s >>= 1) Up(s);
}
long long Query(int s, int t) {
  long long l = 0, r = 0;
  if (s == t) {
    for (s += m; s; s >>= 1) l += T[s];
    return l;
  }
  for (s += m, t += m; s ^ t ^ 1; s >>= 1, t >>= 1) {
    l += T[s];
    r += T[t];
    if (~s & 1) l = std::min(l, T[s ^ 1]);
    if (t & 1) r = std::min(r, T[t ^ 1]);
  }
  l = std::min(l + T[s], r + T[t]);
  for (; s >>= 1;) l += T[s];
  return l;
}
void Dfs2(int u) {
  for (Data x : q[u]) ans[x.id] = Query(x.l, x.r);
  for (int i = pr[u]; i; i = nx[i]) {
    Add(l[i], r[i], -w[i]);
    Add(1, l[i] - 1, w[i]);
    Add(r[i] + 1, n, w[i]);
    Dfs2(i);
    Add(l[i], r[i], w[i]);
    Add(1, l[i] - 1, -w[i]);
    Add(r[i] + 1, n, -w[i]);
  }
}
int main() {
  n = ri();
  Q = ri();
  for (m = 1; m <= n + 1; m <<= 1)
    ;
  for (int i = 2, u; i <= n; ++i)
    u = ri(), nx[i] = pr[u], pr[u] = i, w[i] = ri();
  Dfs1(1);
  for (int i = m - 1; i; --i)
    T[i] = std::min(T[i << 1], T[i << 1 | 1]), T[i << 1] -= T[i],
    T[i << 1 | 1] -= T[i];
  for (int i = 1; i <= Q; ++i) {
    int v = ri(), l = ri(), r = ri();
    q[v].push_back((Data){l, r, i});
  }
  Dfs2(1);
  for (int i = 1; i <= Q; ++i) printf("%lld\n", ans[i]);
  return 0;
}
