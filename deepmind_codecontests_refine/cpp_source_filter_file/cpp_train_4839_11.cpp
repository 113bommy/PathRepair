#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int cnt = 0;
int n, m;
char s[N][N], str[N][N];
int l[N][N], r[N][N];
int num[N][N][2];
int up[N][N], down[N][N];
void init(int n, int m) {
  memset(l, 0, sizeof(l));
  memset(r, 0, sizeof(r));
  memset(up, 0, sizeof(up));
  memset(num, 0, sizeof(num));
  memset(down, 0, sizeof(down));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      num[i][j][0] = num[i - 1][j][0] + (s[i][j] == '#');
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++)
      num[i][j][1] = num[i][j - 1][1] + (s[i][j] == '#');
  }
  for (int i = 1; i <= n; i++) l[i][1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= m; j++)
      if (s[i][j] == '.')
        l[i][j] = l[i][j - 1];
      else
        l[i][j] = j;
  }
  for (int i = 1; i <= n; i++) r[i][m] = m;
  for (int i = n; i >= 1; i--) {
    for (int j = m - 1; j >= 1; j--)
      if (s[i][j] == '.')
        r[i][j] = r[i][j + 1];
      else
        r[i][j] = j;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) up[i][j] = up[i][j - 1] + (num[i][j][0] == 0);
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++)
      down[i][j] = down[i][j - 1] + (num[n][j][0] - num[i - 1][j][0] == 0);
  }
}
long long work(int n, int m) {
  init(n, m);
  long long ans = 0;
  for (int i = 2; i < n; i++) {
    for (int j = 2; j < m; j++)
      if (s[i][j] == '.') {
        int in = l[i][j];
        if (num[i][i][0] == 0 && j - 2 >= in) ans += up[i][j - 2] - up[i][in];
        if (num[i][j][0] == 0 && j - 1 >= in)
          ans += down[i][j - 1] - down[i][in];
        if (num[n][j][0] - num[i - 1][j][0] == 0 && j - 2 >= in)
          ans += down[i][j - 2] - down[i][in];
        in = r[i][j];
        if (num[i][j][0] == 0 && m - 1 >= j)
          ans += down[i][in - 1] - down[i][j];
      }
  }
  return ans;
}
int main() {
  long long ans = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    for (int j = 1; j <= m; j++) str[i][j] = s[i][j];
  }
  init(n, m);
  for (int j = 2; j < m; j++)
    if (num[n][j][0] == 0) ans++;
  for (int i = 2; i < n; i++)
    if (num[i][m][1] == 0) ans++;
  for (int i = 2; i < n; i++) {
    for (int j = 2; j < m; j++)
      if (s[i][j] == '.') {
        if (num[i][j][0] == 0 && num[i][j][1] == 0) ans++;
        if (num[i][j][0] == 0 && num[i][m][1] - num[i][j - 1][1] == 0) ans++;
        if (num[n][j][0] - num[i - 1][j][0] == 0 && num[i][j][1] == 0) ans++;
        if (num[n][j][0] - num[i - 1][j][0] == 0 &&
            num[i][m][1] - num[i][j - 1][1] == 0)
          ans++;
      }
  }
  ans += work(n, m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) s[j][i] = str[i][j];
  }
  ans += work(m, n);
  cout << ans << endl;
  return 0;
}
