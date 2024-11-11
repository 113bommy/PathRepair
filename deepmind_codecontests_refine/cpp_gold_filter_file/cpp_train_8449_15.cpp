#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x) {
  x = 0;
  char c = getchar();
  bool f = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0) {
    putchar('-'), write(-x);
  } else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const int oo = 0x7fffffff, N = 405, M = N * N + 5;
int en = 1, h[N], n, m, s, t, cur[N], d[N], ux[N], uy[N], uxn, uyn;
pair<pair<int, int>, pair<int, int> > a[N];
struct edge {
  int n, v, w;
} e[M << 1];
void add(int first, int second, int z) {
  e[++en] = (edge){h[first], second, z};
  h[first] = en;
}
bool bfs(int s, int t) {
  for (int i = s; i <= t; i++) d[i] = 0, cur[i] = h[i];
  queue<int> q;
  q.push(s);
  d[s] = 1;
  while (!q.empty()) {
    int first = q.front();
    q.pop();
    for (int i = h[first]; i; i = e[i].n) {
      int second = e[i].v;
      if (!d[second] && e[i].w) {
        d[second] = d[first] + 1;
        if (second == t) return 1;
        q.push(second);
      }
    }
  }
  return 0;
}
int dfs(int first, int flow, int t) {
  if (first == t) return flow;
  int rest = flow;
  for (int &i = cur[first]; i && rest; i = e[i].n) {
    int second = e[i].v;
    if (d[second] == d[first] + 1 && e[i].w) {
      int tp = dfs(second, min(rest, e[i].w), t);
      rest -= tp;
      e[i].w -= tp;
      e[i ^ 1].w += tp;
    }
  }
  return flow - rest;
}
int dinic(int s, int t) {
  int res = 0;
  while (bfs(s, t)) res += dfs(s, oo, t);
  return res;
}
signed main() {
  read(n);
  read(m);
  for (int i = 1; i <= m; i++) {
    read(a[i].first.first);
    read(a[i].first.second);
    read(a[i].second.first);
    a[i].second.first++;
    read(a[i].second.second);
    a[i].second.second++;
    ux[++uxn] = a[i].first.first;
    uy[++uyn] = a[i].first.second;
    ux[++uxn] = a[i].second.first;
    uy[++uyn] = a[i].second.second;
  }
  ux[++uxn] = uy[++uyn] = n + 1;
  sort(ux + 1, ux + 1 + uxn);
  sort(uy + 1, uy + 1 + uyn);
  uxn = unique(ux + 1, ux + 1 + uxn) - ux - 1;
  uyn = unique(uy + 1, uy + 1 + uyn) - uy - 1;
  s = 0, t = uxn + uyn + 1;
  for (int i = 1; i <= m; i++) {
    a[i].first.first = lower_bound(ux + 1, ux + 1 + uxn, a[i].first.first) - ux;
    a[i].first.second =
        lower_bound(uy + 1, uy + 1 + uyn, a[i].first.second) - uy;
    a[i].second.first =
        lower_bound(ux + 1, ux + 1 + uxn, a[i].second.first) - ux;
    a[i].second.second =
        lower_bound(uy + 1, uy + 1 + uyn, a[i].second.second) - uy;
    for (int first = a[i].first.first; first < a[i].second.first; first++)
      for (int second = a[i].first.second; second < a[i].second.second;
           second++)
        add(first, second + uxn, oo), add(second + uxn, first, 0);
  }
  for (int i = 1; i < uxn; i++) add(s, i, ux[i + 1] - ux[i]), add(i, s, 0);
  for (int i = 1; i < uyn; i++)
    add(i + uxn, t, uy[i + 1] - uy[i]), add(t, i + uxn, 0);
  write(dinic(s, t));
}
