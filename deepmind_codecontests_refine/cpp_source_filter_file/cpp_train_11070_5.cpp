#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1.0);
const double EPS = 1E-9;
const int INF = 2 * (1e+9) + 1;
const int NMAX = 2000;
const int MOD = (1e+9) + 7;
long long n, c;
long long a[100100], b[100200];
long long days(long long v) {
  long long res = 0;
  for (int i = 0; i < (n); ++i) {
    if (v * a[i] / b[i] > INF) return 1e+18;
    res += v * a[i] / b[i] + 1ll;
    if (res > INF) return 1e+18;
  }
  return res;
}
int main() {
  cin >> n >> c;
  int sum = 0;
  for (int i = 0; i < (n); ++i) {
    cin >> a[i] >> b[i];
    sum += a[i];
  }
  long long low = 0, high = 0;
  long long l = 0, r = 1e+18;
  while (r - l > 1) {
    long long mid = l + (r - l) / 2;
    if (days(mid) < c) {
      l = mid;
    } else
      r = mid;
  }
  low = r;
  if (days(r) != c) {
    cout << 0;
    return 0;
  }
  if (sum == 0) {
    cout << -1;
    return 0;
  }
  l = 0, r = 1e+18;
  while (r - l > 1) {
    long long mid = l + (r - l) / 2;
    if (days(mid) <= c) {
      l = mid;
    } else
      r = mid;
  }
  high = r;
  cout << high - low;
}
