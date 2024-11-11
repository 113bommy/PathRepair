#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC target("avx")
using namespace std;
inline char gc() {
  static char buf[1 << 16], *p1 = buf, *p2 = buf;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, 1 << 16, stdin);
    if (p2 == p1) return EOF;
  }
  return *p1++;
}
template <class t>
inline t read(t &x) {
  char c = gc();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = gc();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const long long N = 6e4 + 5, M = 2e5 + 5;
long long en = 1, h[N], cur[N], d[N], n, m, ans;
struct edge {
  long long n, v, w;
} e[M << 1];
void add(long long x, long long y, long long z) {
  e[++en] = (edge){h[x], y, z};
  h[x] = en;
}
bool bfs(long long s, long long aim) {
  memset(d, 0, sizeof d);
  memcpy(cur, h, sizeof cur);
  queue<long long> q;
  q.push(s);
  d[s] = 1;
  while (!q.empty()) {
    long long x = q.front();
    q.pop();
    for (long long i = h[x]; i; i = e[i].n) {
      long long y = e[i].v;
      if (!d[y] && e[i].w) {
        d[y] = d[x] + 1;
        if (y == aim) return 1;
        q.push(y);
      }
    }
  }
  return 0;
}
long long dfs(long long x, long long flow, long long aim) {
  if (x == aim) return flow;
  long long rest = flow;
  for (long long &i = cur[x]; i && rest; i = e[i].n) {
    long long y = e[i].v;
    if (d[y] == d[x] + 1 && e[i].w) {
      long long tp = dfs(y, min(rest, e[i].w), aim);
      rest -= tp;
      e[i].w -= tp;
      e[i ^ 1].w += tp;
    }
  }
  return flow - rest;
}
long long dinic(long long s, long long t) {
  long long res = 0;
  while (bfs(s, t)) res += dfs(s, 1000000000000, t);
  return res;
}
void exadd(long long x, long long y, long long f) {
  add(x, y, f);
  add(y, x, 0);
}
signed main() {
  read(n);
  for (long long i = 1, m, x; i <= n; i++) {
    read(m);
    while (m--) exadd(i, read(x) + n, 1000000);
  }
  for (long long i = 1, x; i <= n; i++) {
    read(x);
    exadd(0, i, 1000000 - x);
    ans += 1000000 - x;
  }
  for (long long i = 1; i <= n; i++) exadd(i + n, n * 2 + 1, 1000000);
  write(min(dinic(0, n * 2 + 1) - ans, 0ll));
}
