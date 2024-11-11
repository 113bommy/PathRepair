#include <bits/stdc++.h>
using namespace std;
const int MaxN = 4010, Mod = 1e9 + 7;
int p, b;
char s[MaxN];
int len;
long long ta[MaxN];
int a[MaxN], n;
void init() {
  scanf("%d %d", &p, &b);
  scanf("%s", s + 1);
  len = strlen(s + 1);
  for (int i = 1; i <= len; i++) ta[i] = s[i] - '0';
  reverse(ta + 1, ta + len + 1);
  while (!(len == 1 && ta[1] == 0)) {
    ta[0] = 0;
    for (int i = len; i; i--) {
      ta[i - 1] += (long long)(ta[i] % p) * 10;
      ta[i] /= p;
    }
    while (len > 1 && ta[len] == 0) len--;
    a[n++] = ta[0] / 10;
  }
  reverse(a, a + n);
}
int f[2][MaxN][2][2];
bool d, nxt, now;
void dp() {
  if (b > n) {
    puts("0");
    return;
  }
  f[0][0][0][1] = 1;
  for (int i = 0; i <= n - 1; i++) {
    d ^= 1;
    memset(f[d], 0, sizeof(f[d]));
    nxt = d;
    now = d ^ 1;
    for (int j = 0; j <= i; j++)
      for (int k = 0; k <= 1; k++)
        for (int k0 = 0; k0 <= 1; k0++)
          if (f[now][j][k][k0])
            for (int l = 0; l <= 1; l++)
              for (int l0 = 0; l0 <= k0; l0++) {
                int cnt, sum, mul;
                if (k0) {
                  if (l0)
                    cnt = 1, sum = a[i];
                  else
                    cnt = a[i], sum = ((long long)a[i] * (a[i] - 1) / 2) % Mod;
                } else
                  cnt = p, sum = ((long long)p * (p - 1) / 2) % Mod;
                if (k)
                  mul = ((long long)cnt * p - (sum + (!l) * cnt) % Mod + Mod) %
                        Mod;
                else
                  mul = (sum + (!l) * cnt) % Mod;
                (f[nxt][j + l][l][l0] +=
                 (long long)mul * f[now][j][k][k0] % Mod) %= Mod;
              }
  }
  int ans = 0;
  for (int i = b; i <= n; i++)
    for (int k0 = 0; k0 <= 1; k0++) (ans += f[d][i][0][k0]) %= Mod;
  printf("%d\n", ans);
}
int main() {
  init();
  dp();
  return 0;
}
