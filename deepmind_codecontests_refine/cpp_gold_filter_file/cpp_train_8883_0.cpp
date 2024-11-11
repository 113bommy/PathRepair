#include <bits/stdc++.h>
inline int getInt() {
  int s;
  scanf("%d", &s);
  return s;
}
using namespace std;
template <int N>
bool solve(double a[N][N], double c[N], int ret[N]) {
  for (int i = 0; i < (int)(N); i++) {
    if (a[i][i] == 0) {
      for (int j = i + 1; j < N; j++) {
        if (a[j][i] != 0) {
          for (int k = 0; k < (int)(N); k++) swap(a[i][k], a[j][k]);
          swap(c[i], c[j]);
          break;
        }
      }
    }
    if (a[i][i] == 0) return false;
    for (int j = 0; j < (int)(N); j++)
      if (i != j) {
        if (a[j][i] != 0) {
          double p = a[j][i] / a[i][i];
          for (int k = 0; k < (int)(N); k++) a[j][k] -= p * a[i][k];
          c[j] -= p * c[i];
        }
      }
  }
  const double EPS = 1e-9;
  for (int i = 0; i < (int)(N); i++) {
    int r = floor(c[i] / a[i][i] + EPS);
    if (std::abs(r * a[i][i] - c[i]) > EPS) return false;
    ret[i] = r;
  }
  return true;
}
int main() {
  int c[6];
  for (int i = 0; i < (int)(6); i++) c[i] = getInt();
  int t[7][6] = {{0}};
  int o[7];
  for (int c = 0; c < (int)(7); c++) {
    int f = c + 1;
    for (int i = 0; i < (int)(4); i++)
      for (int j = 0; j < (int)(4); j++)
        if (i < j) {
          int idx = 0;
          if (i == 0) idx = j - 1;
          if (i == 1) idx = 3 + j - 2;
          if (i == 2) idx = 5;
          int i1 = (f & (1 << i)) == 0;
          int i2 = (f & (1 << j)) == 0;
          if (i1 == i2) t[c][idx] = 0;
          if (i1 != i2) t[c][idx] = 1;
        }
    o[c] = f;
  }
  const int inf = 1000000;
  int ans = inf;
  int ansh[7];
  for (int i = 0;; i++) {
    double tmp[6][6];
    double cc[6];
    int ret[6];
    for (int j = 0; j < (int)(6); j++)
      for (int k = 0; k < (int)(6); k++) tmp[k][j] = t[j][k];
    for (int j = 0; j < (int)(6); j++) cc[j] = c[j];
    if (solve(tmp, cc, ret)) {
      int sum = i;
      for (int j = 0; j < (int)(6); j++) {
        if (ret[j] < 0) goto bad;
        sum += ret[j];
      }
      if (ans > sum) {
        ans = sum;
        for (int j = 0; j < (int)(6); j++) ansh[j] = ret[j];
        ansh[6] = i;
      }
    }
  bad:;
    for (int j = 0; j < (int)(6); j++) {
      c[j] -= t[6][j];
      if (c[j] < 0) goto end;
    }
  }
end:;
  if (ans == inf) {
    puts("-1");
  } else {
    printf("%d\n", ans);
    for (int i = 0; i < (int)(4); i++) {
      for (int j = 0; j < (int)(7); j++) {
        const int oo = o[j];
        bool b = oo & (1 << i);
        for (int k = 0; k < (int)(ansh[j]); k++) {
          putchar(b ? 'a' : 'b');
        }
      }
      puts("");
    }
  }
  return 0;
}
