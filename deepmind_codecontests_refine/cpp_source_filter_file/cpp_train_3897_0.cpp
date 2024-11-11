#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int inf = -1e18;
long long a[maxn], f[maxn], h[maxn];
long long n, k, ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) f[i] = h[i] = inf;
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j += 2) h[j + 1] = max(h[j + 1], f[j] - a[i]);
    for (int j = 1; j <= n; j += 2) f[j + 1] = max(f[j + 1], h[j] + a[i]);
  }
  for (int i = 0; i <= 2 * k; i++) ans = max(ans, f[i]);
  cout << ans << endl;
  return 0;
}
