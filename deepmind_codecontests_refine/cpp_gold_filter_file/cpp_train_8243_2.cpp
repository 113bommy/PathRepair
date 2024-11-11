#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
vector<long long> getDivisors(long long val) {
  vector<long long> ret;
  for (long long i = 1; i * i <= val; i++) {
    if (val % i) continue;
    if (i != 1) ret.push_back(i);
    if (val / i == i) continue;
    ret.push_back(val / i);
  }
  return ret;
}
vector<long long> getPrimeFactors(long long val) {
  vector<long long> ret;
  for (long long i = 2; i * i <= val; i++) {
    long long cnt = 0;
    while (val % i == 0) cnt++, val /= i;
    if (cnt) ret.push_back(i);
  }
  if (val > 1) ret.push_back(val);
  return ret;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n + 2);
  for (long long i = 1; i <= n; ++i) cin >> v[i];
  vector<long long> div = getPrimeFactors(accumulate(v.begin(), v.end(), 0ll));
  long long mn = LLONG_MAX;
  vector<long long> pre = v;
  partial_sum(pre.begin(), pre.end(), pre.begin());
  for (auto x : div) {
    long long steps = 0;
    for (long long i = 1; i <= n; i++) {
      steps += min(pre[i] % x, x - pre[i] % x);
    }
    mn = min(mn, steps);
  }
  if (mn == LLONG_MAX) mn = -1;
  cout << mn << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t = 1;
  while (t--) solve();
  return 0;
}
