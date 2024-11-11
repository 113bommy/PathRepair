#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
long long cal(long long x) {
  long long ans = 0;
  long long d = 1;
  long long po = 1;
  while (po * 10 <= x) {
    ans += po * 9 * d;
    d++;
    po *= 10;
  }
  ans += (x - po + 1) * d;
  return ans;
}
bool check(long long x, long long n) {
  long long c = cal(x);
  return c < n;
}
long long calsum(long long x) {
  long long ans = 0;
  long long d = 1;
  long long po = 1;
  while (po * 10 <= x) {
    long long cur = po * 9;
    long long s1 = (cur * (cur + 1) / 2) * d;
    long long s2 = cal(po - 1);
    ans += s1 + s2 * cur;
    d++;
    po *= 10;
  }
  long long cur = x - po + 1;
  long long s1 = (cur * (cur + 1) / 2) * d;
  long long s2 = cal(po - 1);
  ans += s1 + s2 * cur;
  return ans;
}
bool check2(long long x, long long n) {
  long long c = calsum(x);
  return c <= n;
}
void solve() {
  long long n;
  cin >> n;
  long long lo = 1, hi = 1e9;
  while (hi - lo > 1) {
    long long mid = (hi + lo) / 2;
    if (check2(mid, n))
      lo = mid;
    else
      hi = mid;
  }
  n -= calsum(lo);
  if (n == 0) {
    cout << lo % 10 << '\n';
    return;
  }
  hi = lo + 1;
  lo = 0;
  while (hi - lo > 1) {
    long long mid = (hi + lo) / 2;
    if (check(mid, n))
      lo = mid;
    else
      hi = mid;
  }
  n -= cal(lo);
  string s = to_string(lo + 1);
  cout << s[n - 1] << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long TESTS = 1;
  cin >> TESTS;
  while (TESTS--) {
    solve();
  }
  return 0;
}
