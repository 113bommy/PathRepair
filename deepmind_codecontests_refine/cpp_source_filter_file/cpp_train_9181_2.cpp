#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2e5 + 17;
int a[SIZE], bst[SIZE];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n, m;
  cin >> t;
  for (int _ = 0; _ < t; _++) {
    cin >> n;
    int ans = 0, won = 0;
    for (int i = 0; i < n; i++) bst[i] = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
      int t1, t2;
      cin >> t1 >> t2;
      bst[t2] = max(bst[t2], t1);
    }
    for (int i = n - 1; i >= 0; i--) bst[i] = max(bst[i], bst[i + 1]);
    while (won < n) {
      int best = 0, mx = 0;
      while (true) {
        mx = max(mx, a[won + best]);
        if (bst[best + 1] >= mx)
          best++;
        else
          break;
      }
      if (best == 0) {
        ans = -1;
        break;
      }
      won += best;
      ans++;
    }
    cout << ans << endl;
  }
}
