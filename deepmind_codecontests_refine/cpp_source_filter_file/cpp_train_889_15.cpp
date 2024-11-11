#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000], x, y, s, ans;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    for (int j = x; j <= y; j++) s += j;
    ans += max(0, s);
    s = 0;
  }
  cout << ans;
  return 0;
}
