#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using P = pair<int, int>;
const int MAX = 1e6 + 50;
const int inf = 0x3f3f3f3f;
const LL mod = 998244353;
void file_read() {}
int n, m, k;
char ans[105][105];
void mark(int i, int j, bool vis[]) {
  if (i >= 0 and j >= 0 and i < n and j < m) {
    vis[ans[i][j] - 'a'] = 1;
  }
}
int main() {
  int T;
  file_read();
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    memset(ans, 0, sizeof(ans));
    if (n % 2 == 0) {
      if (k % 2 == 0 and k <= n * (m / 2)) {
        cout << "YES"
             << "\n";
        for (int i = 0; i < n; i += 2) {
          for (int j = 0; j < m; j++) {
            ans[i][j] = ans[i + 1][j] = 'a' + (((i / 2) + j) % 26);
          }
        }
        if (k > 0)
          for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < m; j += 2) {
              bool vis[26] = {0};
              mark(i - 1, j, vis);
              mark(j - 1, j + 1, vis);
              mark(i, j - 1, vis);
              mark(i, j + 2, vis);
              mark(i + 1, j - 1, vis);
              mark(i + 1, j + 2, vis);
              mark(i + 2, j, vis);
              mark(i + 2, j + 1, vis);
              for (int t = 0, r = 2; t < 26 and r > 0; t++) {
                if (!vis[t]) {
                  r--;
                  if (r == 1) ans[i][j] = ans[i][j + 1] = 'a' + t;
                  if (r == 0) ans[i + 1][j] = ans[i + 1][j + 1] = 'a' + t;
                  vis[t] = 1;
                }
              }
              k -= 2;
              if (k == 0) break;
            }
            if (k == 0) break;
          }
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) cout << ans[i][j];
          puts("");
        }
      } else
        cout << "NO"
             << "\n";
    } else {
      if (k >= m / 2 and (k - m / 2) % 2 == 0 and k <= n * (m / 2)) {
        cout << "YES"
             << "\n";
        for (int i = 1; i < n; i += 2) {
          for (int j = 0; j < m; j++) {
            ans[i][j] = ans[i + 1][j] = 'a' + (((i / 2) + j) % 26);
          }
        }
        for (int i = 0; i < m; i += 2) {
          bool vis[26] = {0};
          mark(0, i - 1, vis);
          mark(1, i, vis);
          mark(1, i + 1, vis);
          for (int t = 0; t < 26; t++) {
            if (!vis[t]) {
              ans[0][i] = ans[0][i + 1] = 'a' + t;
              k--;
              break;
            }
          }
        }
        if (k > 0)
          for (int i = 1; i < n; i += 2) {
            for (int j = 0; j < m; j += 2) {
              bool vis[26] = {0};
              mark(i - 1, j, vis);
              mark(j - 1, j + 1, vis);
              mark(i, j - 1, vis);
              mark(i, j + 2, vis);
              mark(i + 1, j - 1, vis);
              mark(i + 1, j + 2, vis);
              mark(i + 2, j, vis);
              mark(i + 2, j + 1, vis);
              for (int t = 0, r = 2; t < 26 and r > 0; t++) {
                if (!vis[t]) {
                  r--;
                  if (r == 1) ans[i][j] = ans[i][j + 1] = 'a' + t;
                  if (r == 0) ans[i + 1][j] = ans[i + 1][j + 1] = 'a' + t;
                  vis[t] = 1;
                }
              }
              k -= 2;
              if (k == 0) break;
            }
            if (k == 0) break;
          }
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) cout << ans[i][j];
          puts("");
        }
      } else
        cout << "NO"
             << "\n";
    }
  }
}
