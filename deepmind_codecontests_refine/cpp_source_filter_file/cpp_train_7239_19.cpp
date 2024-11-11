#include <bits/stdc++.h>
using namespace std;
int n, g[6][6][3], in[6], out[6], cnt = 0, minoil = 1000000, maxcnt = -1;
void dfs(int l, int r) {
  if (l > 1) {
    if (out[l - 2] != in[l - 2]) return;
  }
  if (l == n - 1) {
    bool ok = true;
    for (int i = 0; i < n; i++)
      if (in[i] < out[i] && i != 0) {
        ok = false;
        break;
      } else if (out[i] < in[i] && i != n - 1) {
        ok = false;
        break;
      }
    if (ok) {
      if (minoil > in[n - 1] || (minoil == in[n - 1] && maxcnt < cnt)) {
        minoil = in[n - 1];
        maxcnt = cnt;
      }
    }
    return;
  }
  for (int i = g[l][r][0]; i <= g[l][r][1]; i++) {
    out[l] += i;
    in[r] += i;
    if (i == 0) {
      if (r + 1 == n) {
        dfs(l + 1, l + 2);
      } else {
        dfs(l, r + 1);
      }
    } else {
      if (r + 1 == n) {
        cnt += i * i + g[l][r][2];
        dfs(l + 1, l + 2);
        cnt -= i * i + g[l][r][2];
      } else {
        cnt += i * i + g[l][r][2];
        dfs(l, r + 1);
        cnt -= i * i + g[l][r][2];
      }
    }
    out[l] -= i;
    in[r] -= i;
  }
}
int main() {
  cin >> n;
  int x, y;
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    scanf("%d%d", &x, &y);
    --x;
    --y;
    for (int j = 0; j < 3; j++) cin >> g[x][y][j];
  }
  dfs(0, 1);
  if (minoil == 1000000 && maxcnt == -1)
    cout << -1 << " " << -1;
  else
    cout << minoil << " " << maxcnt;
  return 0;
}
