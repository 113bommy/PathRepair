#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 4;
const long long MOD = 1e9 + 7;
const long long MX = (long long)1e18;
long long a, b, c, d;
long long get(long long k) {
  if (k < 0) return 0;
  long long ans = (k * (k + 1) * d * b) / 2ll - (k + 1ll) * a;
  return max(0ll, -ans);
}
int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int ttt;
  cin >> ttt;
  while (ttt--) {
    cin >> a >> b >> c >> d;
    if (a > c * b) {
      cout << -1 << endl;
      continue;
    }
    long double minima =
        -((long double)d * (long double)b - (long double)2 * (long double)a) /
        ((long double)2 * (long double)d * (long double)b);
    long long day1 = 0;
    long long day2 = c / d;
    long long day3 = min(day2, (long long)minima);
    long long day4 = min(day2, day3 + 1);
    cout << max({get(day1), get(day2), get(day3), get(day4)}) << endl;
  }
  return 0;
}
