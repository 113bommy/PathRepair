#include <bits/stdc++.h>
const int oo = 2139063143;
const int N = 1010000;
const int P = 1000000007;
using namespace std;
inline void sc(int &x) {
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
inline void print(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
inline void pr(int x) { print(x), putchar('\n'); }
struct EDGE {
  int v, w, c, nx;
} lb[N << 1];
int tot = 1, top[N];
int deg[N];
void add(int u, int v, int l, int r, int c) {
  int w = r - l;
  if (w) {
    lb[++tot] = (EDGE){v, w, c, top[u]}, top[u] = tot;
    lb[++tot] = (EDGE){u, 0, -c, top[v]}, top[v] = tot;
  }
  deg[v] += l, deg[u] -= l;
}
int dis[N], flow[N], pre[N], las[N];
queue<int> q;
bool in[N];
bool spfa(int s, int t) {
  for (int i = 1; i <= t; i++)
    dis[i] = flow[i] = 1e9, pre[i] = las[i] = 0, in[i] = 0;
  dis[s] = 0;
  q.push(s), in[s] = 1;
  while (q.size()) {
    int u = q.front();
    q.pop(), in[u] = 0;
    for (int kb = top[u]; kb; kb = lb[kb].nx) {
      int v = lb[kb].v, w = lb[kb].w, c = lb[kb].c;
      if (w && dis[v] > dis[u] + c) {
        dis[v] = dis[u] + c;
        flow[v] = min(flow[u], w);
        pre[v] = u, las[v] = kb;
        if (!in[v]) q.push(v), in[v] = 1;
      }
    }
  }
  return pre[t];
}
int maflow, micost;
void mcmf(int s, int t) {
  while (spfa(s, t)) {
    int u = t, fl = flow[t], d = dis[t];
    maflow += fl, micost += d * fl;
    while (u != s) {
      lb[las[u]].w -= fl, lb[las[u] ^ 1].w += fl;
      u = pre[u];
    }
  }
}
int main() {
  int n, m;
  sc(n), sc(m);
  for (int i = 1; i <= m; i++) {
    int u, v, c, f;
    sc(u), sc(v), sc(c), sc(f);
    add(u, v, f, f, 0);
    if (f <= c) {
      add(u, v, 0, c - f, 1);
      add(u, v, 0, 1e9, 2);
      add(v, u, 0, f, 1);
    } else {
      micost += f - c;
      add(u, v, 0, 1e9, 2);
      add(v, u, 0, f - c, 0);
      add(v, u, 0, c, 1);
    }
  }
  add(n, 1, 0, 1e9, 0);
  int s = n + 1, t = s + 1;
  for (int i = 1; i <= n; i++) {
    if (deg[i] > 0) add(s, i, 0, deg[i], 0);
    if (deg[i] < 0) add(i, t, 0, -deg[i], 0);
  }
  mcmf(s, t);
  pr(micost);
  return 0;
}
