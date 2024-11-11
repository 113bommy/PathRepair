#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
const int inf = 1e9;
const int md = 1e9 + 7;
int a[205][205];
int m;
int get(int first, int second) {
  if (first < 0 || second < 0 || first >= m || second >= m) return 0;
  return a[first][second];
}
bool check(int first, int second) {
  if (get(first - 1, second) == 0 && get(first + 1, second) == 0 &&
      get(first, second - 1) == 0 && get(first, second + 1) == 0 &&
      get(first, second) == 0)
    return true;
  else
    return false;
}
bool check2(int first, int second) {
  if (get(first, second) == 1)
    if (get(first - 1, second) == 0 && get(first + 1, second) == 0 &&
        get(first, second - 1) == 0 && get(first, second + 1) == 0)
      return true;
    else
      return false;
  else
    return true;
}
int main() {
  int first;
  cin >> first;
  for (int n = 1; n <= 200; ++n) {
    m = n;
    memset(a, 0, sizeof(a));
    int col = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (check(i, j) && check(n - i - 1, j) && check(i, n - j - 1) &&
            check(n - i - 1, n - j - 1))
          a[i][j] = a[n - i - 1][j] = a[i][n - j - 1] =
              a[n - i - 1][n - j - 1] = 1;
        int tmp = 0;
        for (int i2 = 0; i2 < n; ++i2)
          for (int j2 = 0; j2 < n; ++j2) {
            if (!check2(i2, j2)) tmp = inf;
            tmp += a[i2][j2];
          }
        if (tmp > first)
          a[i][j] = a[n - i - 1][j] = a[i][n - j - 1] =
              a[n - i - 1][n - j - 1] = 0;
        else
          col = tmp;
      }
    if (col == first) {
      cout << n << endl;
      return 0;
    }
  }
  return 0;
}
