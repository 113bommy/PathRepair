#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  for (int j = 1; j <= n; ++j) cin >> a[j];
  for (int j = 1; j <= m; ++j) cin >> b[j];
  int po = 1;
  int ans = 0;
  b[0] = -2e9;
  for (int j = 1; j <= n; ++j) {
    while (po < m && b[po] < a[j]) ++po;
    ans = max(ans, min(abs(a[j] - b[po - 1]), abs(b[po] - a[j])));
  }
  cout << ans << endl;
  return 0;
}
