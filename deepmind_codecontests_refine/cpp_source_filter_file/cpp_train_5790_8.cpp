#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int n, m;
bool a[5000 + 10][5000 + 10];
int sum[5000 + 10][5000 + 10];
bool vis[2500 + 10];
int getSum(int ax, int ay, int bx, int by) {
  return sum[bx][by] - sum[bx][ay - 1] - sum[ax - 1][by] + sum[ax - 1][ay - 1];
}
int main() {
  scanf(" %d %d", &n, &m);
  for (int i = 1; i <= 5000; i++) {
    for (int j = 1; j <= 5000; j++) {
      if (i <= n && j <= m) {
        char tmp;
        scanf(" %1c", &tmp);
        if (tmp == '1') a[i][j] = true;
      }
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
      if (a[i][j]) sum[i][j]++;
    }
  }
  for (int i = 2; i <= 2500; i += 2) vis[i] = true;
  int ans = 0;
  int ans2 = 1e9;
  for (int i = 1; i <= n; i += 2)
    for (int j = 1; j <= m; j += 2) {
      int x1 = 0, x2 = 0;
      for (int b = i; b < i + 2; b++) {
        for (int c = j; c < j + 2; c++) {
          if (a[b][c])
            x1++;
          else
            x2++;
        }
      }
      ans += min(x1, x2);
    }
  for (int first = 3; first <= 2500; first += 2) {
    if (vis[first]) continue;
    for (int xx = first * first; xx <= 2500; xx += first) vis[xx] = true;
    int ca = 0;
    for (int i = 1; i <= n; i += first) {
      for (int j = 1; j <= m; j += first) {
        int cn = getSum(i, j, i + first, j + first);
        ca += min(first * first - cn, cn);
      }
    }
    ans2 = min(ans2, ca);
  }
  printf("%d\n", min(ans, ans2));
}
