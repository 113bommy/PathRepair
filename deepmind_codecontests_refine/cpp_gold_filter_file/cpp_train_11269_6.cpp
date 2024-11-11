#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
template <class T>
void Read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = 0;
  while (c < '0' || '9' < c) {
    if (c == '-') flag = 1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (flag) x = -x;
}
int fac[MAXN + 10], inv[MAXN + 10];
inline int ksm(int a, int p) {
  int ret = 1;
  while (p) {
    if (p & 1) ret = 1ll * ret * a % MOD;
    a = 1ll * a * a % MOD;
    p >>= 1;
  }
  return ret;
}
inline int P(int m, int n) { return 1ll * fac[m] * inv[m - n] % MOD; }
inline void init(int K, int W) {
  fac[0] = 1;
  for (int i = 1; i <= K; ++i) fac[i] = 1ll * fac[i - 1] * i % MOD;
  inv[K] = ksm(fac[K], MOD - 2);
  for (int i = K - 1; i >= 0; --i) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
}
inline int solve(int K, int W) {
  int ret = 0;
  for (int L = 1; L <= K; ++L) {
    if (L <= W)
      ret = (ret + 1ll * P(K, L) * P(K, L) % MOD * ksm(K, W - L) % MOD) % MOD;
    else
      ret = (ret + 1ll * P(K, L - W) * P(K - (L - W), W) % MOD *
                       P(K - (L - W), W) % MOD) %
            MOD;
  }
  return ret;
}
int main() {
  int K, W;
  Read(K), Read(W);
  init(K, W);
  printf("%d\n",
         ((solve(K, W) + ksm(K, W)) % MOD - solve(K, W - 1) + MOD) % MOD);
}
