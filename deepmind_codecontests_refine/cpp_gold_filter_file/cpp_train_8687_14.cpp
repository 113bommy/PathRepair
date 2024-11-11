#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> v(m);
  for (int i = 0; i < m; i++) cin >> v[i];
  int fedor, ans = 0;
  cin >> fedor;
  for (int i = 0; i < m; i++) {
    int xord = fedor ^ v[i], diff = 0, cnt = 1;
    while (xord != 0 && cnt <= n) {
      if (xord % 2) diff++;
      xord >>= 1;
      cnt++;
    }
    if (diff <= k) ans++;
  }
  cout << ans;
  return 0;
}
