#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
int p[(int)2e5 + 10];
long long qpow(long long a, long long b) {
  long long res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int i, j;
  cin >> n;
  long long ans = 0;
  for (i = 1; i <= n; i++) {
    cin >> p[i];
    ans = ((ans + 1) * 100 % mod * qpow(p[i], mod - 2)) % mod;
  }
  cout << ans << endl;
  return 0;
}
