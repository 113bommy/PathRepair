#include <bits/stdc++.h>
using namespace std;
int c[2][2];
struct info {
  int x, y;
};
const info d[4] = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int x, y;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    c[x % 4][y % 4]++;
  }
  long long ans = 0;
  for (int i = 0; i < 4; i++) {
    ans += 1ll * c[d[i].x][d[i].y] * (c[d[i].x][d[i].y] - 1) *
           (c[d[i].x][d[i].y] - 2) / 6;
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (j == i) continue;
      ans += 1ll * c[d[i].x][d[i].y] * (c[d[i].x][d[i].y] - 1) *
             c[d[j].x][d[j].y] / 2;
    }
  }
  cout << ans << endl;
  return 0;
}
