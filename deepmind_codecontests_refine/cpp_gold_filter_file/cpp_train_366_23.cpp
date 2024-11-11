#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, siz = 1e5 + 5;
long long t, n, m, k, a[siz], mins[siz][40], sum[siz][40], to[siz][40];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) cin >> to[i][0], to[i][0]++;
  for (long long i = 1; i <= n; i++) cin >> sum[i][0], mins[i][0] = sum[i][0];
  for (long long i = 1; i < 40; i++) {
    for (long long j = 1; j <= n; j++) {
      to[j][i] = to[to[j][i - 1]][i - 1];
      sum[j][i] = sum[j][i - 1] + sum[to[j][i - 1]][i - 1];
      mins[j][i] = min(mins[j][i - 1], mins[to[j][i - 1]][i - 1]);
    }
  }
  for (long long i = 1; i <= n; i++) {
    long long u = i;
    long long s = 0, mn = 1e9;
    for (long long j = 39; j >= 0; j--) {
      if (k & (1LL << j)) {
        s += sum[u][j];
        mn = min(mn, mins[u][j]);
        u = to[u][j];
      }
    }
    cout << s << " " << mn << endl;
  }
}
