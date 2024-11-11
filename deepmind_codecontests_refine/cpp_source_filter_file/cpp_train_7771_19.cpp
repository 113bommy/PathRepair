#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long n, x[10000], y[10000], cnt[1000], ans;
int32_t main() {
  cin >> n;
  for (long long i = 0; i < n - 1; i++) {
    cin >> x[i] >> y[i];
    cnt[x[i]]++;
    cnt[y[i]]++;
  }
  for (long long i = 1; i <= n; i++)
    if (cnt[i] > 1) {
      ans++;
    }
  cout << n - ans;
  return 0;
}
