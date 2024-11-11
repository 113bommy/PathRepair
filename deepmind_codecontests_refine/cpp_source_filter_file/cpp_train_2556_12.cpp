#include <bits/stdc++.h>
inline int Min(const int a, const int b) { return a < b ? a : b; }
inline int Max(const int a, const int b) { return a > b ? a : b; }
inline void CMin(int &x, const int y) { x > y ? x = y : 0; }
int n, Ans, f[10][260], Add[100005];
int d[10][10], Dis[100005][10];
char s[100005];
long long Cnt;
int main() {
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; ++i) s[i] -= 'a';
  for (int i = 0; i <= 7; ++i)
    for (int j = 0; j <= 7; ++j) d[i][j] = i == j ? 0 : n;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= 7; ++j) Dis[i][j] = s[i] == j ? 0 : n;
  for (int k = 0; k <= 7; ++k) {
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j <= 7; ++j) {
        if (i != 1) CMin(Dis[i][j], Dis[i - 1][j] + 1);
        if (i != n) CMin(Dis[i][j], Dis[i + 1][j] + 1);
      }
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j <= 7; ++j) CMin(d[(int)s[i]][j], Dis[i][j]);
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j <= 7; ++j) CMin(Dis[i][j], d[(int)s[i]][j] + 1);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 7; ++j)
      if (d[(int)s[i]][j] < Dis[i][j]) Add[i] |= 1 << j;
  for (int i = 1; i <= n; ++i) {
    for (int j = Max(1, i - 15); j <= i - 1; ++j) {
      int Mind = i - j;
      for (int k = 0; k <= 7; ++k) CMin(Mind, Dis[i][k] + Dis[j][k] + 1);
      if (Ans < Mind) Ans = Mind, Cnt = 0;
      Cnt += Ans == Mind;
    }
    if (i <= 16) continue;
    ++f[(int)s[i - 16]][Add[i - 16]];
    for (int c = 0; c <= 7; ++c)
      for (int j = 0; j < (1 << 8); ++j)
        if (f[c][j]) {
          int Mind = n;
          for (int k = 0; k <= 7; ++k)
            CMin(Mind, Dis[i][k] + d[c][k] + 1 + (j >> k & 1));
          if (Ans < Mind) Ans = Mind, Cnt = 0;
          Cnt += (Ans == Mind) * f[c][j];
        }
  }
  std::cout << Ans << ' ' << Cnt << std::endl;
  return 0;
}
