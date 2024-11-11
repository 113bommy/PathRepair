#include <bits/stdc++.h>
using namespace std;
const int maxn = 307;
int a[maxn][maxn];
int fn1[maxn][maxn], f1m[maxn][maxn], f1n[maxn][maxn], fm1[maxn][maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, t, p, u, d;
  cin >> n >> m >> t;
  cin >> p >> u >> d;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] > a[i - 1][j])
        fn1[i][j] = fn1[i - 1][j] + d;
      else if (a[i][j] < a[i - 1][j])
        fn1[i][j] = fn1[i - 1][j] + u;
      else
        fn1[i][j] = fn1[i - 1][j] + p;
    }
  }
  for (int i = n - 1; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] > a[i + 1][j])
        f1n[i][j] = f1n[i + 1][j] + d;
      else if (a[i][j] < a[i + 1][j])
        f1n[i][j] = f1n[i + 1][j] + u;
      else
        f1n[i][j] = f1n[i + 1][j] + p;
    }
  }
  for (int j = m - 1; j >= 1; j--) {
    for (int i = 1; i <= n; i++) {
      if (a[i][j] > a[i][j + 1])
        f1m[i][j] = f1m[i][j + 1] + d;
      else if (a[i][j] < a[i][j + 1])
        f1m[i][j] = f1m[i][j + 1] + u;
      else
        f1m[i][j] = f1m[i][j + 1] + p;
    }
  }
  for (int j = 2; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (a[i][j] > a[i][j - 1])
        fm1[i][j] = fm1[i][j - 1] + d;
      else if (a[i][j] < a[i][j - 1])
        fm1[i][j] = fm1[i][j - 1] + u;
      else
        fm1[i][j] = fm1[i][j - 1] + p;
    }
  }
  int x1, x2, y1, y2, dif = 1e9;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int i1 = i + 2; i1 <= n; i1++) {
        for (int j1 = j + 2; j1 <= m; j1++) {
          int ans = fn1[i1][j] - fn1[i][j] + f1m[i][j] - f1m[i][j1] +
                    f1n[i][j1] - f1n[i1][j1] + fm1[i1][j1] - fm1[i1][j];
          if (abs(ans - t) < dif) {
            dif = abs(ans - t);
            x1 = i;
            x2 = i1;
            y1 = j;
            y2 = j1;
          }
        }
      }
    }
  }
  cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
  return 0;
}
