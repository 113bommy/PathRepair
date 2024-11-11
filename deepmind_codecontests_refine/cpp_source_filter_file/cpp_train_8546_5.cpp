#include <bits/stdc++.h>
using namespace std;
int n, m, p[510], ans, belong[510], to[510];
vector<int> c[510];
bool bj[510];
inline int getint() {
  int w = 0, q = 0;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 1, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? -w : w;
}
struct DINIC {
  int deep[510], dl[510], head, tail, N;
  bool bj[510];
  vector<int> a[510], val[510], ba[510];
  void link(int x, int y, int z) {
    a[x].push_back(y), val[x].push_back(z);
    a[y].push_back(x), val[y].push_back(0);
    ba[x].push_back(a[y].size() - 1);
    ba[y].push_back(a[x].size() - 1);
  }
  void bfs() {
    int x, w, v;
    head = 0, tail = 1, dl[1] = 0;
    memset(bj, 0, sizeof(bj));
    bj[0] = 1;
    deep[0] = 0;
    do {
      x = dl[++head], w = a[x].size();
      for (int i = 0; i < w; i++) {
        v = a[x][i];
        if (val[x][i] <= 0 || bj[v]) continue;
        deep[v] = deep[x] + 1, bj[v] = 1;
        dl[++tail] = v;
      }
    } while (head != tail);
  }
  int dfs(int x, int low) {
    int inc = 0, va;
    int w = a[x].size(), v;
    if (x == N) return low;
    for (int i = 0; i < w; i++) {
      v = a[x][i];
      if (deep[v] == deep[x] + 1 && val[x][i] &&
          (va = dfs(v, min(low, val[x][i])))) {
        val[x][i] -= va;
        val[v][ba[x][i]] += va;
        inc += va;
        return va;
      }
    }
    if (!inc) deep[x] = -1;
    return 0;
  }
  int maxflow() {
    int sum = 0;
    while (1) {
      bfs();
      if (!bj[N]) break;
      sum += dfs(0, 0x7fffffff);
    }
    return sum;
  }
} G;
void init() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int k = getint();
    for (int j = 1; j <= k; j++) {
      int x = getint();
      c[i].push_back(x);
    }
  }
  for (int i = 1; i <= n; i++) {
    p[i] = getint();
    p[i] *= -1;
    if (p[i] > 0) ans += p[i];
  }
}
bool find(int x) {
  int w = c[x].size();
  for (int i = 0; i < w; i++) {
    int v = c[x][i];
    if (bj[v]) continue;
    bj[v] = 1;
    if (!belong[v] || find(belong[v])) {
      belong[v] = x;
      return 1;
    }
  }
  return 0;
}
void make_g(int x) {
  if (p[x] >= 0)
    G.link(0, x, p[x]);
  else
    G.link(x, G.N, p[x] * -1);
  int w = c[x].size();
  for (int i = 0; i < w; i++) {
    int v = c[x][i];
    if (v == to[x]) continue;
    G.link(x, belong[v], 0x7fffffff);
  }
}
int main() {
  init();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) bj[j] = 0;
    find(i);
  }
  G.N = n + 1;
  for (int i = 1; i <= n; i++) to[belong[i]] = i;
  for (int i = 1; i <= n; i++) make_g(i);
  ans -= G.maxflow();
  cout << ans * -1;
  return 0;
}
