#include <bits/stdc++.h>
using namespace std;
char grid[101][10001];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> grid[i];
  int pos = 0, ori = 1;
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    int left = pos, right = pos;
    while (true) {
      if ((left < 0 || grid[i][left] == '#') &&
          (right >= m || grid[i][right] == '#')) {
        cout << "Never" << endl;
        return 0;
      }
      bool fall = false;
      if (ori) {
        while (right < m && grid[i][right] == '.') {
          if (grid[i + 1][right] == '.') {
            fall = true;
            break;
          }
          right++;
        }
        if (fall) {
          ans += right - pos + 1;
          pos = right;
          break;
        }
        ans += right - pos;
        pos = right - 1;
        if (grid[i][right] == '+') grid[i][right] = '.';
      } else {
        while (left >= 0 && grid[i][left] == '.') {
          if (grid[i + 1][left] == '.') {
            fall = true;
            break;
          }
          left--;
        }
        if (fall) {
          ans += pos - left + 1;
          pos = left;
          break;
        }
        ans += pos - left;
        pos = left + 1;
        if (grid[i][left] == '+') grid[i][left] = '.';
      }
      ori = !ori;
    }
  }
  cout << ans << endl;
  return 0;
}
