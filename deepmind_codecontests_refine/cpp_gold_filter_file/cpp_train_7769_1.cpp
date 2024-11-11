#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000 * 1000 * 1000 + 7;
int mul(long long a, long long b) { return (a * b) % MOD; }
int inv(int x) {
  int y = MOD - 2;
  int ret = 1, base = x;
  for (int i = 0; y >> i; i++) {
    if ((y >> i) & 1) ret = mul(ret, base);
    base = mul(base, base);
  }
  assert(mul(x, ret) == 1);
  return ret;
}
int k, pa, push_back;
int c, mc, t1, t2;
int pd[1010][1010];
int solve(int a, int r) {
  if (a >= r) {
    int at1 = mul(a, t1);
    return mul(mc, (at1 + t2) % MOD);
  }
  if (pd[a][r] != -1) return pd[a][r];
  return pd[a][r] =
             (mul(c, solve(a + 1, r)) + mul(mc, a + solve(a, r - a))) % MOD;
}
int main() {
  scanf("%d %d %d", &k, &pa, &push_back);
  c = mul(pa, inv(pa + push_back));
  mc = mul(push_back, inv(pa + push_back));
  t1 = inv(mc);
  t2 = mul(c, inv(mul(MOD + c - 1, MOD + c - 1)));
  memset(pd, -1, sizeof(pd));
  printf("%d\n", solve(1, k));
  return 0;
}
