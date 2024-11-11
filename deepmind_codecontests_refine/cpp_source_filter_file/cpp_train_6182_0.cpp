#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
int n, q, m;
vector<int> v[MAXN];
int lv[MAXN], tidx[MAXN];
void read() {
  int i, x, y;
  scanf("%d %d", &n, &q);
  for (i = 0; i < n - 1; ++i) {
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
    if (x == 1 || y == 1) m++;
  }
}
vector<int> g[MAXN];
void dfs(int i, int pos, int level, int root) {
  int j, sz = (int)v[i].size();
  g[pos].push_back(0);
  lv[i] = level;
  tidx[i] = pos;
  for (j = 0; j < sz; ++j) {
    if (v[i][j] != root && !lv[v[i][j]]) {
      dfs(v[i][j], pos, level + 1, root);
    }
  }
}
void update(int pos, int num, int idx) {
  for (pos; pos < (int)g[idx].size(); pos += pos & (-pos)) {
    g[idx][pos] += num;
  }
}
int ask(int pos, int idx) {
  int sum = 0;
  for (pos; pos > 0; pos -= pos & (-pos)) {
    sum += g[idx][pos];
  }
  return sum;
}
void solve() {
  int i, j, root = 0;
  int t, u, x, d;
  for (i = 0; i < m; ++i) {
    for (j = 0; j < 5; ++j) {
      g[i].push_back(0);
    }
    dfs(v[1][i], i, 1, 1);
  }
  for (i = 0; i < MAXN; ++i) {
    g[m].push_back(0);
  }
  for (i = 0; i < q; ++i) {
    scanf("%d", &t);
    if (t == 0) {
      scanf("%d %d %d", &u, &x, &d);
      if (u == 1) {
        root += x;
        update(u, x, m);
        update(d + 1, -x, m);
      } else {
        if (d >= lv[u]) {
          int last = d - lv[u];
          root += x;
          if (last > 0) {
            update(1, x, m);
            update(last + 1, -x, m);
          }
          update(last + 1, x, tidx[u]);
          update(lv[u] + d + 1, -x, tidx[u]);
        } else {
          update(lv[u] - d, x, tidx[u]);
          update(lv[u] + d, -x, tidx[u]);
        }
      }
    } else {
      scanf("%d", &u);
      if (u == 1) {
        printf("%d\n", root);
      } else {
        int cnt = ask(lv[u], tidx[u]) + ask(lv[u], m);
        printf("%d\n", cnt);
      }
    }
  }
}
int main() {
  read();
  solve();
  return 0;
}
