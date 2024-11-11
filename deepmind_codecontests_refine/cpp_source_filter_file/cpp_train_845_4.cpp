#include <bits/stdc++.h>
const int oo = 2139063143;
const int N = 101000;
const int P = 1000000007;
using namespace std;
template <typename T>
inline void sc(T &x) {
  x = 0;
  static int p;
  p = 1;
  static char c;
  c = getchar();
  while (!isdigit(c)) {
    if (c == '-') p = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c - 48);
    c = getchar();
  }
  x *= p;
}
template <typename T>
inline void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
inline void pr(T x) {
  print(x), putchar('\n');
}
struct EDGE {
  int v, w, nx;
} lb[N * 20];
int tot = 1, top[N], cur[N], TOT, TOP[N];
void add(int u, int v, int w) {
  lb[++tot] = (EDGE){v, w, top[u]}, top[u] = tot;
  lb[++tot] = (EDGE){u, 0, top[v]}, top[v] = tot;
}
int s, t;
int dep[N];
bool bfs() {
  memcpy(cur, top, sizeof(int) * (t + 1));
  memset(dep, 0, sizeof(int) * (t + 1));
  queue<int> q;
  dep[s] = 1, q.push(s);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int kb = top[u]; kb; kb = lb[kb].nx) {
      int v = lb[kb].v, w = lb[kb].w;
      if (w && !dep[v]) dep[v] = dep[u] + 1, q.push(v);
    }
  }
  return dep[t];
}
int dinic(int u, int flow) {
  if (u == t) return flow;
  int rest = flow;
  for (int &kb = cur[u]; kb; kb = lb[kb].nx) {
    int v = lb[kb].v, w = lb[kb].w;
    if (w && dep[v] == dep[u] + 1) {
      int k = dinic(v, min(w, rest));
      if (!k) dep[v] = 0;
      rest -= k;
      lb[kb].w -= k, lb[kb ^ 1].w += k;
      if (!rest) break;
    }
  }
  return flow - rest;
}
int ans[N];
bool vis[N];
int p[N], c[N], k[N];
int main() {
  int n, m;
  sc(n), sc(m);
  for (int i = 1; i <= n; i++) sc(p[i]), ++p[i];
  for (int i = 1; i <= n; i++) sc(c[i]);
  int d;
  sc(d);
  for (int i = 1; i <= d; i++) sc(k[i]), vis[k[i]] = 1;
  s = m + m + m + 10, t = s + 1;
  for (int i = 1; i <= m; i++) add(s, i, 1);
  for (int i = 1; i <= n; i++)
    if (!vis[i])
      if (p[i] <= m) add(c[i], m + p[i], 1);
  for (int i = d; i >= 1; i--) {
    ans[i] = ans[i + 1] + 1;
    for (; ans[i] <= m + 1; ans[i]++) {
      memcpy(TOP, top, sizeof(int) * (t + 1)), TOT = tot;
      add(m + ans[i], t, 1);
      if (!(bfs() && dinic(s, oo))) {
        memcpy(top, TOP, sizeof(int) * (t + 1)), tot = TOT;
        --ans[i];
        break;
      }
    }
    if (p[i] <= m) add(c[k[i]], m + p[k[i]], 1);
  }
  for (int i = 1; i <= d; i++) pr(ans[i]);
  return 0;
}
