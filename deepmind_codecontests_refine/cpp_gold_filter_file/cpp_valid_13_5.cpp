#include <bits/stdc++.h>
using namespace std;
int n, m, k, a, b, num[110][110], cur;
int ans[110][110];
void solve() {
  cin >> n >> m >> k;
  if (n % 2 == 0)
    a = 0;
  else
    a = m / 2;
  b = n * m / 2;
  if (m % 2 == 1) b -= n / 2;
  if (k >= a && k <= b && ((k - a) & 1) == 0) {
    cout << "YES\n";
    cur = 0;
    if (n & 1) {
      for (int i = 0; i < m; i += 2) {
        num[n - 1][i] = num[n - 1][i + 1] = cur++;
        k--;
      }
    }
    if (m & 1) {
      for (int i = 0; i < n; i += 2) {
        num[i][m - 1] = num[i + 1][m - 1] = cur++;
      }
    }
    for (int i = 0; i < n / 2 * 2; i += 2) {
      for (int j = 0; j < m / 2 * 2; j += 2) {
        if (k) {
          k -= 2;
          num[i][j] = num[i][j + 1] = cur++;
          num[i + 1][j] = num[i + 1][j + 1] = cur++;
        } else {
          num[i][j] = num[i + 1][j] = cur++;
          num[i][j + 1] = num[i + 1][j + 1] = cur++;
        }
      }
    }
    for (int i = 0; i <= n - 1; i++)
      for (int j = 0; j <= m - 1; j++) ans[i][j] = -1;
    for (int i = 0; i <= n - 1; i++) {
      for (int j = 0; j <= m - 1; j++) {
        if (ans[i][j] != -1) continue;
        if (i != n - 1 && num[i][j] == num[i + 1][j]) {
          for (int t = 0; t <= 26 - 1; t++) {
            if (i && t == ans[i - 1][j]) continue;
            if (j && t == ans[i][j - 1]) continue;
            if (j && t == ans[i + 1][j - 1]) continue;
            if (j != m - 1 && t == ans[i][j + 1]) continue;
            ans[i][j] = ans[i + 1][j] = t;
            break;
          }
        } else {
          for (int t = 0; t <= 26 - 1; t++) {
            if (i && t == ans[i - 1][j]) continue;
            if (i && t == ans[i - 1][j + 1]) continue;
            if (j && t == ans[i][j - 1]) continue;
            if (j != m - 2 && t == ans[i][j + 2]) continue;
            ans[i][j] = ans[i][j + 1] = t;
            break;
          }
        }
      }
    }
    for (int i = 0; i <= n - 1; i++) {
      for (int j = 0; j <= m - 1; j++) cout << char('a' + ans[i][j]);
      cout << endl;
    }
  } else
    cout << "NO\n";
}
int main() {
  int T;
  T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
