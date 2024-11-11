#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int inf = 10000000009;
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
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n, x, y;
  cin >> n;
  map<int, int> mp1, mp2;
  long long ans{};
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    ans += mp1[x - y]++;
    ans += mp2[x + y]++;
  }
  cout << ans << endl;
  return 0;
}
