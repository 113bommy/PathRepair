#include <bits/stdc++.h>
using namespace std;
int x, y, xc, yc;
int n, k, e;
int d2[105];
double P[105][105];
bool ok(double m) {
  double r2 = m * m;
  P[0][0] = 1.0;
  for (int i = 1; i <= n; i++) {
    double p = (d2[i - 1] < r2 + 1e-8) ? 1.0 : exp(1.0 - (d2[i - 1] / r2));
    for (int j = 0; j < k; j++) {
      P[i][j] = (P[i - 1][j] * (1 - p));
      if (j > 0) P[i][j] += (P[i - 1][j - 1] * p);
    }
  }
  double lose = 0.0;
  for (int j = 0; j < k; j++) lose += P[n][j];
  return lose * 1000 < e - 1e-8;
}
int main() {
  n = ({
    int x;
    scanf("%d", &x);
    x;
  });
  k = ({
    int x;
    scanf("%d", &x);
    x;
  });
  e = ({
    int x;
    scanf("%d", &x);
    x;
  });
  xc = ({
    int x;
    scanf("%d", &x);
    x;
  });
  yc = ({
    int x;
    scanf("%d", &x);
    x;
  });
  for (int _n(n), i(0); i < _n; i++) {
    x = ({
      int x;
      scanf("%d", &x);
      x;
    });
    y = ({
      int x;
      scanf("%d", &x);
      x;
    });
    d2[i] = (x - xc) * (x - xc) + (y - yc) * (y - yc);
  }
  double lo = 0.0, hi = 10010;
  for (int _n(200), t(0); t < _n; t++) {
    double m = (lo + hi) / 2.0;
    if (ok(m))
      hi = m;
    else
      lo = m;
  }
  printf("%.10lf\n", (lo + hi) / 2.0);
  return 0;
}
