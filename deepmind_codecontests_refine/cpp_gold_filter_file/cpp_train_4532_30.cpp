#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, c, n, k;
  cin >> r >> c >> n >> k;
  int a[r + 1][c + 1];
  for (int i = 0; i <= r; i++) {
    for (int j = 0; j <= c; j++) {
      a[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a[x][y] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      for (int i1 = i; i1 <= r; i1++) {
        for (int j1 = j; j1 <= c; j1++) {
          int cur = 0;
          for (int q = i; q <= i1; q++) {
            for (int w = j; w <= j1; w++) {
              cur += a[q][w];
            }
          }
          if (cur >= k) {
            ans++;
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}
