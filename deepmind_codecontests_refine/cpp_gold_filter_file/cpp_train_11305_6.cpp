#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, k, ans[110][110], x, y, r, rc, j;
int main() {
  cin >> n >> k;
  if (k > n * n) {
    cout << -1 << endl;
    return 0;
  }
  if (k >= 1) {
    ans[y][y] = 1;
    k--;
  }
  x++;
  while (k > 0) {
    if (k % 2 != 0 || r < y) {
      r++;
      ans[r][r] = 1;
      k--;
      continue;
    } else if (x == n) {
      y++;
      x = y + 1;
    } else if (k % 2 == 0) {
      ans[x][y] = 1;
      ans[y][x] = 1;
      k -= 2;
      x++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << ans[i][j] << " ";
    cout << endl;
  }
}
