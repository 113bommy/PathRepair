#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
long double f[2][MAXN], qpow[MAXN];
double p[MAXN];
int t[MAXN];
int n, T;
int main() {
  scanf("%d%d", &n, &T);
  for (int i = 1; i <= n; i++)
    scanf("%lf%d", &p[i], &t[i]), p[i] = (100 - p[i]) / 100;
  f[1][0] = 1;
  long double res = 0;
  for (int i = 1; i <= n; i++) {
    qpow[0] = 1;
    for (int j = 1; j <= T; j++) qpow[j] = qpow[j - 1] * p[i];
    long double sum = 0;
    for (int j = 1; j <= T; j++) {
      if (t[i] == 1)
        f[0][j] = f[1][j - 1];
      else {
        sum *= p[i];
        if (j - t[i] >= 0) sum -= f[1][j - t[i]] * qpow[t[i] - 1] * (1 - p[i]);
        sum += f[1][j - 1] * (1 - p[i]);
        if (j - t[i] >= 0) sum += f[1][j - t[i]] * qpow[t[i] - 1];
        f[0][j] = sum;
      }
      res += f[0][j];
    }
    for (int j = 0; j <= T; j++) f[1][j] = f[0][j], f[0][j] = 0;
  }
  printf("%.9lf\n", (double)res);
  return 0;
}
