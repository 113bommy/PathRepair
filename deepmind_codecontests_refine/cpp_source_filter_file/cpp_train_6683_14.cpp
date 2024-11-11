#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long mod = 1e9 + 7;
const long long mod1 = 998244353;
long long n, k, a[100005];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  long long mi = 1, totmi = 1, totma = 1;
  long long ma = n;
  while (a[mi] == a[mi + 1]) mi++, totmi++;
  while (a[ma] == a[ma - 1]) ma--, totma++;
  if (ma < mi) return cout << k % 2, 0;
  while (k) {
    if (totmi > totma) {
      long long g = (a[ma] - a[ma - 1]);
      if (g * totma <= k) {
        k -= g * totma;
        ma--;
        totma++;
        while (a[ma] == a[ma - 1]) ma--, totma++;
      } else {
        return cout << a[ma] - a[mi] - (k / totma), 0;
      }
    } else {
      long long g = (a[mi + 1] - a[mi]);
      if (g * totmi <= k) {
        k -= g * totmi;
        mi++;
        totmi++;
        while (a[mi] == a[mi + 1]) mi++, totmi++;
      } else {
        return cout << a[ma] - a[mi] - (k / totmi), 0;
      }
    }
    if (a[mi] == a[ma]) return cout << 0, 0;
  }
}
