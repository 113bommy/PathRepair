#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005][1005], x;
bool dd[105][105][1005];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> x;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c, a[i][j] = c - '0';
    }
  for (int i = 1; i <= m; i++) dd[n][i][a[n][i]] = 1;
  for (int i = n; i > 1; i--)
    for (int j = 1; j <= m; j++)
      for (int k = 0; k < 1004; k++)
        if (dd[i][j][k]) {
          if (j > 1) dd[i - 1][j - 1][(k + a[i - 1][j - 1])] = 1;
          if (j < m) dd[i - 1][j + 1][(k + a[i - 1][j + 1])] = 1;
        }
  int ans = -1, bd;
  for (int i = 1; i <= m; i++)
    for (int j = 1000; j > 0; j--)
      if (dd[1][i][j] && j % (x + 1) == 0 && ans < j) {
        ans = j;
        bd = i;
        break;
      }
  cout << ans << "\n";
  if (ans < 0) return 0;
  string s = "";
  for (int i = 1; i < n; i++) {
    ans -= a[i][bd];
    if (bd > 1 && dd[i + 1][bd - 1][ans]) {
      bd--, s += 'R';
      continue;
    }
    if (bd < m && dd[i + 1][bd + 1][ans]) bd++, s += 'L';
  }
  reverse(s.begin(), s.end());
  cout << bd << '\n' << s;
  return 0;
}
