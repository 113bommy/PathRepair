#include <bits/stdc++.h>
using namespace std;
double power(double a, int n) {
  double res = 1.0, curr = a;
  while (n) {
    if (n & 1) res = (res * curr);
    curr = (curr * curr);
    n >>= 1;
  }
  return res;
}
float prob[5001][5001], p[5001], pp[5001][2];
int main() {
  int n, T, i, j, t[5001], st[5001];
  scanf("%d%d", &n, &T);
  for (i = 1; i <= n; ++i) {
    scanf("%d%d", &j, &t[i]);
    p[i] = (j / 100.0);
    pp[i][0] = power(1 - p[i], t[i] - 1);
    pp[i][1] = pp[i][0] * (1 - p[i]);
  }
  st[1] = t[1];
  for (i = 2; i <= n; ++i) st[i] = st[i - 1] + t[i];
  double tmp1 = 1.0;
  memset(prob, 0, sizeof(prob));
  for (i = 1; i <= T; ++i) {
    if (i == st[1]) {
      prob[i][1] = tmp1;
      break;
    }
    prob[i][1] = tmp1 * p[1];
    tmp1 = tmp1 * (1 - p[1]);
  }
  for (i = 2; i <= T; ++i) {
    for (j = 2; j <= n; ++j) {
      if (st[j] < i || i < j) continue;
      prob[i][j] = prob[i - 1][j] * (1 - p[j]) + (prob[i - 1][j - 1] * p[j]);
      if (i - 1 - t[j] >= 1) {
        prob[i][j] -= (prob[i - 1 - t[j]][j - 1] * pp[j][1]);
      }
      if (i - t[j] >= 1) {
        prob[i][j] -= (prob[i - t[j]][j - 1] * pp[j][0] * p[j]);
        prob[i][j] += (prob[i - t[j]][j - 1] * pp[j][0]);
      }
    }
  }
  double fres = 0.0;
  for (i = 1; i <= T; ++i)
    for (j = 1; j <= n; ++j) {
      fres += prob[i][j];
    }
  printf("%.11lf\n", fres);
}
