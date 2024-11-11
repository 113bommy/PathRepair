#include <bits/stdc++.h>
using namespace std;
int cnt[11][101][101];
int stars[11][101][101];
int amount(int s, int x1, int y1, int x2, int y2) {
  return cnt[s][x2][y2] - cnt[s][x1 - 1][y2] - cnt[s][x2][y1 - 1] +
         cnt[s][x1 - 1][y1 - 1];
}
int main() {
  int n, q, c;
  cin >> n >> q >> c;
  memset(stars, 0, sizeof stars);
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; i++) {
    int x, y, s;
    cin >> x >> y >> s;
    stars[s][x][y]++;
  }
  for (int s = 0; s < c; s++) {
    for (int i = 1; i <= 100; i++) {
      for (int j = 1; j <= 100; j++) {
        cnt[s][i][j] = cnt[s][i][j - 1] + cnt[s][i - 1][j] -
                       cnt[s][i - 1][j - 1] + stars[s][i][j];
      }
    }
  }
  for (int i = 0; i < q; i++) {
    int t, x1, y1, x2, y2;
    cin >> t >> x1 >> y1 >> x2 >> y2;
    int sum = 0;
    for (int p = 0; p <= c; p++) {
      sum += ((p + t) % (c + 1)) * amount(p, x1, y1, x2, y2);
    }
    cout << sum << endl;
  }
  return 0;
}
