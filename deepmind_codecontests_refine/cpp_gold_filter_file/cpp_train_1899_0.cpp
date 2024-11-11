#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> calced;
long long x_m(long long m, long long mod) {
  for (pair<long long, long long> a : calced) {
    if (a.first == m) return a.second;
  }
  if (m == 1) return 1 % mod;
  if (m == 2) return 3 % mod;
  for (long long i = 1; i < m; i *= 2) {
    if (i * 2 > m) {
      long long pw = x_m(i, mod);
      long long pw2 = x_m(i - 1, mod);
      long long val = (pw + (m - i) * (pw - pw2)) % mod;
      if (val < 0) val += mod;
      calced.insert(calced.begin(), make_pair(m, val));
      return val;
    }
    if (i * 2 == m) {
      long long val = (2 * (x_m(m - 1, mod)) + 1) % mod;
      if (val < 0) val += mod;
      calced.insert(calced.begin(), make_pair(m, val));
      return val;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    calced.clear();
    long long d, m;
    cin >> d >> m;
    cout << x_m(d, m) << endl;
  }
}
