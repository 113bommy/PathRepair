#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e2 + 7;
const int MOD = 1e9 + 7;
int t;
int n, m, k;
char s[MAX][MAX];
char chk(int x1, int y1, int x2, int y2) {
  vector<int> vis(4);
  if (s[x1 - 1][y1]) vis[s[x1 - 1][y1] - 'a'] = 1;
  if (s[x1][y1 - 1]) vis[s[x1][y1 - 1] - 'a'] = 1;
  if (s[x2 - 1][y2]) vis[s[x2 - 1][y2] - 'a'] = 1;
  if (s[x2][y2 - 1]) vis[s[x2][y2 - 1] - 'a'] = 1;
  for (int i = 0; i < 4; i++)
    if (!vis[i]) return i + 'a';
}
void solve(int x, int y, int num1, int num2) {
  for (int i = x; i <= n; i += 2) {
    for (int j = y; j <= m; j += 2) {
      if (num1) {
        s[i][j] = s[i][j + 1] = chk(i, j, i, j + 1);
        s[i + 1][j] = s[i + 1][j + 1] = chk(i + 1, j, i + 1, j + 1);
        num1 -= 2;
      } else {
        s[i][j] = s[i + 1][j] = chk(i, j, i + 1, j);
        s[i][j + 1] = s[i + 1][j + 1] = chk(i, j + 1, i + 1, j + 1);
        num2 -= 2;
      }
    }
  }
  for (int i = 1; i <= n; i++) cout << s[i] + 1 << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  cin >> t;
  while (t--) {
    memset(s, 0, sizeof(s));
    cin >> n >> m >> k;
    int p = (n * m - 2 * k) / 2;
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0 && p % 2 == 0) {
        cout << "YES" << '\n';
        solve(1, 1, k, p);
      } else
        cout << "NO" << '\n';
    } else if (n % 2 == 1) {
      if (k >= m / 2 && (k - m / 2) % 2 == 0) {
        cout << "YES" << '\n';
        for (int i = 1; i <= m; i += 2)
          s[1][i] = s[1][i + 1] = chk(1, i, 1, i + 1);
        solve(2, 1, k - m, p);
      } else
        cout << "NO" << '\n';
    } else {
      if (p >= n / 2 && (p - n / 2) % 2 == 0) {
        cout << "YES" << '\n';
        for (int i = 1; i <= n; i += 2)
          s[i][1] = s[i + 1][1] = chk(i, 1, i + 1, 1);
        solve(1, 2, k, p - n);
      } else
        cout << "NO" << '\n';
    }
  }
  return 0;
}
