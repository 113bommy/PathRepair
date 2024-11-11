#include <bits/stdc++.h>
using namespace std;
bool ok = false;
int a[15][15];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int r, c, n, k, sum, ans = 0, x, y;
  cin >> r >> c >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    a[x][y] = 1;
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      for (int t = i; t < r; t++) {
        for (int l = j; l < c; l++) {
          sum = 0;
          for (int t1 = i; t1 <= t; t1++) {
            for (int t2 = j; t2 <= l; t2++) {
              sum += a[t1][t2];
            }
          }
          if (sum >= k) ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
