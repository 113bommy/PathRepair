#include <bits/stdc++.h>
using namespace std;
long long modpow(long long x, long long y) {
  if (x == 0) return 0;
  long long res = 1;
  x = x % 1000000007;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
long long modinv(long long a) { return modpow(a, 1000000007 - 2); }
vector<long long> mf = {1};
vector<long long> mfi = {1};
long long modfact(int n) {
  if (mf.size() > n) {
    return mf[n];
  } else {
    for (int i = mf.size(); i <= n; i++) {
      long long next = mf.back() * i % 1000000007;
      mf.push_back(next);
      mfi.push_back(modinv(next));
    }
    return mf[n];
  }
}
long long modfactinv(int n) {
  if (mfi.size() > n) {
    return mfi[n];
  } else {
    return modinv(modfact(n));
  }
}
long long nCr(int n, int k) {
  if (n < 0 || k < 0 || k > n) {
    return 0;
  } else {
    return modfact(n) * modfactinv(k) % 1000000007 * modfactinv(n - k) %
           1000000007;
  }
}
void solve() {
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  ;
  map<double, int> m;
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  double avg = sum / n;
  double now = avg * (n - 2);
  double req = sum - now;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += m[req - a[i]];
    m[a[i]]++;
  }
  cout << ans << "\n";
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
