#include <bits/stdc++.h>
using namespace std;
int n;
int A[5][5];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    char c;
    int y;
    cin >> c >> y;
    int x;
    --x;
    if (c == 'R') x = 0;
    if (c == 'G') x = 1;
    if (c == 'B') x = 2;
    if (c == 'Y') x = 3;
    if (c == 'W') x = 4;
    A[y][x] = 1;
  }
  int ans = 10;
  for (int mask1 = 0; mask1 < (1 << 5); ++mask1)
    for (int mask2 = 0; mask2 < (1 << 5); ++mask2) {
      bool good = true;
      int bad = 0;
      for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j) {
          if (!A[i][j]) continue;
          bool vert = ((1 << i) & mask1);
          bool horiz = ((1 << j) & mask2);
          if (!vert && !horiz) ++bad;
          if (vert && horiz) continue;
          if (vert) {
            int cnt = 0;
            for (int k = 0; k < 5; ++k) {
              if (A[i][k] && !((1 << k) & mask2)) ++cnt;
            }
            if (cnt > 1) good = false;
          }
          if (horiz) {
            int cnt = 0;
            for (int k = 0; k < 5; ++k) {
              if (A[k][j] && !((1 << k) & mask1)) ++cnt;
            }
            if (cnt > 1) good = false;
          }
        }
      int cur = 0;
      for (int i = 0; i < 5; ++i) {
        if ((1 << i) & mask1) ++cur;
        if ((1 << i) & mask2) ++cur;
      }
      if (good && bad <= 1) {
        if (ans > cur) {
          ans = cur;
        }
      }
    }
  cout << ans;
  return 0;
}
