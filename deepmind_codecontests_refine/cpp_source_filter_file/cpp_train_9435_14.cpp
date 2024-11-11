#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010], ch[100010], n, m, mp[20][20], h[20][20], flag,
    use[100010];
const int dx[5] = {0, 0, 1, 0, -1}, dy[5] = {0, 1, 0, -1, 0};
void sc() {
  puts("YES");
  flag = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ", mp[i][j]);
    puts("");
  }
}
bool check(int dep) {
  int x = dep / m, y = dep % m;
  if (y == 0)
    y = m;
  else
    x++;
  mp[x][y] = ch[dep];
  for (int i = 1; i <= 4; i++) {
    int tx = x + dx[i], ty = y + dy[i];
    if (tx > 0 && ty > 0 && tx <= n && ty <= m && (tx - 1) * m + ty < dep &&
        h[mp[x][y]][mp[tx][ty]])
      return false;
  }
  return true;
}
void work(int dep) {
  if (dep > n * m)
    sc();
  else
    for (int i = 1; i <= n * m; i++)
      if (use[i] == 0) {
        ch[dep] = i;
        if (check(dep)) {
          use[i] = 1;
          work(dep + 1);
          use[i] = 0;
          if (flag) return;
        }
      }
}
int main() {
  cin >> n >> m;
  if (max(n, m) <= 4) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) mp[i][j] = (i - 1) * m + j;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        for (int k = 1; k <= 4; k++) {
          int x = i + dx[k], y = j + dy[k];
          if (x > 0 && y > 0 && x <= n && y <= m) h[mp[i][j]][mp[x][y]] = 1;
        }
    work(1);
    if (flag == 0) puts("NO");
    return 0;
  }
  puts("YES");
  if (m > 4) {
    int sum = 0, st1, st0;
    if (m % 2) {
      st1 = m;
      st0 = m - 1;
    } else {
      st1 = m - 1;
      st0 = m;
    }
    for (int i = st1; i >= 1; i -= 2) a[++sum] = i;
    for (int i = st0; i >= 1; i -= 2) a[++sum] = i;
    sum = 0;
    for (int i = st0; i >= 1; i -= 2) b[++sum] = i;
    for (int i = st1; i >= 1; i -= 2) b[++sum] = i;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++)
        if (i % 2)
          printf("%d ", (i - 1) * m + a[j]);
        else
          printf("%d ", (i - 1) * m + b[j]);
      puts("");
    }
  } else {
    int sum = 0, st1, st0;
    if (n % 2) {
      st1 = n;
      st0 = n - 1;
    } else {
      st1 = n - 1;
      st0 = n;
    }
    for (int i = st1; i >= 1; i -= 2) a[++sum] = i;
    for (int i = st0; i >= 1; i -= 2) a[++sum] = i;
    sum = 0;
    for (int i = st0; i >= 1; i -= 2) b[++sum] = i;
    for (int i = st1; i >= 1; i -= 2) b[++sum] = i;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++)
        if (i % 2)
          printf("%d ", (a[i] - 1) * m + j);
        else
          printf("%d ", (b[i] - 1) * m + j);
      puts("");
    }
  }
  return 0;
}
