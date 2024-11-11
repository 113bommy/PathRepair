#include <bits/stdc++.h>
using namespace std;
const int N = 105, mod = int(1e9) + 7;
int n, m, k;
int a[N][N];
int ans;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  ans = k + 1;
  if (n <= k) {
    int x = 0, y = 0;
    int cur = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
      cur = 0;
      for (int j = 0; j < m; j++) {
        x = y = 0;
        for (int i = 0; i < n; i++) {
          if (a[i][j] == ((mask & (1 << i)) > 0))
            x++;
          else
            y++;
        }
        cur += min(x, y);
      }
      ans = min(ans, cur);
    }
  } else {
    int x, y, cur;
    for (int p = 0; p < n; p++) {
      cur = 0;
      for (int i = 0; i < n; i++) {
        x = 0;
        y = 0;
        for (int j = 0; j < m; j++) {
          if (a[i][j] == a[p][j])
            x++;
          else
            y++;
        }
        cur += min(x, y);
      }
      ans = min(ans, cur);
    }
  }
  if (ans > k) ans = -1;
  cout << ans;
  return 0;
}
