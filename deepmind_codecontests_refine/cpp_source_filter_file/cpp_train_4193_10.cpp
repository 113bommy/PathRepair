#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long t, n, m, ans;
int g[103][103];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        if (s[j] == 'D') g[i][j] = 1;
        if (s[j] == 'R') g[i][j] = 2;
        if (s[j] == 'C') g[i][j] = 3;
      }
    }
    for (int i = 0; i < m - 1; i++) {
      if (g[0][i] == 1) ans++;
    }
    for (int i = 0; i < n - 1; i++) {
      if (g[i][m - 1] == 2) ans++;
    }
    cout << ans << '\n';
    ans = 0;
  }
}
