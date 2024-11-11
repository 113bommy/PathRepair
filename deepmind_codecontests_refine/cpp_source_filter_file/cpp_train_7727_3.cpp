#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long binpow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return res;
}
long long n;
vector<long long> ans;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  ans.resize(n);
  long long l = 0, cnt = 0;
  long long a, b, c;
  for (long long i = 0; i < n; i++) {
    l = i + 1;
    cnt = n - l + 1;
    b = (10 * (9) * binpow(10, max((long long)0, n - l - 1))) % mod;
    c = (10 * 9 * 9 * binpow(10, max((long long)0, n - l - 2))) % mod;
    ans[i] = 0;
    for (long long i = 0; i < 2; i++) {
      if (cnt > 0) ans[i] = (ans[i] + b) % mod;
      cnt--;
    }
    ans[i] = (ans[i] + max((long long)0, cnt) * c) % mod;
  }
  ans[n - 1] = 10;
  for (auto e : ans) cout << e << " ";
  return 0;
}
