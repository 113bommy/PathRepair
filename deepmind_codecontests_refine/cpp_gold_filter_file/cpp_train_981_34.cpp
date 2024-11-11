#include <bits/stdc++.h>
using namespace std;
int const LIM = 2100;
int n, m, k;
char g[LIM][LIM];
int check(int x, int y, int time) {
  int res = 0;
  int x1 = x - time, y1 = y;
  if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && g[x1][y1] == 'D') ++res;
  x1 = x + time;
  y1 = y;
  if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && g[x1][y1] == 'U') ++res;
  x1 = x;
  y1 = y - time;
  if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && g[x1][y1] == 'R') ++res;
  x1 = x;
  y1 = y + time;
  if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && g[x1][y1] == 'L') ++res;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
    }
  }
  for (int i = 0; i < m; ++i) {
    int ans = 0;
    for (int j = 0; j < n; ++j) ans += check(j, i, j);
    cout << ans << ' ';
  }
  cout << endl;
  return 0;
}
