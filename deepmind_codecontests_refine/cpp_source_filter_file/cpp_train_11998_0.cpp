#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5, maxf = 1 << 18;
const int mod = 998244353;
namespace usual {
int fac[maxf + 5], ifac[maxf + 5];
int add(int ta, int tb) { return ta + tb >= mod ? ta + tb - mod : ta + tb; }
int sub(int ta, int tb) { return ta < tb ? ta - tb + mod : ta - tb; }
int ksm(long long ta, int tp) {
  int s = 1;
  for (; tp; ta = ta * ta % mod, tp >>= 1)
    if (tp & 1) s = ta * s % mod;
  return s;
}
void make_fac(int len) {
  fac[0] = 1;
  for (int i = 1; i <= len; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[len] = ksm(fac[len], mod - 2);
  for (int i = len; i; i--) ifac[i - 1] = 1ll * ifac[i] * i % mod;
}
int inv(int i) { return 1ll * ifac[i] * fac[i - 1] % mod; }
}  // namespace usual
using namespace usual;
namespace poly {
int pa[maxf + 5], pb[maxf + 5];
int rev[maxf + 5], g[maxf + 5], invg[maxf + 5];
void Cpy(int *A, int *B, int len) {
  for (int i = 0; i < len; i++) A[i] = B[i];
}
void Rev(int *A, int len) {
  for (int i = 0; i < len - i; i++) swap(A[i], A[len - i]);
}
void Cl(int *A, int len) { memset(A, 0, len * 4); }
void make_tt(int *T, int len, int da) {
  int tmp = ksm(da, (mod - 1) / len);
  for (int i = len >> 1; i; i >>= 1, tmp = 1ll * tmp * tmp % mod) {
    T[i] = 1;
    for (int j = 1; j < i; j++) T[i + j] = 1ll * T[i + j - 1] * tmp % mod;
  }
}
void pre_poly(int len) {
  make_tt(g, len, 3);
  make_tt(invg, len, 332748118);
}
void make_rev(int len) {
  for (int i = 1; i < len; i++)
    rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? len >> 1 : 0);
}
void NTT(int *T, int len, bool ok) {
  int *tt, ny;
  for (int i = 1; i < len; i++)
    if (i < rev[i]) swap(T[i], T[rev[i]]);
  for (int i = 1; i < len; i <<= 1) {
    tt = ok ? g + i : invg + i;
    for (int j = 0; j < len; j += i << 1)
      for (int l = 0; l < i; l++) {
        ny = 1ll * T[i + j + l] * tt[l] % mod;
        T[i + j + l] = sub(T[j + l], ny);
        T[j + l] = add(T[j + l], ny);
      }
  }
}
void Mult(int *A, int *B, int *C, int len) {
  Cpy(pa, A, len);
  Cpy(pb, B, len);
  make_rev(len);
  NTT(pa, len, 1);
  NTT(pb, len, 1);
  for (int i = 0; i < len; i++) pa[i] = 1ll * pa[i] * pb[i] % mod;
  NTT(pa, len, 0);
  int invn = ksm(len, mod - 2);
  for (int i = 0; i < len; i++) C[i] = 1ll * pa[i] * invn % mod;
}
void Inv(int *T, int *Ans, int len) {
  static int tf[maxf + 5], tg[maxf + 5];
  int invn;
  Cl(tf, len << 1);
  Cl(tg, len << 1);
  Cl(Ans, len << 1);
  Ans[0] = ksm(T[0], mod - 2);
  for (int i = 2; i <= len; i <<= 1) {
    Cpy(tf, Ans, i);
    Cpy(tg, T, i);
    make_rev(i << 1);
    NTT(tf, i << 1, 1);
    NTT(tg, i << 1, 1);
    for (int j = 0; j < i << 1; j++)
      tf[j] = 1ll * tf[j] * sub(2, 1ll * tf[j] * tg[j] % mod) % mod;
    NTT(tf, i << 1, 0);
    invn = ksm(i << 1, mod - 2);
    for (int j = 0; j < i; j++) Ans[j] = 1ll * tf[j] * invn % mod;
  }
}
void diff(int *T, int len) {
  for (int i = 1; i < len; i++) T[i - 1] = 1ll * T[i] * i % mod;
  T[len - 1] = 0;
}
void inte(int *T, int len) {
  for (int i = len - 1; i; i--) T[i] = 1ll * T[i - 1] * inv(i) % mod;
  T[0] = 0;
}
void Ln(int *T, int *Ans, int len) {
  static int invT[maxf + 5];
  Cl(invT, len << 1);
  Cl(Ans, len << 1);
  Inv(T, invT, len);
  Cpy(Ans, T, len);
  diff(Ans, len);
  Mult(Ans, invT, Ans, len << 1);
  Cl(Ans + len, len);
  inte(Ans, len);
}
void Exp(int *T, int *Ans, int len) {
  static int lnT[maxf + 5];
  Cl(Ans, len << 1);
  Ans[0] = 1;
  for (int i = 2; i <= len; i <<= 1) {
    Ln(Ans, lnT, i);
    for (int j = 0; j < i; j++) lnT[j] = sub(T[j], lnT[j]);
    lnT[0] = add(lnT[0], 1);
    Mult(Ans, lnT, Ans, i << 1);
    Cl(Ans + i, i);
  }
}
void Ksm(int *T, int *Ans, int len, int tp) {
  static int ts[maxf + 5];
  Ln(T, ts, len);
  for (int i = 0; i < len; i++) ts[i] = 1ll * ts[i] * tp % mod;
  Exp(ts, Ans, len);
}
}  // namespace poly
using namespace poly;
int n, len = 1;
int F[maxf + 5];
int T[maxf + 5], H[maxf + 5];
int powH[maxf + 5], invH[maxf + 5];
int S1[maxf + 5], S2[maxf + 5];
void make_F() {
  for (int i = 0; i <= n; i++) T[i] = sub(0, ifac[i + 2]);
  Inv(T, F, len);
  for (int i = 0; i <= n; i++) F[i] = F[i + 1];
  Cl(F + n - 1, len - n + 1);
}
void make_H() {
  Cl(T, len);
  T[0] = 1;
  T[1] = 1;
  Ln(T, H, len);
  for (int i = 0; i <= n; i++) T[i] = H[i + 1];
  Inv(T, H, len);
  Cl(H + n + 1, len - n - 1);
  Ksm(H, powH, len, n - 1);
  Cl(powH + n + 1, len - n - 1);
  for (int i = 0; i <= n; i++) T[i] = sub(0, H[i + 1]);
  T[n] = 0;
  Inv(T, invH, len);
  Cl(invH + n + 1, len - n - 1);
  Cpy(S1, H, n + 1);
  diff(S1, n + 1);
  Mult(powH, invH, S2, len << 1);
  Cl(S2 + n + 1, (len << 1) - n - 1);
  Mult(S1, S2, S1, len << 1);
  Cl(S1 + n + 1, (len << 1) - n - 1);
  Mult(S1, invH, S1, len << 1);
  Cl(S1 + n + 1, (len << 1) - n - 1);
  n -= 2;
  for (int i = 1; i <= n; i++)
    F[i] = sub(F[i], 1ll * add(S1[i + 1], 1ll * (n - i + 1) * S2[i + 1] % mod) *
                         inv(n + 1) % mod);
  F[0] = n;
}
int main() {
  scanf("%d", &n);
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  n += 2;
  while (len <= n) len <<= 1;
  make_fac(len << 1);
  pre_poly(len << 1);
  make_F();
  make_H();
  for (int i = 0; i <= n; i++)
    if (i & 1)
      T[i] = sub(0, ifac[i]);
    else
      T[i] = ifac[i];
  for (int i = 0; i <= n; i++) F[i] = 1ll * F[i] * fac[i] % mod;
  Rev(F, n + 1);
  Cl(T + n + 1, (len << 1) - n - 1);
  Mult(F, T, F, len << 1);
  for (int i = 0; i < n; i++)
    printf("%lld ", 1ll * fac[n] * ifac[i] % mod * F[n - i + 1] % mod);
  printf("\n");
  return 0;
}
