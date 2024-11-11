#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2010;
const int MOD = int(1e9) + 7;
int add(int a, int b) {
  if ((a += b) >= MOD) a -= MOD;
  return a;
}
int mul(int a, int b) { return a * 1ll * b % MOD; }
int mpow(int a, int p) {
  int res = 1;
  while (p > 0) {
    if (p & 1) res = mul(res, a);
    a = mul(a, a);
    p /= 2;
  }
  return res;
}
int fact[MAXN];
int inv_fact[MAXN];
bool used[MAXN];
bool stand[MAXN];
int n;
int C(int n, int k) { return mul(fact[n], mul(inv_fact[k], inv_fact[n - k])); }
int main() {
  memset(used, false, sizeof used);
  memset(stand, false, sizeof stand);
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fact[i] = mul(fact[i - 1], i);
    inv_fact[i] = mpow(fact[i], MOD - 2);
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    if (a != -1) {
      a--;
      stand[i] = true;
      used[a] = true;
    }
  }
  int all = 0;
  int bad = 0;
  for (int i = 0; i < n; i++)
    if (!used[i]) {
      all++;
      if (stand[i]) {
        bad++;
      }
    }
  int res = 0;
  for (int cnt_bad = 1; cnt_bad <= bad; cnt_bad++) {
    int cur = mul(C(all, cnt_bad), fact[all - cnt_bad]);
    if (cnt_bad & 1)
      res = add(res, cur);
    else
      res = add(res, -cur + MOD);
  }
  printf("%d\n", add(fact[all], -res + MOD));
  return 0;
}
