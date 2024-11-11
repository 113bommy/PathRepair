#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e3;
const int maxc = 1e6 + 100;
int f[maxc + 10];
int a[maxn], b[maxn], c[maxn], d[maxn];
int n, m;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> c[i] >> d[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x = c[j] - a[i];
      if (x >= 0) f[x] = max(f[x], d[j] - b[i] + 1);
    }
  }
  for (int i = maxc; i >= 0; i--) {
    f[i] = max(f[i], f[i + 1]);
  }
  int ans = INT_MAX;
  for (int i = 0; i <= maxc; i++) {
    ans = min(ans, i + f[i]);
  }
  cout << ans;
  return 0;
}
