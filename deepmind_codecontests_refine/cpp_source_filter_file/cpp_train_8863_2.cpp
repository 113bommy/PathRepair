#include <bits/stdc++.h>
using namespace std;
const int N = 2333;
const int MOD = 998244353;
namespace {
int inv[N], fac[N], ifac[N], pw2[N];
int Add(int a, int b) { return (a += b) >= MOD ? a - MOD : a; }
int Sub(int a, int b) { return (a -= b) < 0 ? a + MOD : a; }
int Mul(int a, int b) { return (long long)a * b % MOD; }
int Inv(int a) { return (a == 1) ? 1 : Mul(MOD - MOD / a, Inv(MOD % a)); }
int Ch(int a, int b) {
  if (a < b) return 0;
  return Mul(fac[a], Mul(ifac[b], ifac[a - b]));
}
int Pow(int a, int b) {
  int r = 1;
  for (; b; b >>= 1) {
    if (b & 1) {
      r = Mul(r, a);
    }
    a = Mul(a, a);
  }
  return r;
}
void Math_init() {
  inv[1] = 1;
  for (int i = 2; i < N; ++i) {
    inv[i] = Mul(MOD - MOD / i, inv[MOD % i]);
  }
  fac[0] = ifac[0] = pw2[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = Mul(fac[i - 1], i);
    ifac[i] = Mul(ifac[i - 1], inv[i]);
    pw2[i] = Add(pw2[i - 1], pw2[i - 1]);
  }
}
}  // namespace
namespace PO {
int rev[N * 4], w[N * 4], L = 1;
void Init(int l) {
  for (; L < l; L <<= 1) {
    int wn = Pow(3, (MOD - 1) / (L << 1));
    for (int i = L; i < (L << 1); ++i) {
      w[i] = (i == L) ? 1 : Mul(w[i - 1], wn);
    }
  }
  for (int i = 0; i < l; ++i) {
    rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? l >> 1 : 0);
  }
}
void Dft(vector<int> &a, int l) {
  for (int i = 0; i < l; ++i) {
    if (i < rev[i]) {
      swap(a[i], a[rev[i]]);
    }
  }
  for (int i = 1, y; i < l; i <<= 1) {
    for (int j = 0; j < l; j += i << 1) {
      int *l = &a[j], *r = l + i, *wx = w + i;
      for (int k = 0; k < i; ++k, ++l, ++r, ++wx) {
        y = Mul(*r, *wx);
        *r = Sub(*l, y);
        *l = Add(*l, y);
      }
    }
  }
}
void Idft(vector<int> &a, int l) {
  reverse(a.begin() + 1, a.end());
  Dft(a, l);
  int il = Inv(l);
  for (int i = 0; i < l; ++i) {
    a[i] = Mul(a[i], il);
  }
}
vector<int> Poly_mul(vector<int> a, vector<int> b) {
  int n = a.size(), m = b.size(), l;
  for (l = 1; l < n + m - 1; l <<= 1)
    ;
  Init(l);
  a.resize(l);
  Dft(a, l);
  b.resize(l);
  Dft(b, l);
  for (int i = 0; i < l; ++i) {
    a[i] = Mul(a[i], b[i]);
  }
  Idft(a, l);
  a.resize(n + m - 1);
  return a;
}
}  // namespace PO
int main() {
  Math_init();
  int n, k, l;
  cin >> n >> k >> l;
  vector<int> AL(n + 1), AR(n + 1);
  for (int j = k; j <= n; ++j) {
    AL[j] = ifac[j];
  }
  for (int j = 0; j <= n; ++j) {
    AR[j] = (j & 1) ? Sub(0, ifac[j]) : ifac[j];
  }
  vector<int> A = PO::Poly_mul(AL, AR);
  A.resize(n + 1);
  for (int i = 0; i <= n; ++i) {
    A[i] = Mul(A[i], Mul(fac[n], ifac[n - i]));
  }
  int ans = 0;
  for (int i = k; i <= n * 2; ++i) {
    int tmp = 0;
    for (int j = k; j <= min(i, n); ++j) {
      tmp =
          ((i - j) & 1 ? Sub : Add)(tmp, Mul(Mul(A[j], pw2[j]), Ch(j, i - j)));
    }
    ans = Add(ans, Mul(tmp, inv[i + 1]));
  }
  printf("%d\n", Mul(ans, l));
  return 0;
}
