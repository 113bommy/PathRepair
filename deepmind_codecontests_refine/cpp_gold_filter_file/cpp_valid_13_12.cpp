#include <bits/stdc++.h>
using namespace std;
int n, m;
bool ok(int i, int j) { return i < n && j < m && i >= 0 && j >= 0; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin >> test;
  for (int cur_test = 1; cur_test <= test; cur_test++) {
    int k;
    cin >> n >> m >> k;
    string res[n];
    for (int i = 0; i < n; i++) {
      string q = "";
      for (int j = 0; j < m; j++) q += '.';
      res[i] = q;
    }
    bool possible = 0;
    if (m == 1) {
      if (k == 0) {
        cout << "YES\n";
        possible = 1;
        for (int i = 0; i < n; i++) res[i][0] = 'V';
      } else
        cout << "NO\n";
    } else {
      if (n % 2 == 1) {
        for (int fil = 1; fil * (m / 2) <= k && !possible; fil += 2) {
          int sob = k - fil * (m / 2);
          for (int col = 2; col <= m && !possible; col += 2) {
            int cc = col / 2;
            int z = sob / cc;
            int ss = sob % cc;
            if (z + (ss > 0 ? 2 : 0) <= n - fil && z % 2 == 0 && ss % 2 == 0) {
              for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                  if (i + 1 <= fil) {
                    res[i][j] = 'H';
                  } else {
                    if (j + 1 <= col) {
                      if (i + 1 <= fil + z) {
                        res[i][j] = 'H';
                      } else {
                        if (i + 1 <= fil + z + 2 && j + 1 <= ss) {
                          res[i][j] = 'H';
                        } else
                          res[i][j] = 'V';
                      }
                    } else
                      res[i][j] = 'V';
                  }
                }
              }
              possible = 1;
            }
          }
        }
      } else {
        for (int fil = 0; fil * (m / 2) <= k && !possible; fil += 2) {
          int sob = k - fil * (m / 2);
          for (int col = 2; col <= m && !possible; col += 2) {
            int cc = col / 2;
            int z = sob / cc;
            int ss = sob % cc;
            if (z + (ss > 0 ? 2 : 0) <= n - fil && z % 2 == 0 && ss % 2 == 0) {
              for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                  if (i + 1 <= fil) {
                    if (j < m - 1)
                      res[i][j] = 'H';
                    else
                      res[i][j] = 'V';
                  } else {
                    if (j + 1 <= col) {
                      if (i + 1 <= fil + z) {
                        if (j < m - 1)
                          res[i][j] = 'H';
                        else
                          res[i][j] = 'V';
                      } else {
                        if (i + 1 <= fil + z + 2 && j + 1 <= ss) {
                          res[i][j] = 'H';
                        } else
                          res[i][j] = 'V';
                      }
                    } else
                      res[i][j] = 'V';
                  }
                }
              }
              possible = 1;
            }
          }
        }
      }
      if (possible)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
    if (possible) {
      vector<int> dx = {-1, -1, -1, -1, 0, 0, 1, 1, 1, 1};
      vector<int> dy = {-1, 0, 1, 2, -1, 2, -1, 0, 1, 2};
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (res[i][j] == 'H') {
            set<char> s;
            for (int h = 0; h < 10; h++) {
              int ni = dx[h] + i;
              int nj = dy[h] + j;
              if (ok(ni, nj) && res[ni][nj] != 'H' && res[ni][nj] != 'V') {
                s.insert(res[ni][nj]);
              }
            }
            for (char x = 'a'; x <= 'z'; x++) {
              if (s.count(x) == 0) {
                res[i][j] = x;
                res[i][j + 1] = x;
                break;
              }
            }
          }
        }
      }
      dx = {-1, 0, 1, -1, 1, -1, 1, -1, 0, 1};
      dy = {-1, -1, -1, 0, 0, 1, 1, 2, 2, 2};
      for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
          if (res[i][j] == 'V') {
            set<char> s;
            for (int h = 0; h < 10; h++) {
              int ni = dx[h] + i;
              int nj = dy[h] + j;
              if (ok(ni, nj) && res[ni][nj] != 'H' && res[ni][nj] != 'V') {
                s.insert(res[ni][nj]);
              }
            }
            for (char x = 'a'; x <= 'z'; x++) {
              if (s.count(x) == 0) {
                res[i][j] = x;
                res[i + 1][j] = x;
                break;
              }
            }
          }
        }
      }
      for (int i = 0; i < n; i++) cout << res[i] << '\n';
    }
  }
  return 0;
}
