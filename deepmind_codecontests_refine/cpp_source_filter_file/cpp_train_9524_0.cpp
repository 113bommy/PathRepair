#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
const int MN = 55;
string s[MN];
bool ok[MN][MN];
char ans[MN << 1][MN << 1];
int n;
int dx, dy;
bool valid(int r, int c) { return max(r, c) < n && min(r, c) >= 0; }
bool check() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (s[i][j] == 'o' && valid(i + dx, j + dy) && s[i + dx][j + dy] == '.')
        return false;
  return true;
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  int Sz = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (int j = 0; j < n; ++j)
      if (s[i][j] == 'x') ++Sz;
  }
  dx = 2, dy = 2;
  for (int i = 0; i < 2 * n; ++i) fill(ans[i], ans[i] + 2 * n, '.');
  ans[n - 1][n - 1] = 'o';
  for (int i = 0; i < 2 * n - 1; ++i)
    for (int j = 0; j < 2 * n - 1; ++j) {
      if (i == n - 1 && j == n - 1) continue;
      dx = i - n + 1, dy = j - n + 1;
      if (check()) {
        for (int i1 = 0; i1 < n; ++i1)
          for (int j1 = 0; j1 < n; ++j1)
            if (s[i1][j1] == 'o' && valid(i1 + dx, j1 + dy) &&
                !ok[i1 + dx][j1 + dy] && s[i1 + dx][i1 + dy] == 'x')
              ok[i1 + dx][j1 + dy] = true, --Sz;
        ans[i][j] = 'x';
      }
    }
  if (Sz) return cout << "NO\n", 0;
  cout << "YES\n";
  for (int i = 0; i < 2 * n - 1; ++i) {
    for (int j = 0; j < 2 * n - 1; ++j) cout << ans[i][j];
    cout << '\n';
  }
  return 0;
}
