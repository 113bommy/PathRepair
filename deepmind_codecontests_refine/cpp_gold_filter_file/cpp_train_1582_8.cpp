#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
double gtime_() {
  return duration_cast<milliseconds>(
             high_resolution_clock::now().time_since_epoch())
             .count() /
         (double)1000;
}
double gtime() {
  static double tstart = gtime_();
  return gtime_() - tstart;
}
int rand_() {
  static unsigned int X =
      chrono::high_resolution_clock::now().time_since_epoch().count();
  return (X *= 3) >> 1;
}
int f(int i, int k) { return i % k ? i : f(i / k, k); }
int main() {
  int n, m, k, i, xi, yi;
  static int a[16], x[16 - 1], y[16 - 1];
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; ++i) scanf("%d", a + i);
  while (gtime() < 1.975) {
    static int aa[16];
    for (i = 0; i < n; ++i) aa[i] = a[i];
    m = n;
    for (i = 0; i + 1 < n; ++i, --m) {
      x[i] = aa[xi = rand_() % m];
      swap(aa[xi], aa[m - 1]);
      y[i] = aa[yi = rand_() % (m - 1)];
      swap(aa[yi], aa[m - 2]);
      aa[m - 2] = f(x[i] + y[i], k);
    }
    if (aa[0] == 1) {
      printf("YES\n");
      for (i = 0; i < n - 1; ++i) printf("%d %d\n", x[i], y[i]);
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
