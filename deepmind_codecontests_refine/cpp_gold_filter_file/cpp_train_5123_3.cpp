#include <bits/stdc++.h>
using namespace std;
long long inf = 1e18;
long long n, m, k, t = 1, x, y, z, l, r, w, d, q, ct, ans, f;
long long a[203003];
string s, p;
set<long long> si;
queue<long long> qi;
map<long long, long long> mi;
priority_queue<long long, vector<long long>, greater<long long>> pqai;
long long powe(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res *= x, res %= 998244353;
    y >>= 1;
    x *= x;
    x %= 998244353;
  }
  return res;
}
long long inv(long long x) { return powe(x, 998244353 - 2); }
signed main() {
  cin >> n;
  long long curr = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    curr = (curr + 1) * 100 % 998244353;
    curr *= inv(a[i]);
    curr %= 998244353;
  }
  cout << curr;
}
