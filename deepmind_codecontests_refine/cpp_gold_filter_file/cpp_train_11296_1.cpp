#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
const double PI = atan(1.0) * 4.0;
const long long mod = 1e9 + 7;
int n, m, k, cnt;
char s[1005][1005];
int ans[1005][1005], v[1005][1005];
void Getcnt(int x, int y) {
  v[x][y] = 1;
  if (!v[x][y - 1]) {
    if (s[x][y - 1] == '*')
      cnt++;
    else
      Getcnt(x, y - 1);
  }
  if (!v[x][y + 1]) {
    if (s[x][y + 1] == '*')
      cnt++;
    else
      Getcnt(x, y + 1);
  }
  if (!v[x - 1][y]) {
    if (s[x - 1][y] == '*')
      cnt++;
    else
      Getcnt(x - 1, y);
  }
  if (!v[x + 1][y]) {
    if (s[x + 1][y] == '*')
      cnt++;
    else
      Getcnt(x + 1, y);
  }
}
void Getans(int x, int y) {
  ans[x][y] = cnt;
  if (s[x][y - 1] && !ans[x][y - 1] && s[x][y - 1] == '.') Getans(x, y - 1);
  if (s[x][y + 1] && !ans[x][y + 1] && s[x][y + 1] == '.') Getans(x, y + 1);
  if (s[x - 1][y] && !ans[x - 1][y] && s[x - 1][y] == '.') Getans(x - 1, y);
  if (s[x + 1][y] && !ans[x + 1][y] && s[x + 1][y] == '.') Getans(x + 1, y);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '.' && !ans[i][j]) {
        cnt = 0;
        Getcnt(i, j);
        Getans(i, j);
      }
  while (k--) {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", ans[x][y]);
  }
  return 0;
}
