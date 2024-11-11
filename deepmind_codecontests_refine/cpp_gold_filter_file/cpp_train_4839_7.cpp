#include <bits/stdc++.h>
using namespace std;
int n, m, x;
long long ans;
char c[2000][2000];
int u[2000][2000], d[2000][2000], l[2000][2000], r[2000][2000];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (0); i <= (n - 1); i++) scanf("%s", c[i]);
  for (int i = (1); i <= (n - 2); i++) {
    bool u = 1;
    for (int j = (0); j <= (m - 1); j++)
      if (c[i][j] == '#') {
        u = 0;
        break;
      }
    if (u) ans++;
  }
  for (int j = (1); j <= (m - 2); j++) {
    bool u = 1;
    for (int i = (0); i <= (n - 1); i++)
      if (c[i][j] == '#') {
        u = 0;
        break;
      }
    if (u) ans++;
  }
  for (int i = (0); i <= (n - 1); i++) {
    for (int j = (0); j <= (m - 1); j++) {
      if (c[i][j] == '#') break;
      l[i][j] = 1;
    }
    for (int j = (m - 1); j >= (0); j--) {
      if (c[i][j] == '#') break;
      r[i][j] = 1;
    }
  }
  for (int j = (0); j <= (m - 1); j++) {
    for (int i = (0); i <= (n - 1); i++) {
      if (c[i][j] == '#') break;
      u[i][j] = 1;
    }
    for (int i = (n - 1); i >= (0); i--) {
      if (c[i][j] == '#') break;
      d[i][j] = 1;
    }
  }
  for (int i = (1); i <= (n - 2); i++) {
    for (int j = (1); j <= (m - 2); j++) {
      if (u[i][j] && l[i][j]) ans++;
      if (u[i][j] && r[i][j]) ans++;
      if (d[i][j] && l[i][j]) ans++;
      if (d[i][j] && r[i][j]) ans++;
    }
  }
  for (int i = (1); i <= (n - 2); i++) {
    x = 0;
    for (int j = (1); j <= (m - 4); j++) {
      x += u[i][j] + d[i][j];
      if (c[i][j] == '#') x = 0;
      if (c[i][j + 1] == '.') {
        if (u[i][j + 2]) ans += x;
        if (d[i][j + 2]) ans += x;
      }
    }
  }
  for (int i = (1); i <= (n - 2); i++)
    for (int j = (1); j <= (m - 3); j++) {
      if (u[i][j] && d[i][j + 1]) ans++;
      if (d[i][j] && u[i][j + 1]) ans++;
    }
  for (int j = (1); j <= (m - 2); j++) {
    x = 0;
    for (int i = (1); i <= (n - 4); i++) {
      x += l[i][j] + r[i][j];
      if (c[i][j] == '#') x = 0;
      if (c[i + 1][j] == '.') {
        if (l[i + 2][j]) ans += x;
        if (r[i + 2][j]) ans += x;
      }
    }
  }
  for (int j = (1); j <= (m - 2); j++)
    for (int i = (1); i <= (n - 3); i++) {
      if (l[i][j] && r[i + 1][j]) ans++;
      if (r[i][j] && l[i + 1][j]) ans++;
    }
  printf("%I64d\n", ans);
}
