#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void umax(T &x, T y) {
  if (y > x) x = y;
}
template <class T>
inline void umin(T &x, T y) {
  if (y < x) x = y;
}
int d[20][20];
int main() {
  int r, c, n, k, x, y, ans = 0;
  cin >> r >> c >> n >> k;
  for (int i = 1; i <= n; i++) cin >> x >> y, d[x][y] = 1;
  for (int i = 1; i <= r; i++)
    for (int j = 2; j <= c; j++) d[i][j] += d[i][j - 1];
  for (int j = 1; j <= c; j++)
    for (int i = 2; i <= r; i++) d[i][j] += d[i - 1][j];
  for (int i = r; i >= 1; i--) {
    for (int j = c; j >= 1; j--) {
      for (int s = 1; s <= r; s++) {
        for (int t = 1; t <= c; t++) {
          int l = ((d[i][j] - d[s - 1][j]) - d[i][t - 1]) + d[s - 1][t - 1];
          if (l >= k) ans++;
        }
      }
    }
  }
  cout << ans << endl;
}
