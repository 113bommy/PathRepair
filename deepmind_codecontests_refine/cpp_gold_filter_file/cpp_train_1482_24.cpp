#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
inline int read() {
  int x = 0, neg = 1;
  char op = getchar();
  while (!isdigit(op)) {
    if (op == '-') neg = -1;
    op = getchar();
  }
  while (isdigit(op)) {
    x = 10 * x + op - '0';
    op = getchar();
  }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
const int N = 55;
const int M = 20005;
deque<pair<int, int>> dLeft, dRight;
int a[N][M], sum[N][M];
int f[N][M], pre[M], suf[M];
int n, m, k;
int main() {
  n = read(), m = read(), k = read();
  for (register int i = 1; i <= n; i++) {
    for (register int j = 1; j <= m; j++) {
      a[i][j] = read();
      sum[i][j] = sum[i][j - 1] + a[i][j];
    }
  }
  for (register int i = 1; i <= m - k + 1; i++) {
    f[1][i] =
        sum[1][i + k - 1] - sum[1][i - 1] + sum[2][i + k - 1] - sum[2][i - 1];
  }
  for (register int i = 2; i <= n; i++) {
    for (register int j = 1; j <= m - k + 1; j++)
      pre[j] = max(pre[j - 1], f[i - 1][j]);
    for (register int j = m - k + 1; j >= 1; j--)
      suf[j] = max(suf[j + 1], f[i - 1][j]);
    while (!dLeft.empty()) dLeft.pop_back();
    while (!dRight.empty()) dRight.pop_back();
    for (register int j = 1; j <= min(k - 1, m - k + 1); j++) {
      while (!dRight.empty() &&
             f[i - 1][j] + sum[i][j - 1] >= dRight.back().second)
        dRight.pop_back();
      dRight.push_back(make_pair(j, f[i - 1][j] + sum[i][j - 1]));
    }
    for (register int j = 1; j <= m - k + 1; j++) {
      int ext =
          max(j > k ? pre[j - k] : 0, j + k <= m - k + 1 ? suf[j + k] : 0) +
          sum[i][j + k - 1] - sum[i][j - 1];
      while (!dLeft.empty() &&
             f[i - 1][j] - sum[i][j + k - 1] >= dLeft.back().second)
        dLeft.pop_back();
      dLeft.push_back(make_pair(j, f[i - 1][j] - sum[i][j + k - 1]));
      if (j > k && dLeft.front().first == j - k) dLeft.pop_front();
      int pans =
          dLeft.empty() ? -1e9 : dLeft.front().second + sum[i][j + k - 1];
      if (j + k - 1 <= m - k + 1) {
        int p = j + k - 1;
        while (!dRight.empty() &&
               f[i - 1][p] + sum[i][p - 1] >= dRight.back().second)
          dRight.pop_back();
        dRight.push_back(make_pair(p, f[i - 1][p] + sum[i][p - 1]));
      }
      if (dRight.front().first == j) dRight.pop_front();
      int qans = dRight.empty() ? -1e9 : dRight.front().second - sum[i][j - 1];
      f[i][j] =
          max({ext, pans, qans}) + sum[i + 1][j + k - 1] - sum[i + 1][j - 1];
    }
  }
  printf("%d\n", *max_element(f[n] + 1, f[n] + m - k + 2));
  return 0;
}
