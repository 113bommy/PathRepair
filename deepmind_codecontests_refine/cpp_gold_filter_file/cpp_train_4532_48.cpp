#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int r, c, n, k, x, y, a[100][100];
  cin >> r >> c >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> x >> y;
    a[x][y] = 1;
  }
  int otv = 0;
  for (int x1 = 1; x1 <= r; ++x1)
    for (int x2 = x1; x2 <= r; ++x2)
      for (int y1 = 1; y1 <= c; ++y1)
        for (int y2 = y1; y2 <= c; ++y2) {
          int kil = 0;
          for (int i = x1; i <= x2; ++i)
            for (int j = y1; j <= y2; ++j)
              if (a[i][j] == 1) ++kil;
          if (kil >= k) ++otv;
        }
  cout << otv;
  return 0;
}
