#include <bits/stdc++.h>
using namespace std;
void trace_() { cerr << "\n"; }
template <typename T1, typename... T2>
void trace_(T1 t1, T2... t2) {
  cerr << ' ' << t1;
  trace_(t2...);
}
int X[4] = {0, 0, 1, -1}, Y[4] = {1, -1, 0, 0};
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int r = n * m / 2 - k;
  vector<vector<char>> ans(n + 5, vector<char>(m + 5));
  auto valid = [&](int x, int y, char c) -> bool {
    for (int j = 0; j < 4; j++) {
      int nx = x + X[j], ny = y + Y[j];
      if (ans[nx][ny] == c) return false;
    }
    return true;
  };
  auto p = [&]() {
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) cout << ans[i][j];
      cout << "\n";
    }
  };
  if (m & 1) {
    if (m == 1 && k) {
      cout << "NO\n";
      return;
    }
    if ((k & 1) || r < n / 2) {
      cout << "NO\n";
      return;
    }
    char ch = 'a';
    for (int i = 1; i <= n; i += 2) {
      ans[i][1] = ch;
      ans[i + 1][1] = ch;
      r--;
      if (ch == 'z') ch = 'a';
      ch++;
    }
    for (int j = 1; j <= m; j++)
      for (int i = 1; i <= n; i++) {
        if (k == 0) break;
        if ('a' <= ans[i][j] && ans[i][j] <= 'z') continue;
        for (char c = 'a'; c <= 'z'; c++) {
          if (valid(i, j, c) && valid(i, j + 1, c)) {
            ans[i][j] = c;
            ans[i][j + 1] = c;
            k--;
            break;
          }
        }
      }
    for (int j = 1; j <= m; j++)
      for (int i = 1; i <= n; i++) {
        if (r == 0) break;
        if ('a' <= ans[i][j] && ans[i][j] <= 'z') continue;
        for (char c = 'a'; c <= 'z'; c++) {
          if (valid(i, j, c) && valid(i + 1, j, c)) {
            ans[i][j] = c;
            ans[i + 1][j] = c;
            r--;
            break;
          }
        }
      }
    p();
  } else if (n & 1) {
    if (n == 1 && r) {
      cout << "NO\n";
      return;
    }
    if ((r & 1) || k < m / 2) {
      cout << "NO\n";
      return;
    }
    char ch = 'a';
    for (int i = 1; i <= m; i += 2) {
      ans[1][i] = ch;
      ans[1][i + 1] = ch;
      k--;
      if (ch == 'z') ch = 'a';
      ch++;
    }
    for (int j = 1; j <= m; j++)
      for (int i = 1; i <= n; i++) {
        if (k == 0) break;
        if ('a' <= ans[i][j] && ans[i][j] <= 'z') continue;
        for (char c = 'a'; c <= 'z'; c++) {
          if (valid(i, j, c) && valid(i, j + 1, c)) {
            ans[i][j] = c;
            ans[i][j + 1] = c;
            k--;
            break;
          }
        }
      }
    for (int j = 1; j <= m; j++)
      for (int i = 1; i <= n; i++) {
        if (r == 0) break;
        if ('a' <= ans[i][j] && ans[i][j] <= 'z') continue;
        for (char c = 'a'; c <= 'z'; c++) {
          if (valid(i, j, c) && valid(i + 1, j, c)) {
            ans[i][j] = c;
            ans[i + 1][j] = c;
            r--;
            break;
          }
        }
      }
    p();
  } else {
    if (k & 1) {
      cout << "NO\n";
      return;
    }
    for (int j = 1; j <= m; j++)
      for (int i = 1; i <= n; i++) {
        if (k == 0) break;
        if ('a' <= ans[i][j] && ans[i][j] <= 'z') continue;
        for (char c = 'a'; c <= 'z'; c++) {
          if (valid(i, j, c) && valid(i, j + 1, c)) {
            ans[i][j] = c;
            ans[i][j + 1] = c;
            k--;
            break;
          }
        }
      }
    for (int j = 1; j <= m; j++)
      for (int i = 1; i <= n; i++) {
        if (r == 0) break;
        if ('a' <= ans[i][j] && ans[i][j] <= 'z') continue;
        for (char c = 'a'; c <= 'z'; c++) {
          if (valid(i, j, c) && valid(i + 1, j, c)) {
            ans[i][j] = c;
            ans[i + 1][j] = c;
            r--;
            break;
          }
        }
      }
    p();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) solve();
}
