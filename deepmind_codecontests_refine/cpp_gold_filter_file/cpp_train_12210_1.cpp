#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, x = 0;
  char ch;
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = -1;
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return f * x;
}
const int maxn = 1010;
struct edge {
  int next, to, w;
} e[maxn << 1];
int f[maxn][maxn], n, m, Q, x[maxn], y[maxn];
int head[maxn], cnt;
struct rec {
  int p, d;
  rec() { p = 0, d = 0; }
  rec(int a, int b) {
    p = a;
    d = b;
  }
};
priority_queue<rec> q;
bool operator<(const rec &x, const rec &y) { return x.d > y.d; }
inline void addedge(int u, int v, int w) {
  ++cnt;
  e[cnt].to = v;
  e[cnt].next = head[u];
  head[u] = cnt;
  e[cnt].w = w;
}
int d[maxn];
void dij(int s) {
  for (int i = 1; i <= n; ++i) d[i] = 1e9 + 10;
  d[s] = 0;
  q.push(rec(s, d[s]));
  while (!q.empty()) {
    rec now = q.top();
    q.pop();
    if (now.d != d[now.p]) continue;
    for (int i = head[now.p]; ~i; i = e[i].next) {
      int v = e[i].to;
      if (d[v] > d[now.p] + e[i].w) {
        d[v] = d[now.p] + e[i].w;
        q.push(rec(v, d[v]));
      }
    }
  }
  for (int i = 1; i <= n; ++i) f[s][i] = d[i];
}
int U[maxn], V[maxn];
int main() {
  memset(head, -1, sizeof head);
  cnt = -1;
  n = read(), m = read(), Q = read();
  int w;
  for (int i = 1; i <= m; ++i)
    U[i] = read(), V[i] = read(), w = read(), addedge(U[i], V[i], w),
    addedge(V[i], U[i], w);
  for (int i = 1; i <= n; ++i) dij(i);
  for (int i = 1; i <= Q; ++i) x[i] = read(), y[i] = read();
  int ans = 1e9 + 10;
  for (int i = 1; i <= m; ++i) {
    int uu = U[i], vv = V[i];
    int sum = 0;
    for (int j = 1; j <= Q; ++j)
      sum += min(f[x[j]][y[j]],
                 min(f[x[j]][uu] + f[vv][y[j]], f[x[j]][vv] + f[uu][y[j]]));
    ans = min(ans, sum);
  }
  printf("%d", ans);
  return 0;
}
