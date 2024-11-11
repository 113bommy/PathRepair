#include <bits/stdc++.h>
using namespace std;
int i, j, k, l, n, m, a[110][110], ans[110];
pair<int, int> fix[110];
int main() {
  cin >> n >> m >> k;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) cin >> a[j][i];
  }
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) {
      if (a[i][j] == 0) continue;
      if (ans[j] != 0) continue;
      if (fix[a[i][j]].first == 0) {
        fix[a[i][j]] = make_pair(j, i);
      } else {
        if (fix[a[i][j]].first == -1)
          ans[j] = i;
        else {
          ans[fix[a[i][j]].first] = fix[a[i][j]].second;
          ans[j] = i;
          fix[a[i][j]].first = -1;
        }
      }
    }
    for (j = 1; j <= 101; j++) {
      if (fix[j].first != -1) fix[j] = make_pair(0, 0);
    }
  }
  for (i = 1; i <= 101; i++) cout << ans[i] << endl;
}
