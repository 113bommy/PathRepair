#include <bits/stdc++.h>
const int MOD = 998244353;
const int MAXN = 2000 + 10;
int n, a, b;
inline int mul(int a, int b) { return 1ll * a * b % MOD; }
inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}
inline int sub(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}
int pwr(int base, int exp) {
  int ans = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) ans = mul(ans, base);
    base = mul(base, base);
  }
  return ans;
}
int inv(int x) { return pwr(x, MOD - 2); }
namespace solver1 {
int f[MAXN], scc[MAXN], win[MAXN][MAXN];
void main() {
  int p = mul(a, inv(b));
  win[1][0] = win[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    win[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      win[i][j] = add(mul(win[i - 1][j - 1], pwr(p, i - j)),
                      mul(win[i - 1][j], pwr(sub(1, p), j)));
    }
  }
  scc[1] = 1;
  for (int i = 2; i <= n; i++) {
    scc[i] = 1;
    for (int j = 1; j < i; j++) {
      scc[i] = sub(scc[i], mul(scc[j], win[i][j]));
    }
  }
  f[0] = f[1] = 0;
  for (int i = 2; i <= n; i++) {
    int sum = 0;
    for (int j = 1; j < i; j++) {
      sum = add(sum, mul(scc[j],
                         mul(win[i][j], add(add(j * (j - 1) / 2, mul(j, i - j)),
                                            add(f[j], f[i - j])))));
    }
    sum = add(sum, mul(mul(scc[i], win[i][i]), i * (i - 1) / 2));
    f[i] = mul(sum, inv(sub(1, mul(scc[i], win[i][i]))));
  }
  printf("%d", f[n]);
}
}  // namespace solver1
int main() {
  scanf("%d%d%d", &n, &a, &b);
  solver1::main();
}
