#include <bits/stdc++.h>
const int md = 998244353;
inline int add(int a, int b) {
  a += b;
  if (a >= md) a -= md;
  return a;
}
inline int sub(int a, int b) {
  a -= b;
  if (a < 0) a += md;
  return a;
}
const int N = 100000;
const int K = 100;
int n, k, len, a[N + 1], dp[N + 1][K], s[N + 1], amt[K];
int main() {
  scanf("%d%d%d", &n, &k, &len);
  s[0] = 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    --a[i];
    if (i - len > 0 && a[i - len] != -2) --amt[a[i - len]];
    if (a[i] == -2) {
      int r = -1;
      int b = 0;
      for (int j = 0; j < k; ++j)
        if (amt[j]) {
          if (r == -1) {
            r = j;
            b = 1;
          } else
            b = 2;
        }
      if (b == 2 || i - len < 0) {
        for (int j = 0; j < k; ++j) {
          dp[i][j] = s[i - 1];
          s[i] = add(s[i], dp[i][j]);
        }
      } else if (b == 1) {
        for (int j = 0; j < k; ++j) {
          if (j != r)
            dp[i][j] = s[i - 1];
          else
            dp[i][j] = sub(s[i - 1], sub(s[i - len], dp[i - len][j]));
          s[i] = add(s[i], dp[i][j]);
        }
      } else {
        for (int j = 0; j < k; ++j) {
          dp[i][j] = sub(s[i - 1], sub(s[i - len], dp[i - len][j]));
          s[i] = add(s[i], dp[i][j]);
        }
      }
    } else {
      int r = -1;
      int b = 0;
      for (int j = 0; j < k; ++j)
        if (amt[j]) {
          if (r == -1) {
            r = j;
            b = 1;
          } else
            b = 2;
        }
      if (b == 2 || i - len < 0 || r != a[i])
        dp[i][a[i]] = s[i] = s[i - 1];
      else
        dp[i][a[i]] = s[i] = sub(s[i - 1], sub(s[i - len], dp[i - len][a[i]]));
      ++amt[a[i]];
    }
  }
  printf("%d\n", s[n]);
  return 0;
}
