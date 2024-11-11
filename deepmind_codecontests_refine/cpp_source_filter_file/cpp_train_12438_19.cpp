#include <bits/stdc++.h>
using namespace std;
long long x[1000000];
int n;
bool f(long long d) {
  if (x[0] + 2 * d >= x[n - 1]) return true;
  int p1 = 0, p2 = n - 1;
  while (x[p1] <= x[0] + 2 * d) p1++;
  while (x[p2] >= x[n - 1] - 2 * d) p2--;
  return x[p2] - x[p1] <= 2 * d;
}
int main() {
  int n;
  long long lo, hi, mid;
  cin >> n;
  for (int i = 0; i < (n); ++i) cin >> x[i], x[i] *= 2;
  sort(x, x + n);
  lo = 0, hi = INT_MAX;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (f(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  printf("%.6lf\n", lo / 2.);
  printf("%.6lf ", (x[0] + lo) / 2.);
  int p1 = 0, p2 = n - 1;
  while (x[p1] <= x[0] + 2 * lo) p1++;
  while (x[p2] >= x[n - 1] - 2 * lo) p2--;
  if (p1 > p2)
    printf("%.6lf", (x[0] + lo) / 2.);
  else
    printf("%.6lf", (x[p1] + x[p2]) / 4.);
  printf(" %.6lf\n", (x[n - 1] - lo) / 2.);
  return 0;
}
