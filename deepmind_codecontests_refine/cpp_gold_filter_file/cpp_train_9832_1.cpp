#include <bits/stdc++.h>
using namespace std;
const int N = 1.1e5;
int n, m, nq;
int f[N];
int fn(int x) { return f[x] ? (f[x] = fn(f[x])) : x; }
int64_t ans;
struct E {
  int x, y, z;
  bool operator<(const E& o) const { return z < o.z; }
} e[N * 2];
vector<pair<int, int>> a[N];
int d[N], up[N][17], upm[N][17];
void dfs(int v, int f) {
  d[v] = d[f] + 1;
  for (int i = 1; i < 17; ++i) {
    up[v][i] = up[up[v][i - 1]][i - 1];
    upm[v][i] = max(upm[v][i - 1], upm[up[v][i - 1]][i - 1]);
  }
  for (auto& i : a[v])
    if (i.first != f) {
      up[i.first][0] = v;
      upm[i.first][0] = i.second;
      dfs(i.first, v);
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].z);
  sort(e, e + m);
  int nc = n;
  for (int i = 0; i < m; ++i) {
    int x = fn(e[i].x), y = fn(e[i].y);
    if (x != y) {
      ans += e[i].z;
      f[x] = y;
      --nc;
      a[e[i].x].emplace_back(e[i].y, e[i].z);
      a[e[i].y].emplace_back(e[i].x, e[i].z);
    }
  }
  if (nc == 1) dfs(1, 0);
  scanf("%d", &nq);
  while (nq--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (nc > 2)
      puts("-1");
    else if (nc == 2 && fn(x) == fn(y))
      puts("-1");
    else if (nc == 2)
      printf("%" PRId64 "\n", ans);
    else if (nc == 1) {
      int mx = 0;
      if (d[x] > d[y]) swap(x, y);
      int dd = d[y] - d[x];
      for (int i = 0; i < 17; ++i)
        if (dd >> i & 1) {
          mx = max(mx, upm[y][i]);
          y = up[y][i];
        }
      for (int i = 16; i >= 0; --i) {
        if (up[x][i] != up[y][i]) {
          mx = max(mx, upm[x][i]);
          mx = max(mx, upm[y][i]);
          x = up[x][i];
          y = up[y][i];
        }
      }
      if (x != y) {
        mx = max(mx, upm[x][0]);
        mx = max(mx, upm[y][0]);
        x = up[x][0];
        y = up[y][0];
      }
      printf("%" PRId64 "\n", ans - mx);
    }
  }
}
