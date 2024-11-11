#include <bits/stdc++.h>
using namespace std;
const int N = 2002;
int a[N][N];
char b[N][N], color[N / 2];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n & 1) {
    cout << "NONE" << endl;
    return 0;
  }
  for (int j = 0; j < n; j++) {
    a[0][j] = a[n - 1][n - j - 1] = a[j][0] = a[n - j - 1][n - 1] = j / 2;
    b[0][j] = b[n - 1][n - j - 1] = b[j][0] = b[n - j - 1][n - 1] = 1;
    if (j == 0 || j == n - 1) continue;
    a[1][j] = j & 1 ? (j + 1) / 2 : (j - 1) / 2;
    b[1][j] = 0;
  }
  for (int i = 2; i < n - 1; ++i) {
    for (int j = 1; j < n - 1; ++j) {
      if (a[i - 2][j] == a[i - 1][j - 1]) {
        a[i][j] = a[i - 1][j + 1];
      } else {
        a[i][j] = a[i - 1][j - 1];
      }
    }
  }
  memset(color, -1, sizeof(color));
  bool flag = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      int col = (c == 'S');
      if (i > 0 && i < n - 1 && j > 0 && j < n - 1) {
        if (a[i][j] == a[i - 1][j - 1] && a[i][j] == a[i + 1][j + 1]) {
          b[i][j] = 1 ^ b[i - 1][j - 1];
        } else {
          b[i][j] = 1 ^ b[i - 1][j + 1];
        }
      }
      if (c == '.') continue;
      if (!b[i][j]) col ^= 1;
      char &prv = color[a[i][j]];
      if (prv == -1 || prv == col) {
        prv = col;
      } else {
        flag = false;
        goto out;
      }
    }
  }
out:
  if (flag) {
    int c = 0;
    for (int i = 0; i < n / 2; ++i) {
      c += color[i] != -1;
    }
    if (c == n / 2) {
      cout << "UNIQUE" << endl;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          cout << "GS"[color[a[i][j]] == b[i][j]] << endl;
        }
        cout << endl;
      }
    } else {
      cout << "MULTIPLE" << endl;
    }
  } else {
    cout << "NONE" << endl;
  }
  return 0;
}
