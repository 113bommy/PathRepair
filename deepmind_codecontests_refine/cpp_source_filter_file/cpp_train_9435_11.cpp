#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  bool transp = false;
  if (n > m) {
    transp = true;
    swap(n, m);
  }
  if (m == 2 or (n != 3 and m == 3))
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    vector<vector<int> > v(n, vector<int>(m));
    if (n == 1 and m != 4) {
      for (int i = 1; i <= m; i += 2) v[0][i / 2] = i;
      for (int i = 2; i <= m; i += 2) v[0][m / 2 + i / 2] = i;
    } else {
      if (n == 3 and m == 3) {
        v[0][0] = 5;
        v[0][1] = 3;
        v[0][2] = 7;
        v[1][0] = 9;
        v[1][1] = 4;
        v[1][2] = 2;
        v[2][0] = 1;
        v[2][1] = 6;
        v[2][2] = 8;
      } else {
        if (m == 4 and n == 1) {
          v[0][0] = 3;
          v[0][1] = 1;
          v[0][2] = 4;
          v[0][3] = 2;
        } else {
          if (transp) {
            for (int i = 0; i < n; ++i) {
              for (int j = 0; j < m; ++j) {
                v[i][j] = j * n + i + 1;
                if (i % 2 == 0) {
                  v[i][j] += 2 * n;
                  if (j >= m - 2) v[i][j] -= n * m;
                }
              }
            }
            for (int j = 0; j < m; j += 2) {
              int a = v[0][j];
              for (int i = 0; i < n - 1; ++i) {
                v[i][j] = v[i + 1][j];
              }
              v[n - 1][j] = a;
            }
          } else {
            for (int i = 0; i < n; ++i) {
              for (int j = 0; j < m; ++j) {
                v[i][j] = i * m + j + 1;
                if (i % 2 == 0) {
                  v[i][j] += 2;
                  if (v[i][j] > i * m + m) v[i][j] -= m;
                }
              }
            }
            for (int j = 0; j < m; j += 2) {
              int a = v[0][j];
              for (int i = 0; i < n - 1; ++i) {
                v[i][j] = v[i + 1][j];
              }
              v[n - 1][j] = a;
            }
          }
        }
      }
    }
    if (transp) {
      for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
          cout << v[i][j] << " ";
        }
        cout << endl;
      }
    } else {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          cout << v[i][j] << " ";
        }
        cout << endl;
      }
    }
  }
}
