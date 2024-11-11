#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
long long f[maxn][maxn][maxn];
double jc[maxn];
int a[maxn], b[maxn], n, p;
void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  scanf("%d", &p);
}
void prepare() {
  sort(a + 1, a + n + 1);
  for (int i = 1; i < maxn; ++i) jc[i] = jc[i - 1] + log(double(i));
}
void compute(int flag) {
  memset(f, 0, sizeof(f));
  f[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int h = 0; h <= p; ++h) {
        if (f[i][j][h] == 0) continue;
        if (i + 1 != flag && h + a[i + 1] <= p)
          f[i + 1][j + 1][h + a[i + 1]] += f[i][j][h];
        f[i + 1][j][h] += f[i][j][h];
      }
    }
  }
}
void work() {
  prepare();
  int sum = 0;
  for (int i = 0; i < n; ++i) sum += a[i];
  if (sum <= p) {
    printf("%.6lf\n", double(n));
    return;
  }
  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    compute(i);
    for (int j = 1; j < n; ++j) {
      for (int h = 1; h <= p; ++h) {
        if (h + a[i] <= p) continue;
        if (f[n][j][h] == 0) continue;
        double add = log(double(f[n][j][h])) + jc[j] + jc[n - j - 1] +
                     log(double(j)) - jc[n];
        ans += exp(add);
      }
    }
  }
  printf("%.6lf\n", ans);
}
int main() {
  init();
  work();
  return 0;
}
