#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch - '0');
    ch = getchar();
  }
  return f * x;
}
const int maxn = 1e5 + 10, mod = 1e9 + 7, limit = 1e7;
int n, num[2][maxn], k[2];
int f[2][maxn], cnt[2][maxn], ans[2][maxn];
queue<pair<int, int> > q;
int main() {
  n = read();
  memset(ans, 127, sizeof(ans));
  k[0] = read();
  for (int i = 1; i <= k[0]; i++) num[0][i - 1] = read();
  k[1] = read();
  for (int i = 1; i <= k[1]; i++) num[1][i - 1] = read();
  ans[0][0] = ans[1][0] = 0;
  q.push(make_pair(0, 0));
  q.push(make_pair(1, 0));
  while (q.size()) {
    while (q.size()) {
      int x = q.front().first, y = q.front().second;
      q.pop();
      for (int i = 0; i < k[x ^ 1]; i++) {
        int x1 = x ^ 1, y1 = (y - num[x1][i] + n) % n;
        if (!ans[x1][y1] || ans[x1][y1] == 1) continue;
        ans[x1][y1] = 1;
        for (int j = 0; j < k[x]; j++) {
          int y2 = (y1 - num[x][j] + n) % n;
          ++cnt[x][y2];
        }
      }
    }
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < n; j++) {
        if (!ans[i][j] || ans[i][j] == 1) continue;
        if (cnt[i][j] == k[i]) {
          ans[i][j] = 0;
          q.push(make_pair(i, j));
        }
      }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j < n; j++) {
      if (ans[i][j] == 0)
        printf("Lose ");
      else if (ans[i][j] == 1)
        printf("Win ");
      else
        printf("Loop ");
    }
    puts("\n");
  }
  return 0;
}
