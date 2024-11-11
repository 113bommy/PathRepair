#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000009;
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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, h, x;
  cin >> n >> h >> k;
  int s;
  long long sol = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    if (s + x <= h) {
      sol += (s + x) / k;
    } else {
      sol += x / k;
      sol++;
      s = 0;
    }
    s += x;
    s %= k;
  }
  sol += (s + k - 1) / k;
  cout << sol;
  return 0;
}
