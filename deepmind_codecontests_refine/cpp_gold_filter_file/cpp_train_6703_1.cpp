#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
int a[maxn][maxn];
int c[maxn][maxn];
int d[maxn][maxn];
pair<int, int> p[maxn][maxn];
const int inf = 10000001;
pair<int, string> solve(int n) {
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < n + 1; j++) {
      d[i][j] = inf;
    }
  }
  d[1][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (d[i][j - 1] < d[i - 1][j]) {
        p[i][j] = {i, j - 1};
      } else {
        p[i][j] = {i - 1, j};
      }
      d[i][j] = min(d[i][j - 1], d[i - 1][j]) + a[i][j];
    }
  }
  pair<int, int> ptr = {n, n};
  string path;
  do {
    auto nptr = p[ptr.first][ptr.second];
    if (nptr == make_pair(1, 0)) break;
    if (nptr.first == ptr.first)
      path += "R";
    else
      path += "D";
    swap(ptr, nptr);
  } while (ptr != make_pair(1, 0));
  reverse(path.begin(), path.end());
  return {d[n][n], path};
}
string path0;
bool f(int n) {
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (c[i][j] == 0) {
        int x = 1;
        int y = 1;
        while (x < i) path0 += "D", x++;
        while (y < j) path0 += "R", y++;
        while (x < n) path0 += "D", x++;
        while (y < n) path0 += "R", y++;
        return true;
      }
    }
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> c[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (c[i][j] == 0) {
        a[i][j] = 10;
        continue;
      }
      a[i][j] = 0;
      while (c[i][j] % 2 == 0) {
        a[i][j] += 1;
        c[i][j] /= 2;
      }
    }
  }
  pair<int, string> ans = {1000000, " "};
  ans = min(ans, solve(n));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (c[i][j] == 0) {
        a[i][j] = 10;
        continue;
      }
      a[i][j] = 0;
      while (c[i][j] % 5 == 0) {
        a[i][j] += 1;
        c[i][j] /= 5;
      }
    }
  }
  ans = min(ans, solve(n));
  if (f(n)) {
    ans = min(ans, make_pair(1, path0));
  }
  cout << ans.first << endl << ans.second << endl;
  return 0;
}
