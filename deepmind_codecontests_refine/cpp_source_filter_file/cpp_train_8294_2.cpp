#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
const int maxn = 1000000 + 5;
int finv[maxn], fra[maxn], pow3[maxn], pow_3[maxn];
int n;
int pow_mod(int x, int y) {
  int ans = 1;
  for (x %= M; y; y >>= 1, x = 1ll * x * x % M)
    if (y & 1) ans = 1ll * ans * x % M;
  return ans;
}
int C(int n, int m) { return 1ll * fra[n] * finv[m] % M * finv[n - m] % M; }
void Mod(int& x) {
  if (x >= M) x -= M;
  if (x < 0) x += M;
}
int main() {
  int i, j;
  fra[0] = fra[1] = finv[0] = 1;
  pow_3[0] = pow3[0] = 1;
  pow3[1] = 3;
  pow_3[1] = M - 3;
  cin >> n;
  for (i = 2; i <= 100000; i++) {
    fra[i] = 1ll * fra[i - 1] * i % M;
    pow3[i] = 1ll * pow3[i - 1] * 3 % M;
    pow_3[i] = (i & 1) ? M - pow3[i] : pow3[i];
  }
  for (i = 2; i <= n; i++) finv[i] = 1ll * finv[i - 1] * finv[i] % M;
  finv[n] = pow_mod(fra[n], M - 2);
  for (i = n - 1; i > 0; i--) finv[i] = 1ll * finv[i + 1] * (i + 1) % M;
  int f, ans1 = 0, ans2 = 0;
  for (i = 0, f = -1; i <= n; i++) {
    ans1 += 1ll * C(n, i) * pow3[i] % M * pow_mod(pow3[n], n - i) % M * f;
    Mod(ans1);
    f = -f;
  }
  ans1 = (2ll * ans1 % M + 2ll * pow_mod(pow3[n], n) % M) % M;
  for (i = 0, f = -1; i < n; i++) {
    ans2 +=
        1ll * C(n, i) *
        (1ll * pow_mod(1 + M - pow3[i], n) + M - pow_mod(M - pow3[i], n) % M) %
        M * f;
    Mod(ans2);
    f = -f;
  }
  cout << (3ll * ans2 % M + ans1) % M << endl;
  return 0;
}
