#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int _max;
double C[N][N];
void init(int n) {
  for (int i = 0; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
}
int n, m, l[N], w[N][N];
int val[N * N], cnt;
int lim, must, can, d[N];
bool contain[N];
double f[N][N];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &l[i]);
    _max = max(_max, l[i]);
    for (int j = 1; j <= l[i]; ++j) scanf("%d", &w[i][j]), val[++cnt] = w[i][j];
  }
  init(_max);
  sort(val + 1, val + cnt + 1, greater<int>());
  lim = val[n];
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= l[i]; ++j) {
      if (w[i][j] > lim) ++d[i], ++must;
      if (w[i][j] == lim) contain[i] = 1, ++can;
    }
  }
  f[0][0] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j <= n - must; ++j) {
      f[i][j] = f[i - 1][j] / C[l[i]][d[i]];
      if (contain[i]) f[i][j] += f[i - 1][j - 1] / C[l[i]][d[i] + 1];
    }
  }
  printf("%.10lf\n", f[m][n - must] / C[can][n - must]);
}
