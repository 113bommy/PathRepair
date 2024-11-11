#include <bits/stdc++.h>
const int lbt = 1e9 + 7;
struct matrix {
  long long a[101][101];
  int sz;
  matrix() { sz = 0; }
  void init(int sz) {
    this->sz = sz;
    for (int i = 1; i <= sz; i++) {
      for (int j = 1; j <= sz; j++) {
        a[i][j] = 0;
      }
    }
  }
};
matrix multiply(matrix m1, matrix m2);
char str[102];
matrix f[101];
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  scanf("%s", str + 1);
  for (int i = 0; i <= x; i++) {
    f[i].init(n + 1);
  }
  for (int i = 1; i <= n; i++) {
    if (str[i] == '0') {
      f[0].a[i][i + 1] = 1;
    } else {
      f[1].a[i][i + 1] = 1;
    }
    f[0].a[i][i] = f[1].a[i][i] = 1;
  }
  f[0].a[1][1] = f[1].a[1][1] = f[0].a[n + 1][n + 1] = f[1].a[n + 1][n + 1] = 2;
  for (int i = 2; i <= x; i++) {
    f[i] = multiply(f[i - 1], f[i - 2]);
  }
  printf("%d", f[x].a[1][n + 1]);
  return 0;
}
matrix multiply(matrix m1, matrix m2) {
  matrix ans;
  ans.init(m1.sz);
  for (int i = 1; i <= m1.sz; i++) {
    for (int j = 1; j <= m1.sz; j++) {
      for (int k = 1; k <= m1.sz; k++) {
        ans.a[i][j] += ((m1.a[i][k] % lbt) * (m2.a[k][j] % lbt)) % lbt;
        ans.a[i][j] %= lbt;
      }
    }
  }
  return ans;
}
