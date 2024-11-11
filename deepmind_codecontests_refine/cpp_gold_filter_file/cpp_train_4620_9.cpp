#include <bits/stdc++.h>
const int P = 777777777;
const int N = 100005;
using namespace std;
struct matrix {
  int a[3][3];
  matrix() { memset(a, 0, sizeof(a)); }
  void init() { a[0][0] = a[1][1] = a[2][2] = 1; }
  void init(int x) { a[x][x] = 1; }
  matrix operator*(const matrix &b) {
    matrix ans;
    int i, j, k;
    for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++)
        for (k = 0; k < 3; k++) {
          ans.a[i][j] += 1LL * a[i][k] * b.a[k][j] % P;
          if (ans.a[i][j] >= P) ans.a[i][j] -= P;
        }
    return ans;
  }
} mat[8], t[N * 3];
int m;
void update(int k, int x) {
  k += m - 1;
  t[k] = mat[x];
  while (k > 0) {
    k = (k - 1) >> 1;
    t[k] = t[k * 2 + 1] * t[k * 2 + 2];
  }
}
int main() {
  int n, Q;
  scanf("%d%d", &n, &Q);
  m = 1;
  while (m < n) m <<= 1;
  int i, j;
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++) scanf("%d", &mat[0].a[j][i]);
  for (i = 1; i <= 3; i++)
    for (j = 0; j < 3; j++) mat[i].a[i - 1][j] = mat[0].a[i - 1][j];
  mat[4].init();
  mat[5].init(0);
  mat[6].init(1);
  mat[7].init(2);
  for (i = 0; i < n - 1; i++) update(i, 0);
  for (; i < m; i++) update(i, 4);
  while (Q--) {
    int v, x;
    scanf("%d%d", &v, &x);
    if (v == 1)
      update(n - 1, 4 + x);
    else
      update(n - v, x);
    int ans = 0;
    for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++) {
        ans += t[0].a[i][j];
        if (ans >= P) ans -= P;
      }
    printf("%d\n", ans);
  }
  return 0;
}
