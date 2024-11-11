#include <bits/stdc++.h>
using namespace std;
int n, m, s, k, x, y, z, i, j, ans = 0;
int a[2001][2], b[2001][2];
int main() {
  memset(a, 192, sizeof a);
  memset(b, 63, sizeof b);
  cin >> n >> m >> k >> s;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      cin >> x;
      a[x][0] = max(a[x][0], i + j);
      b[x][0] = min(b[x][0], i + j);
      a[x][1] = max(a[x][1], i - j);
      b[x][1] = min(b[x][1], i - j);
    }
  for (i = 1, z, y; i <= s; i++, y = z) {
    cin >> z;
    if (i > 1)
      ans = max(ans, max(max(a[y][0] - b[z][0], a[z][0] - b[y][0]),
                         max(a[y][1] - b[z][1], a[z][1] - b[y][1])));
  }
  cout << ans << endl;
  return 0;
}
