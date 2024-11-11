#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
const int M = 1e2 + 5;
const int inf = 1e18;
const int md = 1e9 + 7;
const long double eps = 0.000000001;
int n, i, j, a[N], b[N];
long long mn, ans, d[N][N];
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] -= i;
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  for (i = 1; i <= n; ++i) d[1][i] = abs(b[i] - a[1]);
  for (i = 2; i <= n; ++i) {
    mn = inf;
    for (j = 1; j <= n; ++j) {
      mn = min(1ll * mn, 1ll * d[i - 1][j]);
      d[i][j] = mn + abs(b[j] - a[i]);
    }
  }
  ans = inf;
  for (i = 1; i <= n; ++i) ans = min(1ll * ans, 1ll * d[n][i]);
  cout << ans;
}
