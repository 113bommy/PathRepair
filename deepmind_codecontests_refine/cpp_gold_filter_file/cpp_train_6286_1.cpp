#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 7;
const int M = 2e4 + 7;
inline int read() {
  int x = 0, f = 1;
  char c;
  while (!isdigit(c = getchar())) f -= (c == '-') * 2;
  while (isdigit(c)) x = x * 10 + f * (c - 48), c = getchar();
  return x;
}
struct edge {
  int u, v;
  edge(int u = 0, int v = 0) : u(u), v(v) {}
} e[M];
struct node {
  int r, id;
  node(int r = 0, int id = 0) : r(r), id(id) {}
  friend bool operator<(node a, node b) { return a.r < b.r; }
};
vector<node> vec[M];
int n, m, k, res, f[N], l[M], r[M], ans[M];
int get(int x) { return x == f[x] ? x : f[x] = get(f[x]); }
void merge(int x, int y) {
  x = get(x), y = get(y);
  if (x != y) f[x] = y, --res;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; ++i) e[i] = edge(read(), read());
  k = read();
  for (int i = 1; i <= k; ++i)
    l[i] = read(), r[i] = read(), vec[l[i]].push_back(node(r[i], i));
  for (int i = 1; i <= m; ++i) sort(vec[i].begin(), vec[i].end());
  for (int i = 1; i <= m; ++i) {
    if (vec[i].empty()) continue;
    res = n;
    for (int j = 1; j <= n; ++j) f[j] = j;
    for (int j = 1; j < i; ++j) merge(e[j].u, e[j].v);
    int det = m;
    while (!vec[i].empty()) {
      node u = vec[i].back();
      while (det > u.r) merge(e[det].u, e[det].v), --det;
      ans[u.id] = res;
      vec[i].pop_back();
    }
  }
  for (int i = 1; i <= k; ++i) printf("%d\n", ans[i]);
  return 0;
}
