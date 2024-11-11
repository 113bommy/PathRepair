#include <bits/stdc++.h>
using namespace std;
const int N = 2010000;
int x[110000], y[110000];
int n;
long double sumx2, sumx, sum;
long double sumy2, sumy;
long double l[N], r[N];
const long double dw = 1.;
inline void cover(int x1, int y1, int x2, int y2) {
  if (x1 > x2) {
    swap(x1, x2);
    swap(y1, y2);
  }
  if (x1 == x2) {
    l[x1] = min(l[x1], dw * min(y2, y1));
    r[x1] = max(r[x1], dw * max(y2, y1));
  } else {
    for (int k = (x1); k <= (int)x2; k++) {
      long double jiao = (y2 - y1) * ((k - x1) * dw / (x2 - x1)) + y1;
      r[k] = max(r[k], jiao);
      l[k] = min(l[k], jiao);
    }
  }
}
inline void Do() {
  for (int i = (0); i <= (int)N; i++) l[i] = N, r[i] = 0;
  for (int i = (1); i <= (int)n; i++) cover(x[i], y[i], x[i + 1], y[i + 1]);
  for (int i = (0); i <= (int)N; i++)
    if (l[i] < N - 2) {
      int a1 = ceil(l[i]);
      int a2 = (int)r[i];
      long double ll = a1 * 1.;
      long double rr = a2 * 1.;
      sum += rr - ll + 1;
      sumx += (rr - ll + 1) * i;
      sumx2 += (rr - ll + 1) * 1. * i * i;
    }
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (int)n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    x[i] += N / 2;
    y[i] += N / 2;
  }
  x[n + 1] = x[1];
  y[n + 1] = y[1];
  Do();
  for (int i = (1); i <= (int)n + 1; i++) swap(x[i], y[i]);
  sumy2 = sumx2;
  sumy = sumx;
  sumx2 = sumx = sum = 0;
  Do();
  long double ans = sum * sumx2 - sumx * sumx + sum * sumy2 - sumy * sumy;
  ans /= sum;
  ans /= (sum - 1);
  printf("%.10lf\n", (double)ans);
  return 0;
}
