#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
using namespace std;
long long fastexpom(long long a, long long b, long long m) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 == 1) res = (((res) % m) * ((a) % m)) % m;
    a = (((a) % m) * ((a) % m)) % m;
    b /= 2;
  }
  return res;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<long long> v(n + 1);
  vector<long long> cnt0(n + 1, 0);
  vector<long long> cnt1(n + 1, 0);
  for (long long i = 0; i < n; i++) {
    v[i + 1] = s[i] - '0';
    if (v[i + 1]) {
      cnt1[i + 1] = cnt1[i] + 1;
      cnt0[i + 1] = cnt0[i];
    } else {
      cnt0[i + 1] = cnt0[i] + 1;
      cnt1[i + 1] = cnt1[i];
    }
  }
  while (m--) {
    long long l, r;
    cin >> l >> r;
    long long one = cnt1[r] - cnt1[l - 1];
    long long zero = cnt0[r] - cnt0[l - 1];
    if (one == 0) {
      cout << "0"
           << "\n";
      continue;
    }
    long long half =
        (fastexpom(2, one, 1000000007) - 1 + 1000000007) % 1000000007;
    long long start = half;
    long long ans = half;
    if (zero != 0) {
      half = (fastexpom(2, zero, 1000000007) - 1 + 1000000007) % 1000000007;
      half = half * start;
      half = half % 1000000007;
      ans = (ans + half) % 1000000007;
    }
    cout << ans << "\n";
  }
  return 0;
}
