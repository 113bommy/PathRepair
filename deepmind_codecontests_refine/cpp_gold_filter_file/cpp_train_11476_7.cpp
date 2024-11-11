#include <bits/stdc++.h>
using namespace std;
long long n, m, k, x, t, y, z, w, ans = 1, l, md[1002], a[1002];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> x, md[x % m]++, a[x % m] = x;
  for (int i = 0; i < m; ++i) {
    if (md[i] > 1) {
      cout << 0;
      return 0;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (!md[i]) continue;
    for (int j = i + 1; j < m; ++j)
      if (md[j]) ans = (ans * (max(a[i], a[j]) - min(a[i], a[j]))) % m;
  }
  cout << ans;
}
