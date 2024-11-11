#include <bits/stdc++.h>
using namespace std;
double p[1020][1020];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  p[0][0] = 1;
  double total = n * m;
  for (int taken = (0); taken < (n); ++taken) {
    for (int c = (0); c <= (taken); ++c) {
      if (c > m) break;
      double pp = (m - c) / (total - taken);
      p[taken + 1][c + 1] += p[taken][c] * pp;
      p[taken + 1][c] += p[taken][c] * (1 - pp);
    }
  }
  double res = 0;
  for (int c = (0); c <= (m); ++c) {
    double x = (c / (double)n);
    x *= x;
    res += p[n][c] * x;
  }
  res *= n;
  printf("%.10lf\n", res);
}
