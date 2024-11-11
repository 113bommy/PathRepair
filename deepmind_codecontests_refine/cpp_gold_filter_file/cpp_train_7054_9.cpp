#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18 + 5;
int n, k;
int a[200005];
int g[200005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  g[n] = n + 1;
  for (int i = n - 1; i >= 1; i--) {
    if (a[i + 1] != 1) {
      g[i] = i + 1;
    } else {
      g[i] = g[i + 1];
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long p = a[i];
    long long s = a[i];
    long long r = i;
    ans += (k == 1);
    while (g[r] != n + 1 && 1ll * a[g[r]] <= inf / p) {
      p *= a[g[r]];
      s += a[g[r]] + g[r] - r - 1;
      r = g[r];
      long long want = -1;
      if (p % k == 0) want = p / k;
      long long h = g[r] - r - 1;
      ans += (s <= want && want <= s + h);
    }
  }
  cout << ans;
  return 0;
}
