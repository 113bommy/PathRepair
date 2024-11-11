#include <bits/stdc++.h>
using namespace std;
long long n, k, l, MOD;
long long ans = 1, a, b, a1, b1;
struct mat {
  long long d[2][2];
  mat() { d[0][0] = d[0][1] = d[1][0] = d[1][1] = 0; }
  void init(int a, int b, int c, int D) {
    d[0][0] = a, d[0][1] = b;
    d[1][0] = c, d[1][1] = D;
  }
  mat operator*(const mat& B) {
    mat C;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
          C.d[i][j] = (C.d[i][j] + d[i][k] * B.d[k][j]) % MOD;
    return C;
  }
};
long long po(long long base, long long p) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base) % MOD;
    base = (base * base) % MOD;
    p /= 2;
  }
  return ans;
}
mat mpo(mat base, long long p) {
  mat ans;
  ans.init(1, 0, 0, 1);
  while (p) {
    if (p & 1) ans = ans * base;
    base = base * base;
    p /= 2;
  }
  return ans;
}
void gen() {
  mat A;
  A.init(0, 0, 1, 0);
  mat base;
  base.init(1, 1, 1, 0);
  A = mpo(base, n + 2) * A;
  a = A.d[0][0];
  b = (po(2, n) - a + MOD) % MOD;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> l >> MOD;
  if (l != 64 && (1LL << l) <= k) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < l; i++)
    if (k & (1LL << i))
      b1++;
    else
      a1++;
  gen();
  for (int i = 0; i < a1; i++) ans = (ans * a) % MOD;
  for (int i = 0; i < b1; i++) ans = (ans * b) % MOD;
  cout << ans % MOD;
}
