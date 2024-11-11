#include <bits/stdc++.h>
using namespace std;
const long long mo = 1e9 + 7;
long long pw[26];
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    pw[0] = 1;
    for (long long i = 1; i <= 25; i++) pw[i] = pw[i - 1] * n % mo;
    long long ans = 0;
    for (long long i = 0; i <= 25; i++)
      if ((k >> i) & 1) ans = (ans + pw[i]) % mo;
    cout << ans << '\n';
  }
  return 0;
}
