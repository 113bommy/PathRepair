#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000000000000000ll;
long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }
long long c1, c2, n, pp, re, sp;
long long c(long long x, long long y) {
  if (x - y < y) y = x - y;
  if (y <= 0) return 1;
  if (y == 1) return x;
  long long re = 1;
  for (long long i = 1; i <= y; i++) {
    long long g = gcd(re, i), tp = (y - x + i);
    re /= g;
    tp /= (i / g);
    re = re * tp;
    if (re % tp || re <= 0 || re > n) return inf;
  }
  return re;
}
bool check(long long mid) {
  pp = 0;
  re = 0;
  long long up = mid / c2;
  long long last = -1;
  pp = 0;
  long long calc = 0;
  for (long long l = up; l >= 0; l--) {
    long long num = (mid - l * c2) / c1;
    if (l == 0) {
      calc = 1;
      pp += calc;
      re += calc * c1 * (last + 1);
      if (pp >= n) return 1;
      continue;
    }
    if (l == 1 && sp) {
      pp += max(num - last - 1, 0ll);
      if (pp >= n) return 1;
    } else {
      for (long long j = num; j >= last + 2; j--) {
        calc = c(j + l - 1, l - 1);
        pp += calc;
        re += calc * (l * c2 + j * c1);
        if (pp >= n) return 1;
      }
    }
    calc = c(l + last + 1, last + 1);
    pp += calc;
    re += calc * (l * c2 + (last + 1) * c1);
    if (pp >= n) return 1;
    last = num;
  }
  if (pp >= n) return 1;
  return 0;
}
int main() {
  cin >> n >> c1 >> c2;
  if (c1 > c2) swap(c1, c2);
  if (c1 == 0) {
    cout << c2 * (n - 1);
    return 0;
  }
  long long gp = gcd(c1, c2);
  c1 /= gp;
  c2 /= gp;
  long long l = 0, r = 1000000000000000000ll, ans = 0;
  sp = 1;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  sp = 0;
  pp = 0;
  check(ans - 1);
  long long rem = (n - pp);
  re = re + rem * ans + rem * c1;
  cout << re * gp;
}
