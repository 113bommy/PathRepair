#include <bits/stdc++.h>
using namespace std;
int i, j, n, m, k, t, w;
int ans;
string s[50];
int p[50];
void dfs(int x, int y, string ss) {
  if (x == n) {
    if (y < p[1]) return;
    for (i = 1; i <= m; i++) {
      int cnt = 0;
      for (j = 0; j <= n - 1; j++) cnt += (ss[j] == s[i][j]);
      if (cnt != p[i]) return;
    }
    ans++;
    return;
  }
  if (y < p[1]) dfs(x + 1, y + 1, ss + s[1][x]);
  dfs(x + 1, y, ss + char('0' + '1' - s[1][x]));
}
int main() {
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> s[i] >> p[i];
  }
  dfs(0, 0, "");
  cout << ans;
}
