#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, i, j, k, ans, white, black, x, x1, y1, x2, y2;
  cin >> n;
  vector<vector<long long>> a(n, vector<long long>(n));
  vector<long long> sx(n * 2 + 10, 0), sy(n * 2 + 10, 0);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> a[i][j];
      sx[i + j] += a[i][j];
      sy[j - i + n] += a[i][j];
    }
  }
  white = 0;
  black = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      x = sx[i + j] + sy[j - i + n] - a[i][j];
      if ((i + j) % 2 == 0) {
        if (x >= white) {
          white = max(white, x);
          x1 = i;
          y1 = j;
        }
      } else {
        if (x >= black) {
          black = max(black, x);
          x2 = i;
          y2 = j;
        }
      }
    }
  }
  ans = white + black;
  cout << ans << "\n";
  cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << "\n";
  return 0;
}
