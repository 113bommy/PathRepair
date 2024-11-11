#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
inline long long bigmod(long long B, long long P) {
  long long R = 1;
  while (P > 0) {
    if (P & 1) {
      R = (R * B) % mod;
    }
    P >>= 1;
    B = (B * B) % mod;
  }
  return R;
}
const long long mxn = 2e5 + 10;
long long Mod(long long a) {
  if (a < 0)
    return (a + mod) % mod;
  else
    return a % mod;
}
long long Mul(long long a, long long b) { return Mod(Mod(a) * Mod(b)); }
long long Add(long long a, long long b) { return Mod(Mod(a) + Mod(b)); }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tt = 1;
  for (long long tc = 1; tc <= tt; tc++) {
    long long n, l, r = -1;
    bool ok = true;
    cin >> n;
    long long ip[n];
    for (long long i = 0; i < n; i++) cin >> ip[i];
    if (is_sorted(ip, ip + n)) {
      cout << "yes\n" << 1 << ' ' << 1 << '\n';
      continue;
    }
    for (long long i = 0; i < n - 1; i++) {
      if (ip[i] > ip[i + 1]) {
        l = i;
        for (long long j = i + 1; j < n - 1; j++) {
          if (ip[j] < ip[j + 1]) {
            r = j;
            l = i;
            break;
          }
        }
        break;
      }
    }
    if (r == -1) r = n - 1;
    reverse(ip + l, ip + r + 1);
    if (is_sorted(ip, ip + n)) {
      cout << "yes\n" << l + 1 << ' ' << r + 1 << '\n';
    } else
      cout << "no\n";
  }
  return 0;
}
