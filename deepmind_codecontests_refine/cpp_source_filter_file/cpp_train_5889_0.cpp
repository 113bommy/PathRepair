#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N][N];
bool l[N][N], r[N][N];
bool d[N][N], u[N][N];
int n, m;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      l[i][j] = l[i][j - 1] | (a[i][j - 1]);
    }
    for (int j = n; j >= 1; j--) {
      r[i][j] = r[i][j + 1] | (a[i][j + 1]);
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      u[i][j] = u[i - 1][j] | (a[i - 1][j]);
    }
    for (int i = n; i >= 1; i--) {
      d[i][j] = d[i + 1][j] | (a[i + 1][j]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!a[i][j]) {
        if (l[i][j]) ans++;
        if (r[i][j]) ans++;
        if (d[i][j]) ans++;
        if (u[i][j]) ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
