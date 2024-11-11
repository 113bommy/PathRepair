#include <bits/stdc++.h>
char S[3][2010];
int F[2010][2010], G[2010][2010], le[3];
unsigned long long mi[2010], ha[3][2010], hf[3][2010];
unsigned long long getha(int i, int l, int r) {
  if (l == 0) return ha[i][r];
  return ha[i][r] - ha[i][l - 1] * mi[r - l + 1];
}
unsigned long long gethf(int i, int l, int r) {
  return hf[i][l] - hf[i][r + 1] * mi[r - l + 1];
}
int zz[2][2010][2010], dp[2010][2010][2][2];
void rev(char zf[2010]) {
  int n = strlen(zf);
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    char t = zf[i];
    zf[i] = zf[j];
    zf[j] = t;
  }
}
int solve() {
  int n = strlen(S[0]), k = strlen(S[2]);
  int m = n;
  if (k > m) m = k;
  mi[0] = 1;
  le[0] = le[1] = n;
  le[2] = k;
  for (int i = 1; i <= m; i++) mi[i] = mi[i - 1] * 13131;
  for (int i = 0; i < 3; i++) {
    unsigned long long h = 0;
    for (int j = 0; j < le[i]; j++) {
      h = h * 13131 + S[i][j];
      ha[i][j] = h;
    }
    h = 0;
    for (int j = le[i] - 1; j >= 0; j--) {
      h = h * 13131 + S[i][j];
      hf[i][j] = h;
    }
  }
  for (int x = 0; x < n; x++) {
    for (int y = x; y < n; y++) {
      F[x][y] = false;
      if (y - x >= k || gethf(2, k - 1 + x - y, k - 1) != getha(0, x, y))
        continue;
      F[x][y] =
          (k - 2 + x + x - y - y >= 0 &&
           getha(2, k - 2 + x + x - y - y, k - 2 + x - y) == getha(1, x, y));
    }
    for (int y = 0; y < x; y++) {
      F[x][y] = false;
      if (x - y >= k || getha(2, 0, x - y) != gethf(0, y, x)) continue;
      F[x][y] = (x - y + 1 + x - y < k &&
                 getha(2, x - y + 1, x - y + 1 + x - y) == getha(1, y, x));
    }
  }
  for (int x = 0; x < n; x++) {
    for (int y = x; y < n; y++) {
      G[x][y] = false;
      if (y - x >= k || gethf(2, k - 1 + x - y, k - 1) != getha(1, x, y))
        continue;
      G[x][y] =
          (k - 2 + x + x - y - y >= 0 &&
           getha(2, k - 2 + x + x - y - y, k - 2 + x - y) == getha(0, x, y));
    }
    for (int y = 0; y < x; y++) {
      G[x][y] = false;
      if (x - y >= k || getha(2, 0, x - y) != gethf(1, y, x)) continue;
      G[x][y] = (x - y + 1 + x - y < k &&
                 getha(2, x - y + 1, x - y + 1 + x - y) == getha(0, y, x));
    }
  }
  for (int x = 0; x < n; x++) {
    for (int j = 0; j < k; j++) zz[0][x][j] = zz[1][x][j] = 0;
  }
  for (int x = 0; x < n; x++) {
    for (int y = x + 1; y < n; y++) {
      if (F[x][y]) zz[1][x][k - ((y - x + 1) + (y - x + 1))] += 1;
      if (G[x][y]) zz[0][x][k - ((y - x + 1) + (y - x + 1))] += 1;
    }
  }
  for (int i = n; i >= 0; i--) {
    for (int j = k; j >= 0; j--) {
      for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          dp[i][j][a][b] = 0;
          if (j == k) {
            dp[i][j][a][b] = (b == 0);
            continue;
          }
          if (i == n) continue;
          if (b == 0) {
            dp[i][j][a][b] = zz[a][i][j];
            if (S[a][i] == S[2][j]) {
              dp[i][j][a][b] =
                  (dp[i][j][a][b] + dp[i][j + 1][a ^ 1][1]) % 1000000007;
              dp[i][j][a][b] =
                  (dp[i][j][a][b] + dp[i + 1][j + 1][a][0]) % 1000000007;
            }
          } else if (S[a][i] == S[2][j])
            dp[i][j][a][b] = dp[i + 1][j + 1][a][0];
        }
      }
    }
  }
  int ans = 0;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < x; y++) {
      if (F[x][y] && (x - y + 1) * 2 < k)
        ans = (ans + dp[x + 1][(x - y + 1) * 2][1][0]) % 1000000007;
      if (G[x][y] && (x - y + 1) * 2 < k)
        ans = (ans + dp[x + 1][(x - y + 1) * 2][0][0]) % 1000000007;
    }
  }
  for (int i = 0; i < n; i++) {
    ans = (ans + dp[i][0][0][0]) % 1000000007;
    ans = (ans + dp[i][0][1][0]) % 1000000007;
  }
  return ans;
}
int main() {
  int n, k;
  scanf("%s%s%s", S[0], S[1], S[2]);
  n = strlen(S[0]);
  k = strlen(S[2]);
  if (k == 1) {
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans += (S[0][i] == S[2][0]) + (S[1][i] == S[2][0]);
    printf("%d", ans);
    return 0;
  }
  if (k == 2) {
    int ans = 0;
    char a = S[2][0], b = S[2][1];
    for (int i = 0; i < n; i++) {
      if (S[0][i] == a && S[1][i] == b) ans += 1;
      if (S[1][i] == a && S[0][i] == b) ans += 1;
      if (i + 1 < n) {
        if (S[0][i] == a && S[0][i + 1] == b) ans += 1;
        if (S[1][i] == a && S[1][i + 1] == b) ans += 1;
      }
      if (i > 0) {
        if (S[0][i] == a && S[0][i - 1] == b) ans += 1;
        if (S[1][i] == a && S[1][i - 1] == b) ans += 1;
      }
    }
    printf("%d", ans);
    return 0;
  }
  int ans = solve();
  for (int i = 0; i < 2; i++) rev(S[i]);
  ans = (ans + solve()) % 1000000007;
  printf("%d", ans);
  return 0;
}
