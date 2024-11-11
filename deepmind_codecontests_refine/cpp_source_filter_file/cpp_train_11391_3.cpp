#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 1;
const int MAX = 200001;
const long long MOD = 1000000007;
struct trio {
  int first;
  int second;
  int third;
};
struct long_trio {
  long long first;
  long long second;
  long long third;
};
double dist_point_line(int x1, int y1, int x2, int y2, int x3, int y3) {
  double distance = abs((y3 - y1) * x2 - (x3 - x1) * y2 + x3 * y1 - x1 * y3) /
                    (2 * sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1)));
  return distance;
}
double dist_point_point(int x1, int y1, int x2, int y2) {
  double distance = sqrt((x1 - y1) * (x1 - y1) + (x2 - y2) * (x2 - y2));
  return distance;
}
long long inq(long long k, long long q) {
  if (q == 0) return 1;
  long long l = inq(k, q / 2);
  if (q % 2 == 0)
    return l * l % MOD;
  else
    return l * l * k % MOD;
}
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long cubr(long long a) {
  long long l = -1, r = 1e6 + 2;
  while (l < r - 1) {
    long long mid = (l + r) / 2;
    if (mid * mid * mid > a)
      r = mid;
    else
      l = mid;
  }
  return l;
}
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long min(long long a, long long b) { return -1 * max(-a, -b); }
long long possible(long long q) {
  if (q == INF) return -1;
  return q;
}
bool correct(int x, int xx) {
  if (x < 0) return 0;
  if (x >= xx) return 0;
  return 1;
}
long long dsumm(long long x) {
  long long y = 1;
  long long z = 0;
  for (int i = 0; i < 18; i++) {
    z += x / y % 10;
    y *= 10;
  }
  return z;
}
string months[12] = {"January",   "February", "March",    "April",
                     "May",       "June",     "July",     "August",
                     "September", "October",  "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long long fact[13] = {1,    1,     2,      6,       24,       120,      720,
                      5040, 40320, 362280, 3622800, 39916800, 479001600};
int cx[6] = {1, -1, 0, 0, 0, 0};
int cy[6] = {0, 0, 1, -1, 0, 0};
int cz[6] = {0, 0, 0, 0, 1, -1};
long long n, m, k, ans, l, r;
string s;
long long probel, x[1000050], y[1000050], z[1000050];
int main() {
  cin >> s;
  for (int(i) = 0; (i) != (s.size()); i++) {
    if (s[i] == 'x') {
      x[i]++;
    }
    if (s[i] == 'y') {
      y[i]++;
    }
    if (s[i] == 'z') {
      z[i]++;
    }
    if (i > 0) x[i] += x[i - 1];
    if (i > 0) y[i] += y[i - 1];
    if (i > 0) z[i] += z[i - 1];
  }
  cin >> m;
  for (int(i) = 0; (i) != (m); i++) {
    cin >> l >> r;
    r--;
    l--;
    long long alpha = x[r] - x[l - 1];
    long long betta = y[r] - y[l - 1];
    long long gamma = z[r] - z[l - 1];
    if (r - l + 1 <= 3 ||
        (alpha >= (r - l + 1) / 3 && betta >= (r - l + 1) / 3 &&
         gamma >= (r - l + 1) / 3 && abs(alpha - betta) <= 1 &&
         abs(alpha - gamma) <= 1 && abs(betta - gamma) <= 1)) {
      cout << "YES\n";
      continue;
    }
    cout << "NO\n";
  }
}
