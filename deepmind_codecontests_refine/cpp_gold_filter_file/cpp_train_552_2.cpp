#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int MOD(long long int n) { return ((n % mod) + mod) % mod; }
long long int power(long long int a, long long int b) {
  if (b == 0) return 1LL;
  long long int s = power(a, b / 2LL);
  s *= s;
  s %= mod;
  if (b & 1LL) return (s * a) % mod;
  return s;
}
long long int inv(long long int a) { return power(a, mod - 2); }
long long int nCr(long long int n, long long int r) {
  if (r > n) return 0LL;
  if (n - r < r) r = n - r;
  long long int ans = 1;
  for (long long int i = 0; i < r; i++) {
    ans *= (n - i);
    ans = MOD(ans);
    ans *= inv(i + 1);
    ans = MOD(ans);
  }
  return ans;
}
bool f(pair<long long int, long long int>& a,
       pair<long long int, long long int>& b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}
signed main() {
  long long int n, k;
  cin >> n >> k;
  map<pair<long long int, long long int>, long long int> m;
  vector<pair<long long int, long long int>> a(n);
  for (long long int i = 0; i < n; i++) {
    long long int x, y;
    cin >> x >> y;
    a[i] = {x, y};
    m[{x, y}]++;
  }
  sort(a.begin(), a.end(), f);
  cout << m[{a[k - 1].first, a[k - 1].second}] << endl;
  return 0;
}
