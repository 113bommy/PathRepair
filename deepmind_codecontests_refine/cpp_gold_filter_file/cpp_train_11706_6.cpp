#include <bits/stdc++.h>
using namespace std;
int a[400][400];
int n, m;
int s[400][400];
int s2[400][400];
int left() {
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 1) continue;
      for (int k = 1;
           k < min(n - i, m - j) && a[i + k][j] == 0 && a[i][j + k] == 0; ++k) {
        if (s2[i + k - 1][j + 1] - s2[i][j + k] == 0) ++res;
      }
    }
  }
  return res;
}
int top() {
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 1) continue;
      for (int k = 1; k < min(min(n - i, m - j), j + 1) &&
                      a[i + k][j - k] == 0 && a[i + k][j + k] == 0;
           ++k) {
        if (s[i + k][j + k - 1] - s[i + k][j - k] == 0) {
          ++res;
        }
      }
    }
  }
  return res;
}
void rotate_a() {
  int b[400][400];
  int tmp = n;
  n = m;
  m = tmp;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      b[i][j] = a[j][n - i - 1];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      a[i][j] = b[i][j];
    }
  }
}
void make_s() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (j != 0)
        s[i][j] = s[i][j - 1] + a[i][j];
      else
        s[i][j] = a[i][j];
    }
  }
}
void make_s2() {
  for (int i = 0; i < m; ++i) {
    s2[0][i] = a[0][i];
  }
  for (int i = 1; i < n; ++i) {
    s2[i][m - 1] = a[i][m - 1];
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      s2[i][j] = a[i][j] + s2[i - 1][j + 1];
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < m; ++j) {
      a[i][j] = tmp[j] - '0';
    }
  }
  int res = 0;
  for (int i = 1; i <= 4; ++i) {
    make_s();
    make_s2();
    res += left();
    res += top();
    rotate_a();
  }
  cout << res << endl;
  return 0;
}
