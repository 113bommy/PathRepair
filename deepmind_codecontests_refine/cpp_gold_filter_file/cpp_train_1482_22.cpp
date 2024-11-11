#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x) {
  x = 0;
  char c = getchar();
  bool f = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0) {
    putchar('-'), write(-x);
  } else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const int N = 55, M = 2e4 + 5;
int n, m, k, a[N][M], sum[N][M], f[N][M], ans, suf[N][M], pre[N][M], pos[N][M],
    neg[N][M];
inline int min(const int &x, const int &y) { return x < y ? x : y; }
inline int max(const int &x, const int &y) { return x > y ? x : y; }
signed main() {
  read(n);
  read(m);
  read(k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      read(a[i][j]), sum[i][j] = sum[i][j - 1] + a[i][j];
  for (int i = 1; i + k - 1 <= m; i++)
    f[1][i] =
        sum[1][i + k - 1] - sum[1][i - 1] + sum[2][i + k - 1] - sum[2][i - 1];
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      pre[i - 1][j] = max(pre[i - 1][j - 1], f[i - 1][j]);
    for (int j = m; j; j--) suf[i - 1][j] = max(suf[i - 1][j + 1], f[i - 1][j]);
    deque<int> q;
    for (int j = 1; j + k - 1 <= m; j++) {
      while (!q.empty() && q[0] < j - k + 1) q.pop_front();
      while (!q.empty() && f[i - 1][q[0]] - sum[i][q[0] + k - 1] <=
                               f[i - 1][j] - sum[i][j + k - 1])
        q.pop_back();
      q.push_back(j);
      pos[i - 1][j] = f[i - 1][q[0]] - sum[i][q[0] + k - 1];
    }
    while (!q.empty()) q.pop_back();
    for (int j = m - k + 1; j; j--) {
      while (!q.empty() && q[0] > j + k - 1) q.pop_front();
      while (!q.empty() &&
             f[i - 1][q[0]] + sum[i][q[0] - 1] <= f[i - 1][j] + sum[i][j - 1])
        q.pop_back();
      q.push_back(j);
      neg[i - 1][j] = f[i - 1][q[0]] + sum[i][q[0] - 1];
    }
    for (int j = 1; j + k - 1 <= m; j++) {
      f[i][j] = max(pre[i - 1][max(0, j - k)], suf[i - 1][j + k]) +
                sum[i][j + k - 1] - sum[i][j - 1];
      for (int l = j - k + 1; l <= j; l++)
        if (l >= 0)
          f[i][j] =
              max(f[i][j], f[i - 1][l] + sum[i][j + k - 1] - sum[i][l + k - 1]);
      for (int l = j + 1; l <= j + k - 1; l++)
        if (l <= m)
          f[i][j] = max(f[i][j], f[i - 1][l] - sum[i][j - 1] + sum[i][l - 1]);
      f[i][j] += sum[i + 1][j + k - 1] - sum[i + 1][j - 1];
    }
  }
  for (int i = 1; i + k - 1 <= m; i++) ans = max(ans, f[n][i]);
  write(ans);
}
