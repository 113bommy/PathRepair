#include <bits/stdc++.h>
long long MOD = 1000000007;
long long C[2000 + 200][2000 + 200];
int pos = 0;
bool notfree[2000 + 200];
int n;
void combin() {
  C[0][0] = 1;
  for (int i = 1; i <= 2000; i++) {
    C[0][i] = 1;
    C[i][i] = 1;
    for (int j = 1; j < i; j++) C[j][i] = (C[j][i - 1] + C[j - 1][i - 1]) % MOD;
  }
}
long long f[2000 + 200];
int cpos = 0;
void init() {
  f[0] = 1;
  for (int i = 1; i <= 2000; i++) f[i] = (f[i - 1] * i) % MOD;
}
int a[2000 + 200];
void fix(long long &n) {
  if (n < 0) n += MOD;
}
void solve() {
  for (int i = 1; i <= n; i++)
    if (a[i] != -1) notfree[a[i]] = true;
  for (int i = 1; i <= n; i++)
    if (a[i] == -1) pos++;
  for (int i = 1; i <= n; i++)
    if (a[i] == -1 && !notfree[i]) cpos++;
  init();
  long long res = 0;
  for (int i = 1; i <= cpos; i++) {
    if (i % 2)
      res = (res + C[i][cpos] * f[pos - i]) % MOD;
    else {
      res = (res - C[i][cpos] * f[pos - i]) % MOD;
      fix(res);
    }
  }
  res = (f[pos] - res) % MOD;
  fix(res);
  printf("%I64d", res);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  combin();
  solve();
}
