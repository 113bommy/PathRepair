#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,mmx,tune=native")
long long p, k, mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> p >> k;
  long long cnt = 1, now = k;
  if (k == 1)
    cnt = p;
  else if (k == 0)
    cnt = p - 1;
  else {
    while (now != 1) {
      now = (now * k) % p;
      cnt++;
    }
    cnt = (p - 1) / cnt;
  }
  long long ans = 1;
  for (long long i = 1; i <= cnt; i++) {
    ans = (ans * p) % mod;
  }
  cout << ans << '\n';
}
