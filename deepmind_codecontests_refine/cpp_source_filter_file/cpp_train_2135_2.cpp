#include <bits/stdc++.h>
using namespace std;
long long t, n, k, i, j, a[5][104] = {0}, first, second, f = 0, visi[5][104];
void dfs(long long first, long long second) {
  if (visi[first][second] || a[first][second] == 0) return;
  visi[first][second] = 1;
  if (second == n) {
    f = 1;
    return;
  }
  if (f) return;
  if (a[first][second + 1] && a[first][second + 2] && a[first][second + 3])
    dfs(first, second + 3);
  if (f) return;
  if (a[first - 1][second + 1] && a[first - 1][second + 2] &&
      a[first - 1][second + 3] && a[first][second + 1])
    dfs(first - 1, second + 3);
  if (f) return;
  if (a[first + 1][second + 1] && a[first + 1][second + 2] &&
      a[first + 1][second + 3] && a[first][second + 1])
    dfs(first + 1, second + 3);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  string s;
  while (t--) {
    cin >> n >> k;
    memset(a, 0, sizeof(a));
    memset(visi, 0, sizeof(visi));
    for (i = 1; i < 4; ++i)
      for (j = 1; j <= n; ++j) a[i][j] = 1;
    for (i = 1; i <= 3; ++i) {
      cin >> s;
      for (j = 1; j <= n; ++j)
        if (s[j - 1] != 's')
          a[i][j] = !isalpha(s[j - 1]);
        else
          first = i, second = j, a[i][j] = 1;
    }
    f = 0;
    dfs(first, second);
    if (f)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
