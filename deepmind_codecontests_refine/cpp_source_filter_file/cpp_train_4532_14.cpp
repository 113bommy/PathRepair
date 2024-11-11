#include <bits/stdc++.h>
using namespace std;
template <class T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
int r, c, k, n, a[15][15];
int main() {
  scanf("%d%d%d%d", &r, &c, &k, &n);
  for (int i = (1); i <= (n); ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x][y] = 1;
  }
  int ans = 0;
  for (int x1 = (1); x1 <= (r); ++x1) {
    for (int y1 = (1); y1 <= (c); ++y1) {
      for (int x2 = (x1); x2 <= (r); ++x2) {
        for (int y2 = (y1); y2 <= (c); ++y2) {
          int sum = 0;
          for (int x = (x1); x <= (x2); ++x) {
            for (int y = (y1); y <= (y2); ++y) sum += a[x][y];
          }
          if (sum >= k) ++ans;
        }
      }
    }
  }
  cout << ans;
  return 0;
}
