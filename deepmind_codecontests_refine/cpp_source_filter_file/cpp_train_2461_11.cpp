#include <bits/stdc++.h>
using namespace std;
inline int qr() {
  int x = 0, f = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    f |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return f ? -x : x;
}
const int mod = 1e9 + 7, N = 707;
int n;
int mi0[N], mi1[N];
char s[N];
long long f[N][N][2];
long long ans = 0;
int main() {
  scanf("%s", s + 1), n = strlen(s + 1);
  mi0[0] = 1;
  for (register int i = 1; i <= n; i++) {
    mi0[i] = mi0[i - 1] * 10 % mod;
    mi1[i] = (mi1[i - 1] * 10 + 1) % mod;
  }
  for (register int k = 1; k <= 9; k++) {
    memset(f, 0, sizeof f);
    f[0][0][1] = 1;
    for (register int i = 0; i < n; i++) {
      for (register int j = 0; j <= i; j++) {
        for (register int l = 0; l <= 9; l++) {
          f[i + 1][j + (l == k)][0] =
              (f[i + 1][j + (l == k)][0] + f[i][j][0] * mi0[l > k] % mod) % mod;
          if (l < s[i + 1] - '0') {
            f[i + 1][j + (l == k)][0] =
                (f[i + 1][j + (l == k)][0] + f[i][j][1] * mi0[l > k] % mod) %
                mod;
          } else if (l == s[i + 1] - '0') {
            f[i + 1][j + (l == k)][1] =
                (f[i + 1][j + (l == k)][1] + f[i][j][1] * mi0[l > k] % mod) %
                mod;
          }
        }
      }
    }
    for (register int j = 0; j <= n; j++) {
      ans = (ans + mi1[j] * (f[n][j][0] + f[n][j][1]) % mod * k % mod) % mod;
    }
  }
  printf("%lld", ans);
  return 0;
}
