#include <bits/stdc++.h>
using namespace std;
const int maxn = 1100;
char ans[maxn][maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int tot = n * m / 2;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) ans[i][j] = '#';
    int nn = n, mm = m;
    if (n % 2) {
      k -= m / 2;
      tot -= m / 2;
      if (k < 0) {
        cout << "NO\n";
        continue;
      }
      int cnt = 1;
      for (int j = 1; j <= m; j += 2) {
        if (cnt % 2)
          ans[n][j] = ans[n][j + 1] = 's';
        else
          ans[n][j] = ans[n][j + 1] = 't';
        cnt++;
      }
      n--;
    }
    if (m % 2) {
      tot -= n / 2;
      int cnt = 1;
      for (int i = 1; i <= n; i += 2) {
        if (cnt % 2)
          ans[i][m] = ans[i + 1][m] = 'x';
        else
          ans[i][m] = ans[i + 1][m] = 'y';
        cnt++;
      }
      m--;
    }
    if (k % 2 || k > tot) {
      cout << "NO\n";
      continue;
    }
    for (int j = 1; j <= m && k; j += 2) {
      for (int i = 1; i <= n && k; i++) {
        if (k) {
          if ((i + j) & 1)
            ans[i][j] = ans[i][j + 1] = 'a';
          else
            ans[i][j] = ans[i][j + 1] = 'b';
          k--;
        }
      }
    }
    for (int i = 1; i <= n; i += 2) {
      for (int j = 1; j <= m; j++) {
        if (ans[i][j] == '#') {
          if ((j + i) & 1)
            ans[i][j] = ans[i + 1][j] = 'i';
          else
            ans[i][j] = ans[i + 1][j] = 'j';
        }
      }
    }
    cout << "YES\n";
    for (int i = 1; i <= nn; i++) {
      for (int j = 1; j <= mm; j++) cout << ans[i][j];
      cout << '\n';
    }
  }
}
