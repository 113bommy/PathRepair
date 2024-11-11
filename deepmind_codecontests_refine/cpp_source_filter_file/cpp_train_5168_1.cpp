#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
double lg(double a) { return (log(a) / log(10.0)); }
const long long N = 111111;
long long n, a[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  long long mn = mod;
  for (int i = 0; i <= n - 1; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= n - 1; i++) {
    mn = min(a[i], mn);
  }
  vector<int> v;
  for (int i = 0; i <= n - 1; i++) {
    if (a[i] && mn) v.push_back(i);
  }
  int ans = mod;
  for (int i = 0; i < ((int)(v).size()) - 1; i++) {
    ans = min(ans, v[i + 1] - v[i]);
  }
  cout << ans << endl;
}
