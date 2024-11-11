#include <bits/stdc++.h>
using namespace std;
const int N = 300;
const int inf = 1000000000;
int n, m, k;
int a[N][N], line[N];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  int ans = k + 1;
  if (n <= 10) {
    for (int mask = 0; mask < (1 << n); mask++) {
      for (int j = 0; j < n; j++)
        if (mask & (1 << j))
          line[j + 1] = 1;
        else
          line[j + 1] = 0;
      int res = 0;
      for (int j = 1; j <= m; j++) {
        int r1 = 0, r2 = 0;
        for (int i = 1; i <= n; i++)
          if (a[i][j] != line[j]) r1++;
        for (int i = 1; i <= n; i++)
          if (a[i][j] == line[j]) r2++;
        res += min(r1, r2);
      }
      ans = min(ans, res);
    }
    if (ans > k) ans = -1;
    cout << ans;
    return 0;
  }
  for (int cur = 1; cur <= n; cur++) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
      int r1 = 0, r2 = 0;
      for (int j = 1; j <= m; j++)
        if (a[i][j] != a[cur][j]) r1++;
      for (int j = 1; j <= m; j++)
        if (a[i][j] == a[cur][j]) r2++;
      res += min(r1, r2);
    }
    ans = min(ans, res);
  }
  if (ans > k) ans = -1;
  cout << ans;
  return 0;
}
