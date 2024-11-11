#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int SIZE = 1e6 + 10;
int N;
vector<pair<int, int> > e[SIZE];
long long dp[SIZE][2], num[SIZE];
void dfs1(int x, int lt) {
  num[x] = 1;
  for (int i = 0; i < (((int)(e[x]).size())); ++i) {
    int y = e[x][i].first;
    if (y == lt) continue;
    dfs1(y, x);
    num[x] += num[y];
    dp[x][0] += dp[y][0] + num[y];
  }
}
void dfs2(int x, int lt, int v) {
  dp[x][1] = dp[x][0] + v;
  for (int i = 0; i < (((int)(e[x]).size())); ++i) {
    int y = e[x][i].first;
    if (y == lt) continue;
    dfs2(y, x, v + (dp[x][0] - dp[y][0] - num[y]) + (N - num[y]));
  }
}
void add(int x, int y, int v) {
  e[x].push_back(make_pair(y, v));
  e[y].push_back(make_pair(x, v));
}
int jump[20][SIZE], lv[SIZE];
void __init(int x, int lt) {
  jump[0][x] = lt;
  for (int i = 0; i < (((int)(e[x]).size())); ++i) {
    int y = e[x][i].first;
    if (y != lt) {
      lv[y] = lv[x] + 1;
      __init(y, x);
    }
  }
}
int adv(int x, int v) {
  for (int i = 0; (1 << i) <= v; i++) {
    if ((v >> i) & 1) x = jump[i][x];
  }
  return x;
}
int lca(int x, int y) {
  if (lv[x] > lv[y])
    x = adv(x, lv[x] - lv[y]);
  else
    y = adv(y, lv[y] - lv[x]);
  if (x == y) return x;
  for (int i = 19; i >= 0; i--)
    if (jump[i][x] != jump[i][y]) {
      x = jump[i][x];
      y = jump[i][y];
    }
  return jump[0][x];
}
void build(int root) {
  __init(root, root);
  for (int i = (1); i < (20); ++i) {
    for (int x = (1); x < (N + 1); ++x)
      jump[i][x] = jump[i - 1][jump[i - 1][x]];
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  N = n;
  for (int i = (1); i < (n); ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y, 1);
  }
  build(1);
  dfs1(1, 1);
  dfs2(1, 1, 0);
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (lv[x] > lv[y]) swap(x, y);
    int z = lca(x, y);
    if (z != x) {
      printf("%.12f\n", lv[x] + lv[y] - lv[z] * 2 + (dp[x][0] * 1. / num[x]) +
                            dp[y][0] * 1. / num[y] + 1);
    } else {
      int u = adv(y, lv[y] - lv[x] - 1);
      printf("%.12f\n", lv[y] - lv[x] + (dp[y][0] * 1. / num[y]) +
                            (dp[x][1] - dp[u][0] - num[u]) * 1. / (N - num[u]) +
                            1);
    }
  }
  return 0;
}
