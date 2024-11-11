#include <bits/stdc++.h>
using namespace std;
bool point_left_from_line(long long x1, long long x2, long long poix,
                          long long y1, long long y2, long long poiy) {
  return (poix - x1) * (y2 - y1) < (poiy - y1) * (x2 - x1);
}
bool point_on_line(long long x1, long long x2, long long poix, long long y1,
                   long long y2, long long poiy) {
  return (poix - x1) * (y2 - y1) == (poiy - y1) * (x2 - x1);
}
bool point_on_circle(long long x, long long y, long long px, long long py,
                     long double r) {
  long double eps = 1e-12;
  if ((px - x) * (px - x) + (py - y) * (py - y) - r * r < eps)
    return 1;
  else
    return 0;
}
bool point_into_circle(long long x, long long y, long long px, long long py,
                       long double r) {
  long double eps = 1e-12;
  if ((px - x) * (px - x) + (py - y) * (py - y) < r * r - eps)
    return 1;
  else
    return 0;
}
long long ll_sign_0(long long x) {
  if (x < 0) return -1;
  if (x > 0) return 1;
  if (x == 0) return 0;
}
struct st {
  long long num;
  long long t;
  int type;
};
bool cmp(const st &a, const st &b) {
  if (b.t == a.t) return b.type == 2;
  return b.t > a.t;
}
long long maxdiv(long long x) {
  long long n = (long long)sqrt((long double)x);
  long long res;
  for (long long i = n; i >= 1; i--) {
    if (x % i == 0) {
      res = i;
      break;
    }
  }
  return res;
}
int main() {
  long long n, res;
  cin >> n;
  res = n;
  long long div = maxdiv(n);
  while (div != 1) {
    n /= div;
    res += n;
    div = maxdiv(n);
  }
  if (n != 1) res++;
  cout << res;
  return 0;
}
