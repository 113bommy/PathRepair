#include <bits/stdc++.h>
using namespace std;
const int32_t mod = 1e9 + 7;
const int32_t mod2 = 998244353;
bool check(long long k, long long h, vector<long long> &v) {
  long long n = v.size();
  long long sum = 0;
  for (long long i = 0; i < n - 1; i++) {
    sum += min(v[i + 1] - v[i], k);
  }
  sum += k;
  return (sum >= h);
}
void TestCases(long long tc) {
  long long n, h;
  cin >> n >> h;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long l = 0, r = 1e17;
  long long k = 0;
  while (l <= r) {
    long long midk = l + (r - l) / 2;
    if (check(midk, h, v)) {
      k = midk;
      r = midk - 1;
    } else {
      l = midk + 1;
    }
  }
  cout << k << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    TestCases(i);
  }
  return 0;
}
