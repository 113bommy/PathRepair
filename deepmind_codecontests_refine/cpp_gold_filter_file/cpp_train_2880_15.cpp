#include <bits/stdc++.h>
using namespace std;
const int maxN = 210;
const int inf = 2147483647;
int n;
double P[maxN], F[maxN][maxN * maxN];
inline double Max(register double a, register double b);
int main() {
  scanf("%d", &n);
  register int i, j, k;
  int up = min(n + n, 200);
  for (i = 0; i <= up; ++i)
    for (j = 0; j <= up * up; ++j) F[i][j] = -inf;
  F[0][0] = 0;
  for (i = 0; i <= n; i++) cin >> P[i];
  for (i = 1; i <= up; ++i)
    for (j = 0; j <= i * n; ++j)
      for (k = 0; k <= n; ++k)
        if (j - k + (n - k) >= 0)
          F[i][j] = Max(F[i][j], F[i - 1][j - k + (n - k)] + P[k]);
  double mx = 0;
  for (i = 1; i <= up; i++) mx = max(mx, F[i][0] / i);
  printf("%.10lf\n", mx);
  return 0;
}
inline double Max(register double a, register double b) {
  return (a > b) ? (a) : (b);
}
