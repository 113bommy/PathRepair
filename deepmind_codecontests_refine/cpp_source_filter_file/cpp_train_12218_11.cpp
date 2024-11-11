#include <bits/stdc++.h>
using namespace std;
int pref[25][25];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) pref[i][j] = s[j] == '1';
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      pref[i][j] += (i > 0 ? pref[i - 1][j] : 0) +
                    (j > 0 ? pref[i][j - 1] : 0) -
                    (i > 0 && j > 0 ? pref[i - 1][j - 1] : 0);
  int ans = 0;
  for (int i1 = 0; i1 < n; i1++)
    for (int j1 = 0; j1 < m; j1++)
      for (int i2 = i1; i2 < n; i2++)
        for (int j2 = 0; j2 < m; j2++)
          if (pref[i2][j2] - (i1 == 0 ? 0 : pref[i1 - 1][j2]) -
                  (j1 == 0 ? 0 : pref[i2][j1 - 1]) +
                  (i1 > 0 && j1 > 0 ? pref[i1 - 1][j1 - 1] : 0) ==
              0)
            ans = max(ans, 2 * (i2 - i1 + 1 + j2 - j1 + 1));
  cout << ans;
}
