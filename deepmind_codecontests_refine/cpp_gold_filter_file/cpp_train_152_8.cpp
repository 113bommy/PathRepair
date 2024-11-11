#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-12;
const long long MOD = 1e9 + 7;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
void fail() {
  cout << "-1";
  exit(0);
}
void win() {
  cout << "YES";
  exit(0);
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long double p[300300], a[300300];
int n;
long double f(long double x) {
  p[0] = a[0] - x;
  for (int i = 1; i < n; i++) p[i] = p[i - 1] + a[i] - x;
  long double ans1 = -2e12, ans2 = 2e12;
  long double mn = 2e9 + 41;
  for (int i = 0; i < n; i++) {
    ans1 = max(p[i] - mn, max(p[i], ans1));
    mn = min(mn, p[i]);
  }
  mn = -2e9 - 41;
  for (int i = 0; i < n; i++) {
    ans2 = min(p[i] - mn, min(p[i], ans2));
    mn = max(mn, p[i]);
  }
  return max(fabs(ans1), fabs(ans2));
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  long double l = -1e5, r = 1e5;
  for (int q = 0; q < 100; q++) {
    long double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
    if (f(m1) < f(m2))
      r = m2;
    else
      l = m1;
  }
  cout.precision(10);
  cout << fixed << f(l);
  return 0;
}
