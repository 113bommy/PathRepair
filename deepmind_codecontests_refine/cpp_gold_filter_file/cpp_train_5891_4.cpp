#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const int MAX_N = (int)3e5 + 17;
const int mod = (int)1e9 + 7 + eps;
int N, M, S, T, K, tp, bk;
double X[MAX_N], Y[MAX_N];
int main() {
  int kase = 1;
  long long n, k;
  long long cnt = 0;
  while (~scanf("%d", &N)) {
    for (int i = 0; i < N; i++) {
      scanf("%lf %lf", &X[i], &Y[i]);
    }
    double ans = LLINF;
    for (int i = 1; i < N - 1; i++) {
      double x1 = X[i - 1], y1 = Y[i - 1];
      double x0 = X[i], y0 = Y[i];
      double x2 = X[i + 1], y2 = Y[i + 1];
      double d =
          (fabs((y2 - y1) * x0 + (x1 - x2) * y0 + ((x2 * y1) - (x1 * y2)))) /
          (sqrt(pow(y2 - y1, 2) + pow(x1 - x2, 2)));
      if (d < ans) ans = d;
    }
    int i = 0;
    double x1 = X[N - 1], y1 = Y[N - 1];
    double x0 = X[i], y0 = Y[i];
    double x2 = X[i + 1], y2 = Y[i + 1];
    double d =
        (fabs((y2 - y1) * x0 + (x1 - x2) * y0 + ((x2 * y1) - (x1 * y2)))) /
        (sqrt(pow(y2 - y1, 2) + pow(x1 - x2, 2)));
    i = N - 1;
    if (d < ans) ans = d;
    x1 = X[i - 1], y1 = Y[i - 1];
    x0 = X[i], y0 = Y[i];
    x2 = X[0], y2 = Y[0];
    d = (fabs((y2 - y1) * x0 + (x1 - x2) * y0 + ((x2 * y1) - (x1 * y2)))) /
        (sqrt(pow(y2 - y1, 2) + pow(x1 - x2, 2)));
    if (d < ans) ans = d;
    printf("%.10lf\n", ans / 2);
  }
  return 0;
}
