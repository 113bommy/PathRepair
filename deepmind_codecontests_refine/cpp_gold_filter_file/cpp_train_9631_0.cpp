#include <bits/stdc++.h>
using namespace std;
inline void add(int &x, int y) {
  ((x += y) >= 1000000007) ? x -= 1000000007 : 0;
}
char s1[2005], s2[2005], s3[2005];
int lcp[2005][2005][2][2];
void pre(int n, int m) {
  for (int i = n; i > 0; i--) {
    for (int j = 1; j <= m; j++) {
      lcp[i][j][0][0] = ((s1[i] == s2[j]) ? lcp[i + 1][j - 1][0][0] + 1 : 0);
      lcp[i][j][1][0] = ((s1[i] == s3[j]) ? lcp[i + 1][j - 1][1][0] + 1 : 0);
      lcp[i][j][0][1] = ((s1[i] == s2[j]) ? lcp[i + 1][j + 1][0][1] + 1 : 0);
      lcp[i][j][1][1] = ((s1[i] == s3[j]) ? lcp[i + 1][j + 1][1][1] + 1 : 0);
    }
  }
}
int f[2005][2005][2][2];
void dp(int n, int m) {
  for (int i = 0; i <= m + 1; i++)
    f[n + 1][i][0][0] = f[n + 1][i][0][1] = f[n + 1][i][1][0] =
        f[n + 1][i][1][1] = 1;
  for (int i = n; i > 0; i--) {
    for (int j = 1; j <= m; j++) {
      if (s1[i] == s2[j]) {
        add(f[i][j][0][0], f[i + 1][j - 1][0][0]);
        if (i < n - 1 && s1[i + 1] == s3[j])
          add(f[i][j][0][0], f[i + 2][j - 1][1][0]);
      }
      if (s1[i] == s3[j]) {
        add(f[i][j][1][0], f[i + 1][j - 1][1][0]);
        if (i < n - 1 && s1[i + 1] == s2[j])
          add(f[i][j][1][0], f[i + 2][j - 1][0][0]);
      }
    }
    for (int j = m; j > 0; j--) {
      if (s1[i] == s2[j]) {
        add(f[i][j][0][1], f[i + 1][j + 1][0][1]);
        if (i < n - 1 && s1[i + 1] == s3[j])
          add(f[i][j][0][1], f[i + 2][j + 1][1][1]);
      }
      if (s1[i] == s3[j]) {
        add(f[i][j][1][1], f[i + 1][j + 1][1][1]);
        if (i < n - 1 && s1[i + 1] == s2[j])
          add(f[i][j][1][1], f[i + 2][j + 1][0][1]);
      }
    }
    if ((n - i) & 1) {
      int len = ((n - i + 1) >> 1);
      for (int j = len; j <= m; j++) {
        if (lcp[i][j][0][0] >= len && lcp[i + len][j - len + 1][1][1] >= len)
          add(f[i][j][0][0], 1);
        if (lcp[i][j][1][0] >= len && lcp[i + len][j - len + 1][0][1] >= len)
          add(f[i][j][1][0], 1);
      }
      for (int j = m - len + 1; j > 0; j--) {
        if (lcp[i][j][0][1] >= len && lcp[i + len][j + len - 1][1][0] >= len)
          add(f[i][j][0][1], 1);
        if (lcp[i][j][1][1] >= len && lcp[i + len][j + len - 1][0][0] >= len)
          add(f[i][j][1][1], 1);
      }
    }
  }
}
int solve(int n, int m) {
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    if (lcp[1][i][0][0] >= n) add(ans, 1);
    if (lcp[1][i][1][0] >= n) add(ans, 1);
    if (lcp[1][i][0][1] >= n) add(ans, 1);
    if (lcp[1][i][1][1] >= n) add(ans, 1);
  }
  for (int i = 1; i <= m; i++) {
    if (s1[1] == s2[i]) {
      int t = lcp[1][i][0][1];
      for (int j = 1; j <= min(t, n - 1); j++)
        if (s1[j + 1] == s3[i + j - 1]) {
          if (j < n - 1) add(ans, f[j + 2][i + j][1][1]);
          if (n - j <= j) {
            if (lcp[j + 1][i + j - 1][1][0] >= n - j) add(ans, 1);
          } else if (lcp[j + 1][i + j - 1][1][0] >= j)
            add(ans, f[(j << 1) + 1][i - 1][1][0]);
        }
      t = lcp[1][i][0][0];
      for (int j = 2; j <= min(t, n - 1); j++)
        if (s1[j + 1] == s3[i - j + 1]) {
          if (j < n - 1) add(ans, f[j + 2][i - j][1][0]);
          if (n - j <= j) {
            if (lcp[j + 1][i - j + 1][1][1] >= n - j) add(ans, 1);
          } else if (lcp[j + 1][i - j + 1][1][1] >= j)
            add(ans, f[(j << 1) + 1][i + 1][1][1]);
        }
    }
    if (s1[1] == s3[i]) {
      int t = lcp[1][i][1][1];
      for (int j = 1; j <= min(t, n - 1); j++)
        if (s1[j + 1] == s2[i + j - 1]) {
          if (j < n - 1) add(ans, f[j + 2][i + j][0][1]);
          if (n - j <= j) {
            if (lcp[j + 1][i + j - 1][0][0] >= n - j) add(ans, 1);
          } else if (lcp[j + 1][i + j - 1][0][0] >= j)
            add(ans, f[(j << 1) + 1][i - 1][0][0]);
        }
      t = lcp[1][i][1][0];
      for (int j = 2; j <= min(t, n - 1); j++)
        if (s1[j + 1] == s2[i - j + 1]) {
          if (j < n - 1) add(ans, f[j + 2][i - j][0][0]);
          if (n - j <= j) {
            if (lcp[j + 1][i - j + 1][0][1] >= n - j) add(ans, 1);
          } else if (lcp[j + 1][i - j + 1][0][1] >= j)
            add(ans, f[(j << 1) + 1][i + 1][0][1]);
        }
    }
  }
  return ans;
}
int main() {
  scanf("%s%s%s", s2 + 1, s3 + 1, s1 + 1);
  int n = strlen(s1 + 1), m = strlen(s2 + 1);
  if (n == 1) {
    int ans = 0;
    for (int i = 1; i <= m; i++) {
      if (s2[i] == s1[1]) ans++;
      if (s3[i] == s1[1]) ans++;
    }
    printf("%d\n", ans);
    return 0;
  }
  pre(n, m);
  dp(n, m);
  printf("%d\n", solve(n, m));
  return 0;
}
