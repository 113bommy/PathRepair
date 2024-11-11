#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int sum = 0, f = 1;
  char ch = getchar();
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') ch = getchar(), f = -1;
  while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
  return sum * f;
}
const int mod = 998244353;
char s[3010], t[3010];
int lens, lent;
int f[3010][3010];
int ksm(int a, int b) {
  int sum = 1;
  while (b) {
    if (b & 1) sum = 1ll * sum * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return sum;
}
int main() {
  scanf("%s%s", &s[1], &t[1]);
  lens = strlen(&s[1]), lent = strlen(&t[1]);
  if (lens < lent) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= lent; i++)
    if (s[1] == t[i]) f[1][i] = 2;
  f[1][lent + 1] = 2;
  for (int i = 2; i <= lens; i++) {
    for (int j = 1; j <= lent; j++) {
      int len = lent - j + 1;
      if (len >= i) {
        if (s[i] == t[j + i - 1]) f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
        if (s[i] == t[j]) f[i][j] = (f[i][j] + f[i - 1][j + 1]) % mod;
      } else {
        f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
        if (s[i] == t[j]) f[i][j] = (f[i][j] + f[i - 1][j + 1]) % mod;
      }
    }
    f[i][lent + 1] = ksm(2, i);
  }
  int ans = 0;
  for (int i = lent; i <= lens; i++) ans = (ans + f[i][1]) % mod;
  cout << ans;
  return 0;
}
