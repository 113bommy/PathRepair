#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const long long mod = 998244353;
inline long long gcd(long long a, long long b) {
  return !b ? a : gcd(b, a % b);
}
inline long long q_pow(long long a, long long x) {
  long long ans = 1, tmp = a;
  while (x) {
    if (x & 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    x >>= 1;
  }
  return ans;
}
template <typename T>
inline void re(T &N) {
  int f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  N = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') N = N * 10 + c - '0';
  N *= f;
}
int m, n;
namespace NTT {
const int mod = 998244353;
inline int q_pow(int a, int x) {
  int ans = 1;
  while (x) {
    if (x & 1) ans = 1ll * ans * a % mod;
    a = 1ll * a * a % mod;
    x >>= 1;
  };
  return ans;
}
int g = 3, _g = q_pow(3, mod - 2);
vector<int> pos, int_inv;
inline void check_inv(int n) {
  while (int_inv.size() <= n) int_inv.push_back(q_pow(int_inv.size(), mod - 2));
}
struct Poly {
  vector<int> P;
  Poly() {}
  Poly(int n) { P.assign(n, 0); }
  Poly(vector<int> &p) { P = p; }
  void tran(vector<int> &v, int inv) {
    int len = v.size();
    for (int i = 0; i < len; i++)
      if (i < pos[i]) swap(v[i], v[pos[i]]);
    for (int i = 2, mid = 1; i <= len; i <<= 1, mid <<= 1) {
      int wm = q_pow(inv ? g : _g, (mod - 1) / i);
      for (int j = 0; j < len; j += i) {
        int w = 1;
        for (int k = 0; k < mid; k++, w = 1ll * w * wm % mod) {
          int x = v[j + k], y = 1ll * w * v[j + k + mid] % mod;
          v[j + k] = x + y >= mod ? x + y - mod : x + y;
          v[j + k + mid] = x - y < 0 ? x - y + mod : x - y;
        }
      }
    }
  }
  inline void R() { reverse(P.begin(), P.end()); }
  inline int &operator[](const int x) { return P[x]; }
  inline Poly operator+(Poly p) {
    vector<int> A = P, B = p.P, C;
    int len = max(A.size(), B.size());
    A.resize(len), B.resize(len), C.resize(len);
    for (int i = 0; i < len; i++)
      C[i] = A[i] + B[i] >= mod ? A[i] + B[i] - mod : A[i] + B[i];
    return Poly(C);
  }
  inline Poly operator-(Poly p) {
    vector<int> A = P, B = p.P, C;
    int len = max(A.size(), B.size());
    A.resize(len), B.resize(len), C.resize(len);
    for (int i = 0; i < len; i++)
      C[i] = A[i] - B[i] < 0 ? A[i] - B[i] + mod : A[i] - B[i];
    return Poly(C);
  }
  inline Poly operator*(Poly &p) {
    vector<int> A = P, B = p.P, C;
    int Max_len = int(A.size() + B.size()) - 1;
    int len = 1;
    while (len < Max_len) len <<= 1;
    A.resize(len);
    B.resize(len);
    C.resize(len);
    if (pos.size() != len) {
      pos.resize(len);
      for (int i = 0; i < len; i++)
        pos[i] = (pos[i >> 1] >> 1) + ((i & 1) ? len >> 1 : 0);
    }
    tran(A, 1);
    tran(B, 1);
    for (int i = 0; i < len; i++) C[i] = 1ll * A[i] * B[i] % mod;
    tran(C, 0);
    int inv = q_pow(len, mod - 2);
    C.resize(Max_len);
    for (int i = 0; i < C.size(); i++) C[i] = 1ll * C[i] * inv % mod;
    return Poly(C);
  }
  inline Poly operator*(long long x) {
    vector<int> C = P;
    x %= mod;
    for (int i = 0; i < C.size(); i++) C[i] = 1ll * C[i] * x % mod;
    return Poly(C);
  }
  inline Poly operator%(int n) {
    vector<int> C(n + 1);
    for (int i = 0; i <= min(n, (int)P.size() - 1); i++) C[i] = P[i];
    return Poly(C);
  }
  inline Poly operator/(long long x) {
    vector<int> C = P;
    x %= mod;
    int inv = q_pow(x, mod - 2);
    for (int i = 0; i < C.size(); i++) C[i] = 1ll * C[i] * inv % mod;
    return Poly(C);
  }
  inline Poly operator/(Poly &p) {
    Poly tmp = p.Inv();
    return (*this) * tmp % P.size();
  }
  inline Poly operator<<(int x) {
    vector<int> C = P;
    for (int i = (int)C.size() - 1; i >= 0; i--)
      C[i] = i - x >= 0 ? C[i - x] : 0;
    return Poly(C);
  }
  inline Poly operator>>(int x) {
    vector<int> C = P;
    for (int i = 0; i < C.size(); i++) C[i] = i + x < C.size() ? C[i + x] : 0;
    return Poly(C);
  }
  inline Poly Inv() {
    vector<int> A = P;
    int len = 1;
    while (len < A.size()) len <<= 1;
    A.resize(len);
    len = 2;
    Poly p1 = Poly(1), p2 = Poly(1);
    p1[0] = A[0];
    p2[0] = q_pow(P[0], mod - 2);
    while (len <= A.size()) {
      for (int i = len / 2; i < len; i++) p1.push_back(A[i]);
      p2 = p2 * 2 - p1 * p2 % len * p2 % len;
      len <<= 1;
    }
    return Poly(p2) % P.size();
  }
  inline Poly Diff() {
    vector<int> A = P;
    int len = A.size();
    for (int i = 0; i < len - 1; i++) A[i] = 1ll * A[i + 1] * (i + 1) % mod;
    A[len - 1] = 0;
    return Poly(A);
  }
  inline Poly Inte() {
    vector<int> A = P;
    int len = A.size();
    check_inv(len);
    for (int i = len - 1; i >= 1; i--) A[i] = 1ll * A[i - 1] * int_inv[i] % mod;
    A[0] = 0;
    return Poly(A);
  }
  inline Poly Ln() { return ((*this).Diff() / (*this)).Inte(); }
  inline Poly Exp() {
    Poly B0, B, A = Poly(0);
    int len = 1;
    while (len / 2 < P.size()) {
      for (int i = len / 2; i < len; i++) A.push_back(i < P.size() ? P[i] : 0);
      B = (Poly() - B0.Ln() + A);
      len <<= 1;
      B0 = B * B0 % len;
    }
    return B0 % P.size();
  }
  inline Poly pow(long long k) {
    Poly p = (*this);
    int _low = -1;
    for (int i = 0; i < p.size(); i++)
      if (p[i]) {
        _low = i;
        break;
      }
    if (!(~_low) || (k * _low > p.size())) return Poly(p.size());
    p = p >> _low;
    int mul = p[0];
    p = ((p / mul).Ln() * k).Exp();
    mul = q_pow(mul, k % (mod - 1));
    return p * mul << (_low * k);
  }
  inline void push_back(int x) { P.push_back(x); }
  inline void resize(int x) { P.resize(x); }
  inline int size() { return P.size(); }
};
inline Poly Lagrange(vector<long long> &x, vector<long long> &fx) {
  Poly ans(1), p;
  for (int i = 0; i < x.size(); i++) {
    p = Poly(1);
    p[0] = 1;
    for (int j = 0; j < x.size(); j++)
      if (i != j) {
        p.push_back(0), p = (p << 1) + p * (mod - x[j]);
        p = p *
            q_pow(x[i] - x[j] < 0 ? x[i] - x[j] + mod : x[i] - x[j], mod - 2);
      }
    ans = ans + p * fx[i];
  }
  return ans;
}
}  // namespace NTT
long long p0[N], p1[N], p2[N], p3[N], p4[N];
long long S1[N], S2[N], ST[N];
char s1[N], st[N];
int p[30], val[30];
NTT::Poly a1, b1, c1, a2, b2, c2, a3, b3, c3;
mt19937 mr(time(0));
int main() {
  for (int i = 0; i < 26; i++) {
    int x;
    re(x);
    p[x - 1] = i;
  }
  uniform_int_distribution<int> V(0, 100);
  for (int i = 0; i < 26; i++) val[i] = V(mr);
  scanf("%s%s", st + 1, s1 + 1);
  int ls = strlen(s1 + 1), lt = strlen(st + 1);
  for (int i = 1; i <= ls; i++) {
    S1[i] = s1[i] - 'a';
    S2[i] = p[S1[i]];
    S1[i] = val[S1[i]];
    S2[i] = val[S2[i]];
  }
  for (int i = 1; i <= lt; i++) ST[i] = val[st[i] - 'a'];
  for (int i = 1; i <= ls; i++)
    p0[i] = (p0[i - 1] + S1[i] * S1[i] * S2[i] * S2[i]) % mod;
  for (int i = ls; i >= lt; i--) p0[i] = (p0[i] - p0[i - lt] + mod) % mod;
  for (int i = 1; i <= ls; i++)
    a1.push_back((S1[i] * S1[i] * S2[i] + S1[i] * S2[i] * S2[i]) % mod);
  for (int i = 1; i <= lt; i++) b1.push_back(ST[i]);
  b1.R();
  c1 = a1 * b1;
  for (int i = lt; i <= ls; i++) p1[i] = (-2 * c1[i - 1] + 2 * mod) % mod;
  for (int i = 1; i <= ls; i++)
    a2.push_back((S1[i] * S1[i] + 4 * S1[i] * S2[i] + S2[i] * S2[i]) % mod);
  for (int i = 1; i <= lt; i++) b2.push_back((ST[i] * ST[i]) % mod);
  b2.R();
  c2 = a2 * b2;
  for (int i = lt; i <= ls; i++) p2[i] = c2[i - 1];
  for (int i = 1; i <= ls; i++) a3.push_back(S1[i] + S2[i]);
  for (int i = 1; i <= lt; i++) b3.push_back((ST[i] * ST[i] * ST[i]) % mod);
  b3.R();
  c3 = a3 * b3;
  for (int i = lt; i <= ls; i++) p3[i] = (-2 * c3[i - 1] + 2 * mod) % mod;
  for (int i = 1; i <= lt; i++)
    p4[i] = (p4[i - 1] + ST[i] * ST[i] % mod * ST[i] * ST[i] % mod) % mod;
  for (int i = lt; i <= ls; i++) {
    long long sum = (p0[i] + p1[i] + p2[i] + p3[i] + p4[lt]) % mod;
    putchar(sum ? '0' : '1');
  }
  puts("");
}
