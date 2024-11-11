#include <bits/stdc++.h>
using namespace std;
int m, n, j, k, l, i, o, p, __t;
double A[1000];
int main() {
  double ans = 0;
  cin >> m;
  for (int i = (0); i <= (m); i++) scanf("%lf", &A[i]);
  if (m % 2 != 0) ans = A[m / 2];
  for (int i = (0); i <= (m); i++)
    for (int j = (i + 1); j <= (m); j++)
      if (m - 2 * i > 0 && m - 2 * j < 0)
        ans =
            max(ans, (A[i] * (2 * j - m) + A[j] * (m - 2 * i)) / (2 * (j - i)));
  printf("%.8lf\n", ans);
}
