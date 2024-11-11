#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int n, m, q, L[maxn][maxn], R[maxn][maxn], U[maxn][maxn], D[maxn][maxn],
    mat[maxn][maxn];
void upr(int r) {
  L[r][0] = mat[r][0];
  for (int i = 1; i < n; i++) L[r][i] = (L[r][i - 1] + 1) * mat[r][i];
  R[r][m - 1] = mat[r][m - 1];
  for (int i = m - 2; i >= 0; i--) R[r][i] = (R[r][i + 1] + 1) * mat[r][i];
}
void upc(int c) {
  U[0][c] = mat[0][c];
  for (int i = 1; i < n; i++) U[i][c] = (U[i - 1][c] + 1) * mat[i][c];
  D[n - 1][c] = mat[n - 1][c];
  for (int i = n - 2; i >= 0; i--) D[i][c] = (D[i + 1][c] + 1) * mat[i][c];
}
void change(int x, int y) {
  mat[x][y] = mat[x][y] xor 1;
  upc(y), upr(x);
}
void init() {
  for (int i = 0; i < n; i++) upr(i);
  for (int i = 0; i < m; i++) upc(i);
}
int ret_find(int x, int y) {
  int l = L[x][y], r = R[x][y], h = 1, res = 0;
  while (l > 0 && r > 0) {
    res = max(res, (l + r - 1) * h);
    if (h > x) break;
    l = min(L[x - h][y], l), r = min(R[x - h][y], r);
    h++;
  }
  l = L[x][y], r = R[x][y], h = 1;
  while (l > 0 && r > 0) {
    res = max(res, (l + r - 1) * h);
    if (x + h >= n) break;
    l = min(l, L[x + h][y]), r = min(r, R[x + h][y]);
    h++;
  }
  int u = U[x][y], d = D[x][y];
  h = 1;
  while (u > 0 && d > 0) {
    res = max(res, (u + d - 1) * h);
    if (h > y) break;
    u = min(u, U[x][y - h]), d = min(d, D[x][y - h]);
    h++;
  }
  u = U[x][y], d = D[x][y], h = 1;
  while (u > 0 && d > 0) {
    res = max(res, (u + d - 1) * h);
    if (h + y >= m) break;
    u = min(u, U[x][y + h]), d = min(d, D[x][y + h]);
    h++;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> mat[i][j];
  init();
  while (q--) {
    int bo;
    pair<int, int> v;
    cin >> bo >> v.first >> v.second;
    v.first--, v.second--;
    if (bo == 1) change(v.first, v.second);
    if (bo == 2) cout << ret_find(v.first, v.second) << endl;
  }
}
