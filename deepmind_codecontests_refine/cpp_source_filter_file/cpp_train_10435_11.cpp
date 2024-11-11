#include <bits/stdc++.h>
const int MAXN = 2e5 + 5;
const int ha = 998244353;
const int G = 3;
const int Gn = 332748118;
inline int qpow(int a, int n = ha - 2) {
  int res = 1;
  while (n) {
    if (n & 1) res = 1ll * res * a % ha;
    a = 1ll * a * a % ha;
    n >>= 1;
  }
  return res;
}
inline void add(int &x, int y) {
  (x += y);
  if (x >= ha) x -= ha;
}
struct Poly {
  std::vector<int> x;
  inline int &operator[](const int &n) { return x[n]; }
  inline int deg() { return (int)x.size() - 1; }
  inline void ext(int n) { x.resize(n + 1); }
};
int r[MAXN << 2], N;
inline void init(int n) {
  N = 1;
  int len = 0;
  while (N <= n) N <<= 1, len++;
  for (int i = 0; i <= N - 1; ++i)
    r[i] = (r[i >> 1] >> 1) | ((i & 1) << (len - 1));
}
inline void NTT(Poly &A, int opt = 1) {
  A.ext(N);
  for (int i = 0; i <= N - 1; ++i)
    if (i < r[i]) std::swap(A[i], A[r[i]]);
  for (int mid = 1; mid < N; mid <<= 1) {
    int W = qpow(opt == 1 ? G : Gn, (ha - 1) / (mid << 1));
    for (int i = 0; i < N; i += (mid << 1)) {
      for (int w = 1, j = 0; j < mid; ++j, w = 1ll * w * W % ha) {
        int x = A[i + j], y = 1ll * w * A[i + mid + j] % ha;
        A[i + j] = (x + y) % ha;
        A[i + mid + j] = (x + ha - y) % ha;
      }
    }
  }
  if (opt == -1) {
    int inv = qpow(N);
    for (int i = 0; i <= N - 1; ++i) A[i] = 1ll * A[i] * inv % ha;
  }
}
inline Poly operator*(Poly A, Poly B) {
  int len = A.deg() + B.deg();
  init(len);
  NTT(A, 1);
  NTT(B, 1);
  for (int i = 0; i <= N - 1; ++i) A[i] = 1ll * A[i] * B[i] % ha;
  NTT(A, -1);
  A.ext(len);
  return A;
}
std::mt19937 g(time(NULL));
int P[MAXN], iP[MAXN];
char S[MAXN], T[MAXN];
int val[26];
Poly s, s2, s3, t, t2, p, p2, t2p, tp2, tp;
int t2p2[MAXN];
int main() {
  for (int i = 0; i <= 25; ++i)
    scanf("%d", P + i), val[i] = i + 1, iP[P[i]] = i + 1;
  scanf("%s%s", S, T);
  int n = strlen(S), m = strlen(T);
  --n;
  --m;
  s.ext(n);
  s2.ext(n);
  s3.ext(n);
  t.ext(m);
  t2.ext(m);
  p.ext(m);
  p2.ext(m);
  t2p.ext(m);
  tp2.ext(m);
  tp.ext(m);
  int sm = 0;
  for (int i = 0; i <= n; ++i) {
    s[i] = val[S[i] - 'a'];
    s2[i] = 1ll * s[i] * s[i] % ha;
    s3[i] = 1ll * s2[i] * s[i] % ha;
    add(sm, 1ll * s2[i] * s2[i] % ha);
  }
  for (int i = 0; i <= m; ++i) {
    t[i] = val[T[i] - 'a'];
    t2[i] = 1ll * t[i] * t[i] % ha;
    p[i] = val[iP[T[i] - 'a' + 1] - 1];
    p2[i] = 1ll * p[i] * p[i] % ha;
    t2p[i] = 1ll * t2[i] * p[i] % ha;
    tp2[i] = 1ll * t[i] * p2[i] % ha;
    tp[i] = 1ll * t[i] * p[i] % ha;
    t2p2[i] = 1ll * t2[i] * p2[i] % ha;
    p[i] = 2ll * p[i] % ha;
    t2p[i] = 2ll * t2p[i] % ha;
    t[i] = 2ll * t[i] % ha;
    tp2[i] = 2ll * tp2[i] % ha;
    tp[i] = 4ll * tp[i] % ha;
  }
  for (int i = 1; i <= m; ++i) add(t2p2[i], t2p2[i - 1]);
  init(m);
  std::reverse(s.x.begin(), s.x.end());
  std::reverse(s2.x.begin(), s2.x.end());
  std::reverse(s3.x.begin(), s3.x.end());
  NTT(s);
  NTT(s2);
  NTT(s3);
  NTT(t);
  NTT(t2);
  NTT(p);
  NTT(p2);
  NTT(t2p);
  NTT(tp2);
  NTT(tp);
  Poly ans;
  ans.ext(N);
  for (int i = 0; i <= N - 1; ++i) {
    add(ans[i], 1ll * p2[i] * s2[i] % ha);
    add(ans[i], ha - 1ll * p[i] * s3[i] % ha);
    add(ans[i], 1ll * t2[i] * s2[i] % ha);
    add(ans[i], ha - 1ll * t2p[i] * s[i] % ha);
    add(ans[i], ha - 1ll * t[i] * s3[i] % ha);
    add(ans[i], ha - 1ll * tp2[i] * s[i] % ha);
    add(ans[i], 1ll * tp[i] * s2[i] % ha);
  }
  NTT(ans, -1);
  for (int i = 0; i <= m - n; ++i) {
    int res = ans[i + n];
    add(res, sm);
    add(res, (t2p2[i + n] + ha - (i == 0 ? 0 : t2p2[i - 1])) % ha);
    putchar(res ? '0' : '1');
  }
  return 0;
}
