#include <bits/stdc++.h>
using namespace std;
const int maxn = 100003;
const int maxk = 1003;
int mat[maxk][maxk];
int up[maxk][maxk], down[maxk][maxk], leftc[maxk][maxk], rightc[maxk][maxk];
int n, m, q;
int query(int xi, int yj) {
  int hmax = up[xi][yj];
  int ans = hmax, lft = yj, rght = yj;
  for (int i = hmax; i > 0; i--) {
    while (lft > 0 && up[xi][lft] >= i) lft--;
    while (rght <= m && up[xi][rght] >= i) rght++;
    ans = max(ans, (rght - lft - 1) * i);
  }
  int hmax2 = down[xi][yj];
  int ans2 = hmax2;
  lft = yj;
  rght = yj;
  for (int i = hmax2; i > 0; i--) {
    while (lft > 0 && down[xi][lft] >= i) lft--;
    while (rght <= m && down[xi][rght] >= i) rght++;
    ans = max(ans, (rght - lft - 1) * i);
  }
  int hmax3 = leftc[xi][yj];
  int ans3 = hmax3;
  lft = xi;
  rght = xi;
  for (int i = hmax3; i > 0; i--) {
    while (lft > 0 && leftc[lft][yj] >= i) lft--;
    while (rght <= n && leftc[rght][yj] >= i) rght++;
    ans3 = max(ans3, (rght - lft - 1) * i);
  }
  int hmax4 = rightc[xi][yj];
  int ans4 = hmax4;
  lft = xi;
  rght = yj;
  for (int i = hmax4; i > 0; i--) {
    while (lft > 0 && rightc[lft][yj] >= i) lft--;
    while (rght <= n && rightc[rght][yj] >= i) rght++;
    ans4 = max(ans4, (rght - lft - 1) * i);
  }
  return max(max(ans, ans2), max(ans3, ans4));
}
void update(int xi, int yj) {
  mat[xi][yj] = 1 - mat[xi][yj];
  for (int i = 1; i <= n; i++) {
    if (mat[i][yj]) {
      up[i][yj] = up[i - 1][yj] + 1;
    } else {
      up[i][yj] = 0;
    }
    if (mat[n - i + 1][yj]) {
      down[n - i + 1][yj] = down[n - i + 2][yj] + 1;
    } else {
      down[n - i + 1][yj] = 0;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (mat[xi][i]) {
      leftc[xi][i] = leftc[xi][i - 1] + 1;
    } else {
      leftc[xi][i] = 0;
    }
    if (mat[xi][m - i + 1]) {
      rightc[xi][m - i + 1] = rightc[xi][m - i + 2] + 1;
    } else {
      rightc[xi][m - i + 1] = 0;
    }
  }
}
void build() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (mat[i][j] == 1) {
        up[i][j] = up[i - 1][j] + 1;
        leftc[i][j] = leftc[i][j - 1] + 1;
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      if (mat[i][j]) {
        down[i][j] = down[i + 1][j] + 1;
        rightc[i][j] = rightc[i][j + 1] + 1;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mat[i][j];
    }
  }
  build();
  int t, x, y;
  for (int i = 0; i < q; i++) {
    cin >> t >> x >> y;
    if (t == 1) {
      update(x, y);
    } else {
      cout << query(x, y) << '\n';
    }
  }
  return 0;
}
