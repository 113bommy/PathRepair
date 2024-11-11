#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
char s1[101010], s2[101010];
int fac[101010], ifac[101010], c[4], rl = 1;
int calc(int n, int m) {
  if (n < m || (m == 0 && n > 0) || m < 0) return 0;
  if (n == 0 && m == 0) return 1;
  n--;
  m--;
  return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int solve(char *s) {
  int l = strlen(s + 1);
  if (l < rl) return 0;
  int d0 = c[2], d1 = c[1] + 1, c0 = c[0] + d0, c1 = c[3] + d1;
  if (d1 < d0 || d1 > d0 + 1) return 0;
  if (l > rl) return 1ll * calc(c0, d0) * calc(c1, d1) % mod;
  s[0] = '0';
  int res = 0;
  for (int i = 1; i <= l; i++) {
    if (i != 1 && s[i] == '1') {
      if (s[i - 1] == '0')
        res = (res + 1ll * calc(c0, d0 + 1) * calc(c1, d1) % mod) % mod;
      else
        res = (res + 1ll * calc(c0, d0) * calc(c1, d1) % mod) % mod;
    }
    if (s[i] == '0') {
      c0--;
      d0 -= (s[i - 1] == '1');
    } else {
      c1--;
      d1 -= (s[i - 1] == '0');
    }
  }
  return res;
}
int main() {
  for (int i = fac[0] = 1; i <= 100000; i++)
    fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[0] = ifac[1] = 1;
  for (int i = 2; i <= 100000; i++)
    ifac[i] = 1ll * (mod - mod / i) * ifac[mod % i] % mod;
  for (int i = 2; i <= 100000; i++) ifac[i] = 1ll * ifac[i - 1] * ifac[i] % mod;
  scanf("%s", s1 + 1);
  scanf("%s", s2 + 1);
  s2[0] = '0';
  int h = strlen(s2 + 1);
  while (s2[h] == '1') {
    s2[h] = '0';
    h--;
  }
  s2[h]++;
  if (s2[0] == '1') {
    h = strlen(s2 + 1);
    for (int i = h + 1; i >= 1; i--) s2[i] = s2[i - 1];
  }
  for (int i = 0; i < 4; i++) {
    scanf("%d", &c[i]);
    rl += c[i];
  }
  printf("%d", (solve(s2) - solve(s1) + mod) % mod);
  return 0;
}
