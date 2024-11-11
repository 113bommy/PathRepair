#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
char a[maxn][maxn];
int n, m;
void enter() {
  cin >> n >> m;
  for (int i = (1), _b = (n + 1); i < _b; ++i)
    for (int j = (1), _b = (m + 1); j < _b; ++j) cin >> a[i][j];
}
int f[maxn][maxn];
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const char col[5] = {'.', 'a', 'b', 'c', 'd'};
int c[maxn * maxn];
bool ct[maxn * maxn][5];
bool in_bound(int xx, int yy) {
  if (xx > 0 && xx <= n && yy > 0 && yy <= m)
    return true;
  else
    return false;
}
bool possible() {
  int B = 0, W = 0;
  for (int i = (1), _b = (n + 1); i < _b; ++i)
    for (int j = (1), _b = (m + 1); j < _b; ++j) {
      if (a[i][j] == 'b')
        ++B;
      else if (a[i][j] == 'w')
        ++W;
    }
  if (W == B * 2)
    return true;
  else
    return false;
}
void solve() {
  int cnt = 1;
  for (int i = (1), _b = (n + 1); i < _b; ++i)
    for (int j = (1), _b = (m + 1); j < _b; ++j)
      if (a[i][j] == 'b') {
        if (i == 1 || i == n || a[i - 1][j] == '.' || f[i - 1][j] != 0 ||
            a[i + 1][j] == '.' || f[i + 1][j] != 0) {
          if (j > 1 && j < m && a[i][j - 1] != '.' && a[i][j + 1] != '.' &&
              f[i][j - 1] == 0 && f[i][j + 1] == 0) {
            f[i][j - 1] = cnt;
            f[i][j] = cnt;
            f[i][j + 1] = cnt;
            ++cnt;
          } else {
            cout << "NO";
            exit(0);
          }
        } else {
          if (i > 1 && i < n && a[i - 1][j] != '.' && a[i + 1][j] != '.' &&
              f[i - 1][j] == 0 && f[i + 1][j] == 0) {
            f[i - 1][j] = cnt;
            f[i + 1][j] = cnt;
            f[i][j] = cnt;
            ++cnt;
          } else {
            cout << "NO";
            exit(0);
          }
        }
      }
  cout << "YES\n";
  for (int i = (1), _b = (n + 1); i < _b; ++i) {
    for (int j = (1), _b = (m + 1); j < _b; ++j)
      if (f[i][j] != 0) {
        if (c[f[i][j]] == 0) c[f[i][j]] = 1;
        for (int z = (0), _b = (4); z < _b; ++z) {
          int xx = i + dx[z];
          int yy = j + dy[z];
          if (in_bound(xx, yy) && f[xx][yy] != 0 && f[xx][yy] != f[i][j])
            ct[f[i][j]][c[f[xx][yy]]] = true;
        }
        while (ct[f[i][j]][c[f[i][j]]]) c[f[i][j]]++;
      }
  }
  for (int i = (1), _b = (n + 1); i < _b; ++i) {
    for (int j = (1), _b = (m + 1); j < _b; ++j) cout << col[c[f[i][j]]];
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  enter();
  if (possible())
    solve();
  else
    cout << "NO";
}
