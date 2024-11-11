#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int inf = 1000000009;
int i, j, k, l, m, n, q;
int ans;
int a[4][1000][1000], h[4][1000][1000], W[4], H[4];
void prec(int k, int i) {
  for (int j = 0; j < H[k]; j++) {
    if (h[k][i][j] == 0)
      a[k][i][j] = 0;
    else {
      a[k][i][j] = 1;
      if (j > 0) a[k][i][j] += a[k][i][j - 1];
    }
  }
}
void fl(int k, int i, int j) {
  h[k][i][j] ^= 1;
  prec(k, i);
}
int best(int k, int i, int j) {
  int ret = 0;
  int i1 = i - 1, i2 = i + 1, y = a[k][i][j];
  while (y > 0) {
    if (i1 >= 0 && a[k][i1][j] >= y) i1--;
    if (i2 < W[k] && a[k][i2][j] >= y) i2++;
    ret = max(ret, (i2 - i1 - 1) * y);
    y--;
  }
  return ret;
}
int main() {
  scanf("%d%d%d", &m, &n, &q);
  W[0] = W[2] = H[1] = H[3] = m;
  H[0] = H[2] = W[1] = W[3] = n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &h[0][i][j]);
      h[1][j][m - i - 1] = h[0][i][j];
      h[2][m - i - 1][n - j - 1] = h[0][i][j];
      h[3][n - j - 1][i] = h[0][i][j];
    }
  for (int k = 0; k < 4; k++)
    for (int i = 0; i < W[k]; i++) prec(k, i);
  while (q--) {
    int op;
    scanf("%d%d%d", &op, &i, &j);
    i--;
    j--;
    if (op == 1) {
      fl(0, i, j);
      fl(1, j, m - i - 1);
      fl(2, m - i - 1, n - j - 1);
      fl(3, n - j - 1, i);
    } else {
      int ans = max(max(best(0, i, j), best(1, j, m - i - 1)),
                    max(best(2, m - i - 1, n - j - 1), best(3, n - j - 1, i)));
      cout << ans << endl;
    }
  }
  return 0;
}
