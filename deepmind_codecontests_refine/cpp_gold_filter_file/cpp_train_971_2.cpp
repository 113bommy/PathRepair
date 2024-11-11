#include <bits/stdc++.h>
using namespace std;
int n, k;
char s[2][100005];
int d[2][100005];
bool f[2][100005];
void work() {
  int i, j, x, y, ans = 0;
  scanf("%d%d", &n, &k);
  scanf("%s%s", s[0] + 1, s[1] + 1);
  queue<pair<int, int> > q;
  q.push(make_pair(0, 1)), f[0][1] = 1, d[0][1] = 1;
  while (!q.empty()) {
    x = q.front().first, y = q.front().second, q.pop();
    if (y + k <= n && s[!x][y + k] != 'X' && !f[!x][y + k])
      f[!x][y + k] = 1, q.push(make_pair(!x, y + k)),
                d[!x][y + k] = d[x][y] + 1;
    if (y + 1 <= n && s[x][y + 1] != 'X' && !f[x][y + 1])
      f[x][y + 1] = 1, q.push(make_pair(x, y + 1)), d[x][y + 1] = d[x][y] + 1;
    if (y - 1 > 0 && y - 1 > d[x][y] && s[x][y - 1] != 'X' && !f[x][y - 1])
      f[x][y - 1] = 1, q.push(make_pair(x, y - 1)), d[x][y - 1] = d[x][y] + 1;
  }
  for (i = n - k + 1; i <= n; ++i) ans |= f[0][i] | f[1][i];
  puts(ans ? "YES" : "NO");
}
int main() {
  work();
  return 0;
}
