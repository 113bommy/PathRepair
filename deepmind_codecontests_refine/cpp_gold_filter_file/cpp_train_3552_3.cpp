#include <bits/stdc++.h>
long long ans;
const int mod = 998244353;
const int b = 97;
int pw[505], p[556], n, m, sum[305][305][26], s[556];
int str[1006];
char w[505][505];
int manacher(int *s, int n) {
  int ans = 0;
  std::memset(p, 0, sizeof(p));
  std::memset(str, 0, sizeof(str));
  str[0] = -1;
  str[1] = -1;
  for (int i = 0; i < n; i++)
    str[(i << 1) + 2] = s[i + 1], str[(i << 1) + 3] = -1;
  n = (n << 1) + 2;
  str[n] = -10;
  int mx = 0, id;
  for (int i = n; str[i] != 0; i++) str[i] = -10;
  for (int i = 1; i < n; i++) {
    if (mx > i)
      p[i] = std::min(p[2 * id - i], p[id] + id - i);
    else
      p[i] = 1;
    for (; str[i + p[i]] == str[i - p[i]]; ++p[i])
      ;
    if (p[i] + i > mx) {
      mx = p[i] + i;
      id = i;
    }
  }
  for (int i = 0; i < n; ++i)
    if (str[i] >= -20) ans += p[i] / 2;
  return ans;
}
int dec(int x) { return x >= mod ? x - mod : x; }
int main() {
  scanf("%d%d", &n, &m);
  pw[0] = 1;
  for (int i = 1; i < 26; ++i) pw[i] = (long long)pw[i - 1] * b % mod;
  for (int i = 1; i <= n; ++i) scanf("%s", w[i] + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int k = 0; k < 26; ++k) sum[i][j][k] = sum[i][j - 1][k];
      sum[i][j][w[i][j] - 'a']++;
    }
  }
  for (int l = 1; l <= m; ++l)
    for (int r = l; r <= m; ++r) {
      int nl = -20;
      for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        s[i] = 0;
        for (int k = 0; k < 26; ++k) {
          cnt += (sum[i][r][k] - sum[i][l - 1][k]) & 1;
          s[i] = dec(s[i] + (long long)pw[k] *
                                (sum[i][r][k] - sum[i][l - 1][k]) % mod);
        }
        if (cnt > 1) s[i] = --nl;
      }
      ans += manacher(s, n);
    }
  printf("%lld", ans);
  return 0;
}
