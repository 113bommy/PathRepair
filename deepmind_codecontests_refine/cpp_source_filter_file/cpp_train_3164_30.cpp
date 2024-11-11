#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, m, k, s, e;
bool a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];
char d;
void print() {
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << c[i][j] + 1 << " ";
    cout << endl;
  }
}
bool check() {
  int x = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 2; j <= m; j++)
      if ((a[i][j] && (c[i][j] == c[i][j - 1])) ||
          (!a[i][j] && (c[i][j] != c[i][j - 1])))
        x++;
  for (int j = 1; j <= m; j++) {
    for (int i = 2; i <= n; i++) {
      if ((b[i][j] && (c[i][j] == c[i - 1][j])) ||
          (!a[i][j] && (c[i][j] != c[i - 1][j])))
        x++;
    }
  }
  if (4 * x >= 3 * s)
    return true;
  else
    return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  s = n * (m - 1) + m * (n - 1);
  for (int i = 1; i < 2 * n; i++) {
    if (i % 2) {
      for (int j = 2; j <= m; j++) {
        cin >> d;
        if (d == 'E') {
          a[(i + 1) / 2][j] = 1;
          e++;
        }
      }
    } else {
      for (int j = 1; j <= m; j++) {
        cin >> d;
        if (d == 'E') {
          b[i / 2 + 1][j] = 1;
          e++;
        }
      }
    }
  }
  if (k == 1) {
    if (4 * e >= 3 * s) {
      cout << "YES" << endl;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout << 1 << " ";
        cout << endl;
      }
    } else
      cout << "NO" << endl;
    return 0;
  }
  if (n <= m) {
    for (int i = 1; i <= n; i++) {
      for (int j = 2; j <= m; j++) {
        if (!a[i][j])
          c[i][j] = 1 - c[i][j - 1];
        else
          c[i][j] = c[i][j - 1];
      }
    }
    if (check())
      print();
    else {
      for (int i = 1; i <= n; i += 2) {
        for (int j = 1; j <= m; j++) c[i][j] = 1 - c[i][j];
      }
      print();
    }
  } else {
    for (int j = 1; j <= m; j++) {
      for (int i = 2; i <= n; i++) {
        if (!b[i][j])
          c[i][j] = 1 - c[i - 1][j];
        else
          c[i][j] = c[i - 1][j];
      }
    }
    if (check())
      print();
    else {
      for (int j = 1; j <= m; j += 2) {
        for (int i = 1; i <= n; i++) c[i][j] = 1 - c[i][j];
      }
      print();
    }
  }
  return 0;
}
