#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n + 1], b[m + 2];
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) cin >> b[i];
  int it = 1, ans = 0;
  b[m + 1] = 0;
  for (int i = 1; i <= n; ++i) {
    if (b[it] >= a[i]) ++ans, ++it;
  }
  cout << ans;
  return 0;
}
