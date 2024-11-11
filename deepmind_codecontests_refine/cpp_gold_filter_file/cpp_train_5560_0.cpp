#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2100;
const int MOD = 1000000007;
int pow(int a, int b) {
  if (!b) return 1;
  if (b & 1) return (pow(a, b - 1) * 1LL * a) % MOD;
  int temp = pow(a, b / 2);
  return (temp * 1LL * temp) % MOD;
}
int f[MAXN];
int invf[MAXN];
bool can[MAXN];
int cnk(int n, int k) {
  if (n < k) return 0;
  int res = f[n];
  res = (res * 1LL * invf[k]) % MOD;
  res = (res * 1LL * invf[n - k]) % MOD;
  return res;
}
int main() {
  f[0] = invf[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    f[i] = (f[i - 1] * 1LL * i) % MOD;
    invf[i] = pow(f[i], MOD - 2);
  }
  int n;
  int placed = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    --a;
    if (a != -2) {
      can[a] = can[i] = true;
      placed++;
      assert(a != i);
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) cnt += !can[i];
  int res = 0;
  for (int i = 0; i <= n - placed; i++) {
    int temp = cnk(cnt, i);
    temp = (temp * 1LL * f[n - placed - i]) % MOD;
    if ((i & 1) == 0)
      res = (res + temp) % MOD;
    else
      res = (res - temp + MOD) % MOD;
  }
  printf("%d\n", res);
  ;
  return 0;
}
