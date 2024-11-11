#include <bits/stdc++.h>
using namespace std;
long long pot[80];
long long f(long long x) {
  long long S = 0;
  while (x % 2 == 0) {
    S += x / 2;
    x /= 2;
  }
  return S + x * (x - 1) / 2;
}
long long solve(long long x, long long n) {
  long long hi = (long long)(1e9 + 1), lo = 1;
  if (x > 0) hi = max(hi, n / x + 1);
  if (x == n) return 1;
  while (lo + 1 < hi) {
    long long mid = ((lo + hi) >> 1);
    if ((2 * x + (mid - 1)) <= 2 * n / mid)
      lo = mid;
    else
      hi = mid;
  }
  if (lo & 1 and lo * x + lo * (lo - 1) / 2 == n) return lo;
  return -1;
}
int main() {
  long long n;
  pot[0] = 1;
  for (int i = 1; i < 63; i++) pot[i] = pot[i - 1] * 2LL;
  while (cin >> n) {
    vector<long long> ans;
    for (int i = 0; i < 63; i++) {
      if (pot[i] - 1 > n) break;
      long long k = solve(pot[i] - 1, n);
      if (k != -1) ans.push_back(pot[i] * k);
    }
    sort(ans.begin(), ans.end());
    if (ans.size() > 0)
      ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
    if (ans.size() == 0) cout << -1 << endl;
  }
  return 0;
}
