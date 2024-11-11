#include <bits/stdc++.h>
using namespace std;
const long long mod = (1e9) + 7;
char ans[105][105];
char pickcolor(int x, int y, int hor, int n, int m) {
  set<char> s;
  for (int i = 0; i < 7; i++) {
    s.insert((char)(i + 'a'));
  }
  if (hor == 1) {
    if (x > 0) {
      if (s.count(ans[x - 1][y])) s.erase(ans[x - 1][y]);
      if (s.count(ans[x - 1][y + 1])) s.erase(ans[x - 1][y + 1]);
    }
    if (x < n - 1) {
      if (s.count(ans[x + 1][y])) s.erase(ans[x + 1][y]);
      if (s.count(ans[x + 1][y + 1])) s.erase(ans[x + 1][y + 1]);
    }
    if (y > 0) {
      if (s.count(ans[x][y - 1])) s.erase(ans[x][y - 1]);
    }
    if (y < m - 2) {
      if (s.count(ans[x][y + 2])) s.erase(ans[x][y + 2]);
    }
    for (auto xx : s) {
      return xx;
    }
  } else {
    if (y > 0) {
      if (s.count(ans[x][y - 1])) s.erase(ans[x][y - 1]);
      if (s.count(ans[x + 1][y - 1])) s.erase(ans[x + 1][y - 1]);
    }
    if (y < m - 1) {
      if (s.count(ans[x][y + 1])) s.erase(ans[x][y + 1]);
      if (s.count(ans[x + 1][y + 1])) s.erase(ans[x + 1][y + 1]);
    }
    if (x > 0) {
      if (s.count(ans[x - 1][y])) s.erase(ans[x - 1][y]);
    }
    if (x < n - 2) {
      if (s.count(ans[x + 2][y])) s.erase(ans[x + 2][y]);
    }
    for (auto xx : s) {
      return xx;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int tmp = (n * m - 2 * k) / 2;
    if ((m / 2) * n >= k && ((m / 2) * n - k) % 2 == 0 && (n / 2) * m >= tmp &&
        ((n / 2) * m - tmp) % 2 == 0) {
      cout << "YES\n";
      int cur = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          ans[i][j] = '0';
        }
      }
      int x = 0, y = 0;
      if (n % 2 == 0) {
        for (int i = 0; i < k; i++) {
          ans[x][y] = ans[x][y + 1] = pickcolor(x, y, 1, n, m);
          x++;
          if (x >= n) {
            x = 0;
            y += 2;
          }
        }
      } else {
        int i = 0;
        for (; i < k; i++) {
          ans[x][y] = ans[x][y + 1] = pickcolor(x, y, 1, n, m);
          y += 2;
          if (y >= m) {
            y = 0;
            x += 1;
            i++;
            break;
          }
        }
        for (; i < k; i++) {
          ans[x][y] = ans[x][y + 1] = pickcolor(x, y, 1, n, m);
          x++;
          if (x >= n) {
            x = 1;
            y += 2;
          }
        }
      }
      for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
          if (ans[i][j] == '0' && ans[i + 1][j] == '0') {
            ans[i][j] = ans[i + 1][j] = pickcolor(i, j, 0, n, m);
          }
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << ans[i][j];
        }
        cout << '\n';
      }
    } else
      cout << "NO\n";
  }
  return 0;
}
