#include <bits/stdc++.h>
const long long INF = (long long)1e7 + 1;
const long long mod = (long long)998244353;
const long long hell = (long long)1000000007;
using namespace std;
long long int power(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y % 2) res = (x * res) % mod;
    x = (x * x) % mod;
    y = y / 2;
  }
  return res;
}
long long int modinv(long long int x) { return power(x, hell - 2); }
void solve();
void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fastIO();
  solve();
}
long long int pw(long long int k, long long int x);
long long int gcd(long long int x, long long int y);
bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first)
    return (a.first < b.first);
  else
    return a.second < b.second;
}
void solve() {
  int test;
  cin >> test;
  while (test--) {
    long long int x;
    cin >> x;
    long long int q = x / 14;
    long long int r = x % 14;
    if (q >= 1 and (r >= 1 and r <= 6))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
long long int gcd(long long int x, long long int y) {
  if (x == 0)
    return y;
  else
    return gcd(y % x, x);
}
long long int pw(long long int k, long long int x) {
  if (x == 0) return 1;
  if (x & 1)
    return ((pw(k, x - 1)) * k);
  else
    return ((pw(k, x / 2)) * (pw(k, x / 2)));
}
