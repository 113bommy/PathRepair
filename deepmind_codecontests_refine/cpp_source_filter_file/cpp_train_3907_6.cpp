#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5 + 10;
const int MaxL = 18;
const int INF = 1e9;
const int MOD = 1e9 + 7;
int up[MaxN][MaxL], ds[MaxN];
vector<int> graph[MaxN];
int n, m, sz[MaxN];
long long sum[MaxN], ups[MaxN];
void dfsLca(int v, int p) {
  up[v][0] = p;
  for (int i = 1; i < MaxL; ++i) {
    up[v][i] = up[up[v][i - 1]][i - 1];
  }
  sz[v] = 1;
  for (int i = 0; i < (int)graph[v].size(); ++i) {
    int to = graph[v][i];
    if (to == p) {
      continue;
    }
    ds[to] = ds[v] + 1;
    dfsLca(to, v);
    sz[v] += sz[to];
    sum[v] += sz[to] + sum[to];
  }
}
void dfsUp(int v, int p) {
  if (p != -1) {
    ups[v] = (sum[p] - (sum[v] + sz[v]) + ups[p]) + (n - sz[v]);
  }
  for (int i = 0; i < (int)graph[v].size(); ++i) {
    int to = graph[v][i];
    if (to == p) {
      continue;
    }
    dfsUp(to, v);
  }
}
int getLca(int x, int y) {
  if (ds[x] > ds[y]) {
    swap(x, y);
  }
  for (int i = MaxL - 1; i >= 0; --i) {
    if (ds[up[y][i]] >= ds[x]) {
      y = up[y][i];
    }
  }
  if (x == y) {
    return x;
  }
  for (int i = MaxL - 1; i >= 0; --i) {
    if (up[x][i] != up[y][i]) {
      x = up[x][i];
      y = up[y][i];
    }
  }
  return up[x][0];
}
int getKth(int x, int k) {
  for (int i = MaxL - 1; i >= 0; --i) {
    if (k & (1 << i)) {
      x = up[x][i];
    }
  }
  return x;
}
double solve(int x, int y) {
  int l = getLca(x, y);
  int len = ds[x] + ds[y] - 2 * ds[l];
  double ans = 0;
  if (x != l && y != l) {
    long long total = 1LL * sz[x] * sz[y];
    long long cnt =
        1LL * sz[x] * sum[y] + 1LL * sz[y] * sum[x] + 1LL * total * len + total;
    ans = 1.0 * cnt / total;
  } else {
    if (ds[x] > ds[y]) {
      swap(x, y);
    }
    int xy = getKth(y, len - 1);
    long long total = 1LL * (n - sz[xy]) * sz[y];
    long long cnt = 1LL * (n - sz[xy]) * sum[y] +
                    1LL * (ups[xy] - (n - sz[xy])) * sz[y] + 1LL * total * len +
                    total;
    ans = 1.0 * cnt / total;
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  dfsLca(0, -1);
  dfsUp(0, -1);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    printf("%.9lf\n", solve(x, y));
  }
  return 0;
}
