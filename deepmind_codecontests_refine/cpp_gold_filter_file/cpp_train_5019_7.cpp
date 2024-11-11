#include <bits/stdc++.h>
template <typename T>
inline void rd(T& x) {
  int si = 1;
  char c = getchar();
  x = 0;
  while (!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) {
  rd(x);
  rd(args...);
}
const int kN = 1e7 + 5, kP = 1e6 + 5, kInf = 0x3f3f3f3f;
const long long kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;
long long QPow(long long a, long long b) {
  long long ret = 1, bas = a % kMod;
  for (; b; b >>= 1, bas = bas * bas % kMod)
    if (b & 1) ret = ret * bas % kMod;
  return ret;
}
int n, m, k, p;
int prime[kP], cnt = 0, pw_xk[kN];
bool flag[kN];
void Sieve() {
  pw_xk[1] = 1;
  for (int i = 2; i <= k; ++i) {
    if (!flag[i]) {
      prime[++cnt] = i;
      pw_xk[i] = QPow(i, k);
    }
    for (int j = 1; j <= cnt && i * prime[j] <= k; ++j) {
      flag[i * prime[j]] = true;
      pw_xk[i * prime[j]] = (long long)pw_xk[i] * pw_xk[prime[j]] % kMod;
      if (i % prime[j] == 0) break;
    }
  }
}
int pw_px[kN], C_n_x[kN], C_nx1_kx[kN], inv[kN], f[kN];
void Init() {
  Sieve();
  pw_px[0] = C_n_x[0] = 1;
  f[0] = 0;
  long long np = -p + kMod, fac = 1;
  for (int i = 1; i <= k; ++i) fac = fac * i % kMod;
  inv[k] = QPow(fac, kMod - 2);
  fac = 1;
  for (int i = k - 1; ~i; --i) inv[i] = (long long)inv[i + 1] * (i + 1) % kMod;
  for (int i = 1; i <= k; ++i) {
    inv[i] = (long long)inv[i] * fac % kMod;
    fac = fac * i % kMod;
  }
  for (int i = 1; i <= k; ++i) {
    pw_px[i] = (long long)pw_px[i - 1] * np % kMod;
    C_n_x[i] = (long long)C_n_x[i - 1] * (n - i + 1) % kMod * inv[i] % kMod;
  }
  C_nx1_kx[0] = (long long)C_n_x[k] * QPow(n, kMod - 2) % kMod * (n - k) % kMod;
  for (int i = 1; i <= k; ++i)
    C_nx1_kx[i] =
        C_nx1_kx[i - 1] * QPow(n - i, kMod - 2) % kMod * (k - i + 1) % kMod;
  f[k] = 1;
  for (int i = k - 1; ~i; --i) {
    f[i] = (long long)f[i + 1] * (1 + np) % kMod +
           (long long)C_nx1_kx[i] * pw_px[k - i] % kMod;
  }
}
long long Calc() {
  long long ret = 0;
  if (n > k) {
    long long bas_p = 1;
    for (int i = 0; i <= k; ++i) {
      ret =
          (ret + (long long)bas_p * pw_xk[i] % kMod * C_n_x[i] % kMod * f[i]) %
          kMod;
      bas_p = bas_p * p % kMod;
    }
  } else {
    long long bas_p = 1, bas_1p = QPow(1 - p + kMod, n),
              inv_1p = QPow(1 - p + kMod, kMod - 2);
    for (int i = 0; i <= k; ++i) {
      ret = (ret + C_n_x[i] * bas_p % kMod * bas_1p % kMod * pw_xk[i]) % kMod;
      bas_p = bas_p * p % kMod;
      bas_1p = bas_1p * inv_1p % kMod;
    }
  }
  return ret;
}
int main() {
  int T = 1;
  while (T--) {
    rd(n, m, k);
    if (m == 1) {
      printf("%d\n", n);
      continue;
    }
    p = QPow(m, kMod - 2);
    Init();
    printf("%lld\n", Calc());
  }
  return 0;
}
