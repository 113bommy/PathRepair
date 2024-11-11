#include <bits/stdc++.h>
using namespace std;
const int size = 110000, mod = 1000000009;
const double pi = acos(-1.0);
char s[110][10010];
int pre[110][10010];
int n, m;
bool in(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
bool flag;
int cnt;
void bfs(int x, int y, int d, int f) {
  while (1) {
    cnt++;
    if (x == n - 1) return;
    if (s[x + 1][y] == '.')
      pre[x + 1][y] = y, x++, f = 0;
    else {
      if (in(x, y + d)) {
        if (s[x][y + d] == '.')
          pre[x][y + d] = pre[x][y], y += d;
        else if (s[x][y + d] == '+')
          s[x][y + d] = '.', d = -d, f = 0, cnt += abs(pre[x][y] - y),
                   pre[x][pre[x][y]] = y, y = pre[x][y];
        else {
          if (f) {
            flag = 0;
            return;
          }
          d = -d, f = 1, cnt += abs(pre[x][y] - y), pre[x][pre[x][y]] = y,
          y = pre[x][y];
        }
      } else {
        if (f) {
          flag = 0;
          return;
        }
        d = -d, f = 1, cnt += abs(pre[x][y] - y), pre[x][pre[x][y]] = y,
        y = pre[x][y];
      }
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  flag = 1;
  memset(pre, 0, sizeof(pre));
  bfs(0, 0, 1, 0);
  if (!flag)
    cout << "Never" << endl;
  else
    cout << cnt - 1 << endl;
  return 0;
}
