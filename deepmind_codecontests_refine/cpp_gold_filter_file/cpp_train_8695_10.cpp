#include <bits/stdc++.h>
using namespace std;
const int N = 2e3;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
int n, m;
long long z;
struct DSU {
  int p[N * N], sz[N * N], n, cmp;
  void init(int _n) {
    n = _n;
    for (int i = int(1); i <= int(n); ++i) p[i] = i, sz[i] = 1;
    cmp = n;
  }
  int f(int x) { return p[x] == x ? x : p[x] = f(p[x]); }
  void unite(int a, int b) {
    a = f(a), b = f(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    --cmp;
  }
} dsu;
int id(int i, int j) { return (i - 1) * m + j; }
bool inside(int i, int j) { return 1 <= i && i <= n && 1 <= j && j <= m; }
struct elem {
  int i, j, x;
  elem() {}
} q[N * N];
bool operator<(const elem &a, const elem &b) { return a.x < b.x; }
int a[N][N];
bool u[N][N], ans[N][N];
int need, res;
int di[] = {0, +1, 0, -1};
int dj[] = {+1, 0, -1, 0};
void dfs(int i, int j) {
  if (ans[i][j] || !need) return;
  ans[i][j] = 1;
  --need;
  for (int dir = int(0); dir <= int(3); ++dir) {
    int ni = i + di[dir], nj = j + dj[dir];
    if (inside(ni, nj) && a[ni][nj] >= res) dfs(ni, nj);
  }
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  int sz = 0;
  cin >> n >> m >> z;
  for (int i = int(1); i <= int(n); ++i) {
    for (int j = int(1); j <= int(m); ++j) {
      cin >> a[i][j];
      ++sz;
      q[sz].i = i, q[sz].j = j, q[sz].x = a[i][j];
    }
  }
  sort(q + 1, q + 1 + sz);
  dsu.init(n * m);
  for (int i = int(sz); i >= int(1); --i) {
    if (q[i].x == 0) break;
    int r = q[i].i, c = q[i].j;
    for (int dir = int(0); dir <= int(3); ++dir) {
      int nr = r + di[dir], nc = c + dj[dir];
      if (inside(nr, nc) && a[nr][nc] >= q[i].x)
        dsu.unite(id(r, c), id(nr, nc));
    }
    u[r][c] = 1;
    if (z % q[i].x == 0 && dsu.sz[dsu.f(id(r, c))] >= z / q[i].x) {
      res = q[i].x;
      need = z / q[i].x;
      dfs(r, c);
      cout << "YES\n";
      for (int j = int(1); j <= int(n); ++j) {
        for (int k = int(1); k <= int(m); ++k)
          cout << q[i].x * ans[j][k] << " ";
        cout << "\n";
      }
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
