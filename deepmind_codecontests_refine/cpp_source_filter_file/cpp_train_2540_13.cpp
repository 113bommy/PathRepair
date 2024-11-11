#include <bits/stdc++.h>
const int MAXN = 2010;
const int MOD = 1000000007;
long long c[MAXN][MAXN];
long long f[MAXN];
int a[MAXN];
int v[MAXN];
void init() {
  c[0][0] = 1;
  for (int i = 1; i < MAXN; i++) {
    c[i][0] = 1;
    for (int j = 1; j < i; j++) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
      c[i][j] %= MOD;
    }
    c[i][i] = 1;
  }
  f[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    f[i] = f[i - 1] * i;
    f[i] %= MOD;
  }
}
int main() {
  init();
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", a + i);
    if (a[i] > 0) {
      v[a[i]] = 1;
    }
  }
  int k = 0, n = 0;
  for (int i = 0; i < m; i++) {
    if (a[i] == -1) {
      n++;
      if (v[a[i]] == 0) {
        k++;
      }
    }
  }
  long long ans = 0, flip = 1;
  for (int i = 0; i <= k; i++) {
    ans += flip * c[k][i] * f[n - i];
    ans %= MOD;
    flip *= -1;
  }
  ans = (ans + MOD) % MOD;
  printf("%d\n", (int)ans);
}
