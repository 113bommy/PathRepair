#include <bits/stdc++.h>
using namespace std;
int fac[2000010], inv[2000010], sum[2][2000010], many[4][2000010], many1, ans,
    n;
char str[2000010];
int C(int n, int m) {
  return 1ll * fac[n] * inv[m] % 998244353 * inv[n - m] % 998244353;
}
int qpow(int x, int y) {
  int tmp = 1;
  while (y) {
    if (y & 1) tmp = 1ll * x * tmp % 998244353;
    y >>= 1, x = 1ll * x * x % 998244353;
  }
  return tmp;
}
int main() {
  scanf("%s", str + 1), n = strlen(str + 1);
  for (int i = 1; i <= n; i++) many1 += str[i] == '?';
  for (int i = 1; i <= n; i++)
    many[0][i] = many[0][i - 1] + (str[i] == '('),
    many[1][i] = many[1][i - 1] + (str[i] == '?');
  for (int i = n; i; i--)
    many[2][i] = many[2][i + 1] + (str[i] == ')'),
    many[3][i] = many[3][i + 1] + (str[i] == '?');
  for (int i = fac[0] = 1; i <= n; i++)
    fac[i] = 1ll * fac[i - 1] * i % 998244353;
  for (int i = inv[0] = 1; i <= n; i++) inv[i] = qpow(fac[i], 998244353 - 2);
  for (int i = 1; i <= many1 + 1; i++)
    sum[1][i] = (sum[1][i - 1] + C(many1, i - 1)) % 998244353;
  for (int i = 1; i <= many1; i++)
    sum[0][i] = (sum[0][i - 1] + C(many1 - 1, i - 1)) % 998244353;
  for (int i = 1; i <= n; i++)
    if (str[i] == '(')
      (ans += sum[1][min(many[2][i + 1] - many[0][i - 1] + many[3][i + 1],
                         many1 + 1)]) %= 998244353;
  for (int i = 1; i <= n; i++)
    if (str[i] == '?')
      (ans +=
       sum[0][min(many[2][i + 1] - many[0][i - 1] + many[3][i + 1], many1)]) %=
          998244353;
  printf("%d\n", (ans + 998244353) % 998244353);
}
