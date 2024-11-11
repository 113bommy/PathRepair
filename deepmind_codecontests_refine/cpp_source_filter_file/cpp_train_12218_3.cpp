#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int n, m, a[N][N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      a[i][j] = (c == '1') ? 1 : 0;
    }
  int res = 0;
  for (int hi = 0; hi < n; ++hi) {
    for (int hj = n - 1; hj >= hi; --hj) {
      for (int wi = 0; wi <= m; ++wi) {
        for (int wj = m - 1; wj > wi; --wj) {
          int ok = 1;
          for (int i = hi; i <= hj; ++i) {
            for (int j = wi; j <= wj; ++j) {
              if (a[i][j]) {
                ok = 0;
                break;
              }
            }
            if (!ok) break;
          }
          if (ok) {
            res = max(res, (hj - hi + 1) * 2 + (wj - wi + 1) * 2);
          }
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}
