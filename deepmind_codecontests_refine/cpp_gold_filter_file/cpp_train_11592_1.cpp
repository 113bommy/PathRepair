#include <bits/stdc++.h>
using namespace std;
const int N = 6;
const int M = 10010;
const int K = 510;
const int LIT = 2500;
const long long INF = 1LL << 60;
int n, m[N][N], tot;
vector<int> v, vis;
int row[N], col[N], dia1, dia2;
void init() {
  memset(m, 0, sizeof(m));
  memset(row, 0, sizeof(row));
  memset(col, 0, sizeof(col));
  dia1 = dia2 = 0;
  tot = n * n;
  v = vector<int>(n * n);
  vis = vector<int>(n * n);
  for (int i = 0; i < tot; i++) cin >> v[i];
  sort(v.begin(), v.end());
}
void insert(int x, int y, int p, int ord) {
  m[x][y] = v[p];
  vis[p] = (ord > 0) ? 1 : 0;
  row[x] += v[p] * ord;
  col[y] += v[p] * ord;
  if (x == y) dia1 += v[p] * ord;
  if (x + y == n + 1) dia2 += v[p] * ord;
}
bool dfs1(int x, int y) {
  if (x > n) {
    int sum = dia1;
    for (int i = 1; i <= n; i++)
      if (sum != row[i]) return 0;
    for (int i = 1; i <= n; i++)
      if (sum != col[i]) return 0;
    if (dia1 != dia2) return 0;
    printf("%d\n", sum);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) printf("%d ", m[i][j]);
      printf("\n");
    }
    return 1;
  }
  int xx = x, yy = y + 1;
  if (yy > n) xx++, yy = 1;
  for (int i = 0; i < tot; i++) {
    if (vis[i]) continue;
    insert(x, y, i, 1);
    if (dfs1(xx, yy)) return 1;
    insert(x, y, i, -1);
  }
  return 0;
}
void solve() {
  if (n <= 3) dfs1(1, 1);
}
int main() {
  while (cin >> n) {
    init();
    solve();
  }
}
