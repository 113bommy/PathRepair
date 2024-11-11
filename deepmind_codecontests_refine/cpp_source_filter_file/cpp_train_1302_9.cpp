#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const int MOD = 1e9 + 7;
bool was[1005000];
long long fp(long long x, long long n, long long mod) {
  long long ans = 1;
  while (n) {
    if (x & 1) ans = (ans * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return ans;
}
int main() {
  int p, k;
  cin >> p >> k;
  if (k == 0)
    cout << fp(p, p - 1, MOD) << endl;
  else if (k == 1)
    cout << fp(p, p, MOD) << endl;
  else {
    long long ans = 1;
    long long inv = fp(k, p - 2, p);
    for (int i = 1; i < p; i++) {
      if (was[i]) continue;
      long long cur = i;
      int sz = 0;
      while (not was[cur]) {
        was[cur] = true;
        cur = (cur * k) % p;
        sz++;
      }
      if (fp(inv, sz, p) == 1) ans = (ans * p) % MOD;
    }
    cout << ans << endl;
  }
  return 0;
}
