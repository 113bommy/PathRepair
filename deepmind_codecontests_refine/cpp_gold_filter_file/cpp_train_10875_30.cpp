#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-5;
int grid[51][51];
int main(void) {
  int n, m;
  cin >> n >> m;
  for (int y = (0); y < (int)(n); ++y)
    for (int x = (0); x < (int)(m); ++x) cin >> grid[y][x];
  int a, b;
  cin >> a >> b;
  int ans = INT_MAX;
  for (int y = (0); y < (int)(n - a + 1); ++y)
    for (int x = (0); x < (int)(m - b + 1); ++x) {
      int tmp = 0;
      for (int dy = (0); dy < (int)(a); ++dy)
        for (int dx = (0); dx < (int)(b); ++dx) {
          if (grid[y + dy][x + dx]) tmp++;
          if (tmp > ans) break;
        }
      ans = min(ans, tmp);
    }
  for (int y = (0); y < (int)(n - b + 1); ++y)
    for (int x = (0); x < (int)(m - a + 1); ++x) {
      int tmp = 0;
      for (int dy = (0); dy < (int)(b); ++dy)
        for (int dx = (0); dx < (int)(a); ++dx) {
          if (grid[y + dy][x + dx]) tmp++;
          if (tmp > ans) break;
        }
      ans = min(ans, tmp);
    }
  cout << ans << endl;
  return 0;
}
