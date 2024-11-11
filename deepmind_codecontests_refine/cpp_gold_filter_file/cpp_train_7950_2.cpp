#include <bits/stdc++.h>
using namespace std;
template <class t, class u>
void chmax(t& first, u second) {
  if (first < second) first = second;
}
template <class t, class u>
void chmin(t& first, u second) {
  if (second < first) first = second;
}
unsigned long long int d;
unsigned long long int n, x, y;
long long int f(long long int value) { return y * value - d * x; }
const double EPS = 1e-15;
unsigned long long int binary() {
  long long int lo = -1, hi = 1e12 + 1e6;
  while (hi - lo > 1) {
    long long int mi = lo + (hi - lo) / 2;
    if (f(mi) <= 0)
      lo = mi;
    else
      hi = mi;
  }
  if (lo == -1) return hi;
  if (abs(f(lo)) <= abs(f(hi))) return lo;
  return hi;
}
int main() {
  scanf("%llu%llu%llu", &x, &y, &n);
  double value = double(x) / double(y);
  double Min = 1e13;
  long long int min_num = -1, min_den = -1;
  for (d = 1; d < n + 1; ++d) {
    long long int num = binary();
    if (Min > EPS + abs(value - double(num) / double(d))) {
      Min = abs(value - double(num) / double(d));
      min_num = num;
      min_den = d;
    }
  }
  printf("%lld/%lld\n", min_num, min_den);
  return 0;
}
