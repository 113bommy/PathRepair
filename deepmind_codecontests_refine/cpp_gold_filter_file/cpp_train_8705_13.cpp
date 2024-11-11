#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, mod;
  cin >> n >> mod;
  long long m = n / 2;
  n -= m;
  vector<long long> a(n);
  vector<long long> b(m);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] %= mod;
  }
  for (long long i = 0; i < m; ++i) {
    cin >> b[i];
    b[i] %= mod;
  }
  set<long long> st_a;
  for (long long i = 0; i < 1LL << (n + 1); ++i) {
    long long sum = 0;
    for (long long j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        sum += a[j];
      }
    }
    st_a.insert(sum % mod);
  }
  set<long long> st_b;
  for (long long i = 0; i < 1LL << (m + 1); ++i) {
    long long sum = 0;
    for (long long j = 0; j < m; ++j) {
      if ((i >> j) & 1) {
        sum += b[j];
      }
    }
    st_b.insert(sum % mod);
  }
  long long res = -1;
  for (auto x : st_a) {
    auto it = st_b.upper_bound(mod - 1 - x);
    it--;
    res = max(res, x + *it);
  }
  cout << res;
  return 0;
}
