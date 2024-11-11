#include <bits/stdc++.h>
using namespace std;
int n, m, k, s;
int a[2005][2005];
int b[100005];
int c[11][11];
int d[11][2005][2005];
int get(int i1, int j1, int d1) {
  int an = -1;
  int x, y;
  if (d1 == 0)
    x = 1, y = 1;
  else if (d1 == 1)
    x = 1, y = -1;
  else if (d1 == 2)
    x = -1, y = -1;
  else
    x = -1, y = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j] == i1) {
        an = max({an, x * i + y * j + d[j1][i][j]});
      }
  return an;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k >> s;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 1; i <= s; i++) cin >> b[i];
  for (int i = 2; i <= s; i++) c[b[i]][b[i - 1]] = 1, c[b[i - 1]][b[i]] = 1;
  int ans = 0;
  for (int i1 = 1; i1 <= k; i1++) {
    for (int i = 1; i <= n; i++)
      if (a[i][1] == i1)
        d[i1][i][1] = -i - 1;
      else
        d[i1][i][1] = -100000000;
    for (int i = 1; i <= m; i++)
      if (a[1][i] == i1)
        d[i1][1][i] = -i - 1;
      else
        d[i1][1][i] = -100000000;
    for (int i = 2; i <= n; i++)
      d[i1][i][1] = max(d[i1][i][1], d[i1][i - 1][1]);
    for (int i = 2; i <= m; i++)
      d[i1][1][i] = max(d[i1][1][i], d[i1][1][i - 1]);
    for (int i = 2; i <= n; i++)
      for (int j = 2; j <= m; j++)
        d[i1][i][j] = max({(a[i][j] == i1 ? -i - j : -100000000),
                           d[i1][i - 1][j], d[i1][i][j - 1]});
  }
  for (int i1 = 1; i1 <= k; i1++) {
    for (int j1 = i1; j1 <= k; j1++) {
      if (c[i1][j1]) {
        ans = max(ans, get(i1, j1, 0));
      }
    }
  }
  for (int i1 = 1; i1 <= k; i1++) {
    for (int i = 1; i <= n; i++)
      if (a[i][m] == i1)
        d[i1][i][m] = -i + m;
      else
        d[i1][i][m] = -100000000;
    for (int i = 1; i <= m; i++)
      if (a[1][i] == i1)
        d[i1][1][i] = i - 1;
      else
        d[i1][1][i] = -100000000;
    for (int i = 2; i <= n; i++)
      d[i1][i][m] = max(d[i1][i][m], d[i1][i - 1][m]);
    for (int i = m - 1; i >= 1; i--)
      d[i1][1][i] = max(d[i1][1][i + 1], d[i1][1][i]);
    for (int i = 2; i <= n; i++)
      for (int j = m - 1; j >= 1; j--)
        d[i1][i][j] = max({(a[i][j] == i1 ? -i + j : -100000000),
                           d[i1][i - 1][j], d[i1][i][j + 1]});
  }
  for (int i1 = 1; i1 <= k; i1++) {
    for (int j1 = i1; j1 <= k; j1++) {
      if (c[i1][j1]) {
        ans = max(ans, get(i1, j1, 1));
      }
    }
  }
  for (int i1 = 1; i1 <= k; i1++) {
    for (int i = 1; i <= n; i++)
      if (a[i][m] == i1)
        d[i1][i][m] = i + m;
      else
        d[i1][i][m] = -100000000;
    for (int i = 1; i <= m; i++)
      if (a[n][i] == i1)
        d[i1][n][i] = i + n;
      else
        d[i1][n][i] = -100000000;
    for (int i = n - 1; i >= 1; i--)
      d[i1][i][m] = max(d[i1][i][m], d[i1][i + 1][m]);
    for (int i = m - 1; i >= 1; i--)
      d[i1][n][i] = max(d[i1][n][i], d[i1][n][i - 1]);
    for (int i = n - 1; i >= 1; i--)
      for (int j = m - 1; j >= 1; j--)
        d[i1][i][j] = max({a[i][j] == i1 ? i + j : -100000000, d[i1][i + 1][j],
                           d[i1][i][j + 1]});
  }
  for (int i1 = 1; i1 <= k; i1++) {
    for (int j1 = i1; j1 <= k; j1++) {
      if (c[i1][j1]) {
        ans = max(ans, get(i1, j1, 2));
      }
    }
  }
  for (int i1 = 1; i1 <= k; i1++) {
    for (int i = n; i >= 1; i--)
      if (a[i][1] == i1)
        d[i1][i][1] = i - 1;
      else
        d[i1][i][1] = -100000000;
    for (int i = 1; i <= m; i++)
      if (a[n][i] == i1)
        d[i1][n][i] = -i + n;
      else
        d[i1][n][i] = -100000000;
    for (int i = n - 1; i >= 1; i--)
      d[i1][i][1] = max(d[i1][i][1], d[i1][i + 1][1]);
    for (int i = 2; i <= m; i++)
      d[i1][n][i] = max(d[i1][n][i], d[i1][n][i - 1]);
    for (int i = n - 1; i >= 1; i--)
      for (int j = 2; j <= m; j++)
        d[i1][i][j] = max({a[i][j] == i1 ? i - j : -100000000, d[i1][i + 1][j],
                           d[i1][i][j - 1]});
  }
  for (int i1 = 1; i1 <= k; i1++) {
    for (int j1 = i1; j1 <= k; j1++) {
      if (c[i1][j1]) {
        ans = max(ans, get(i1, j1, 3));
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
