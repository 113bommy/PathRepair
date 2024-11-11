#include <bits/stdc++.h>
using namespace std;
const int T = 1e9 + 7;
long long ans = 0;
int b[20][20], a[20][20], p[20], cur[20][20];
int n, m, k;
bool check(int x, int y, int c) {
  b[x][y] = b[x][y - 1] | b[x - 1][y];
  if (b[x][y] & (1 << c)) return 0;
  b[x][y] |= (1 << c);
  cur[x][y] = c;
  return 1;
}
void cal() {
  int num = 0;
  memset(p, 0, sizeof(p));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (num < cur[i][j]) num = cur[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j]) {
        int buf = cur[i][j];
        if (!p[buf])
          p[buf] = a[i][j];
        else if (p[buf] != a[i][j])
          return;
      }
  for (int i = 1; i <= num; i++)
    for (int j = 1; j <= num; j++)
      if (i != j && p[i] && p[j] && p[i] == p[j]) return;
  int a = k, b = num;
  for (int i = 1; i <= num; i++)
    if (p[i]) a--, b--;
  long long buf = 1;
  for (int i = a; i >= (a - b + 1); i--) buf *= i, buf %= T;
  ans += buf;
  ans %= T;
  return;
}
void dfs(int x, int y, int num) {
  if (x == n + 1) {
    cal();
    return;
  }
  if (y == m + 1) {
    dfs(x + 1, 1, num);
    return;
  }
  for (int i = 1; i <= num; i++)
    if (check(x, y, i)) {
      if (i == num)
        dfs(x, y + 1, min(num + 1, k));
      else
        dfs(x, y + 1, num);
    }
  return;
}
int main() {
  cin >> n >> m >> k;
  if (m + n - 1 > k) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  memset(b, 0, sizeof(b));
  dfs(1, 1, 1);
  cout << ans << endl;
  return 0;
}
