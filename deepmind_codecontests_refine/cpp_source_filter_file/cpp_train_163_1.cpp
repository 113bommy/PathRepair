#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
signed main() {
  long long int n, k, p;
  cin >> n >> k >> p;
  vector<long long int> pos(n), keys(k);
  for (long long int i = 0; i < n; i++) cin >> pos[i];
  for (long long int i = 0; i < k; i++) cin >> keys[i];
  sort(pos.begin(), pos.end());
  sort(keys.begin(), keys.end());
  long long int ans = 1e9;
  for (long long int i = 0; i <= k - n; i++) {
    long long int summ = 0;
    for (long long int j = 0; j < n; j++) {
      summ = max(summ, abs(keys[i + j] - pos[j]) + abs(p - keys[i + j]));
    }
    ans = min(ans, summ);
  }
  cout << ans;
  return 0;
}
