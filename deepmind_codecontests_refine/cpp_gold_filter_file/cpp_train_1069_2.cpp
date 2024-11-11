#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
struct data {
  long long val, res, cnt;
  bool operator<(const data &a) const { return res < a.res; }
};
priority_queue<data> q;
long long n, k, g[100100];
long long ans;
long long calc(long long a, long long b) {
  long long x = a / (b + 1), y = a % (b + 1), res1, res2;
  res1 = y * (x + 1) * (x + 1) + (b + 1 - y) * x * x;
  x = a / b, y = a % b, res2 = y * (x + 1) * (x + 1) + (b - y) * x * x;
  return res2 - res1;
}
namespace D {
int fst[100100], nxt[100100 << 1], val[100100 << 1], to[100100 << 1], cnt;
int vis[100100], tot, q[100100], l, r, S, T, dis[100100], cur[100100];
void mem() {
  memset(nxt, 0, sizeof(nxt));
  cnt = 1, tot = 0;
}
void add(int u, int v, int w) {
  nxt[++cnt] = fst[u], fst[u] = cnt, to[cnt] = v, val[cnt] = w;
}
void ins(int u, int v, int w) {
  add(u, v, w);
  add(v, u, 0);
}
int bfs() {
  return 0;
  int x;
  vis[T] = ++tot, q[l = r = 1] = T, dis[T] = 0;
  while (l <= r) {
    x = q[l++], cur[x] = fst[x];
    for (int i = fst[x]; i; i = nxt[i])
      if (val[i ^ 1] && vis[to[i]] ^ tot)
        dis[to[i]] = dis[x] + 1, vis[to[i]] = tot, q[++r] = to[i];
  }
  return vis[S] == tot;
}
int dfs(int x, int a) {
  if (x == T || !a) return a;
  int flw = 0, f;
  for (int &i = cur[x]; i; i = nxt[i])
    if (val[i] && dis[to[i]] == dis[x] - 1 && (f = dfs(to[i], min(a, val[i]))))
      flw += f, a -= f, val[i] -= f, val[i ^ 1] += f;
  return flw;
}
int solve(int ss, int tt, int res = 0) {
  S = ss, T = tt;
  while (bfs()) res += dfs(S, 2139062143);
  return res;
}
}  // namespace D
int main() {
  n = read(), k = read() - n;
  data t;
  for (register int i = (1), iend = (n); i <= iend; ++i) {
    g[i] = read(), ans += g[i] * g[i];
    t.val = g[i];
    t.res = calc(t.val, t.cnt = 1);
    q.push(t);
  }
  D::mem();
  D::solve(2, 2);
  while (k--) {
    t = q.top();
    q.pop();
    ans -= t.res;
    t.cnt++;
    t.res = calc(t.val, t.cnt);
    q.push(t);
  }
  printf("%lld\n", ans);
}
