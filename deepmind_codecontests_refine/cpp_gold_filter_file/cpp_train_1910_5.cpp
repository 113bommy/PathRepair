#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,popcnt,tune=native")
using namespace std;
const int SZE = 1e3 + 5;
const int MOD = 1e9 + 7;
int n;
int m, u;
int x[250], y[250];
int res[1000001];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> x[i] >> y[i];
  for (int i = 1; i <= n; i++) res[i] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      if (y[j] == y[i] || (long long)(x[i] - x[j]) * y[i] % (y[j] - y[i]) != 0)
        continue;
      long long t = x[i] + (long long)(x[i] - x[j]) * y[i] / (y[j] - y[i]);
      if (t >= 1 && t <= n) {
        int cnt = 0;
        for (int k = 0; k < m; k++) {
          if ((long long)(x[i] - x[k]) * (y[j] - y[k]) -
                  (long long)(x[j] - x[k]) * (y[i] - y[k]) ==
              0)
            cnt++;
        }
        res[t] = max(res[t], cnt);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += res[i];
  }
  cout << ans;
  return 0;
}
