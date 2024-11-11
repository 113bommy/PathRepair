#include <bits/stdc++.h>
template <class _Tp>
inline void min(_Tp &A, const _Tp &B) {
  if (B < A) A = B;
}
inline int count1(const long long &x) {
  return x ? (x & 1LL) + count1(x >> 1) : 0;
}
class matrix {
 private:
  static const int SZ = 256;
  long long V[SZ][SZ];

 public:
  matrix() { init(); }
  void init() { memset(V, 0x3f, sizeof(V)); }
  long long *operator[](const int &x) { return V[x]; }
  const long long *operator[](const int &x) const { return V[x]; }
} P[30];
int x, K, n, q, sz;
matrix mul(const matrix &A, const matrix &B, const int &sz) {
  matrix ret;
  for (int k = 0; k < sz; ++k)
    for (int i = 0; i < sz; ++i)
      if (A[i][k] != 0x3f3f3f3f3f3f3f3fLL)
        for (int j = 0; j < sz; ++j)
          if (B[k][j] != 0x3f3f3f3f3f3f3f3fLL)
            min(ret[i][j], A[i][k] + B[k][j]);
  return ret;
}
struct pll {
  long long x, y;
  pll(const long long &a = 0, const long long &b = 0) : x(a), y(b) {}
  bool operator<(const pll &A) const { return x < A.x; }
} B[30];
void Build_Matrix() {
  long long Cost[10];
  for (int i = (1); i < (K + 1); ++i) scanf("%lld", Cost + i);
  for (int i = 2; i < 1 << K; i += 2)
    if (count1(i) == x) P[0][i][i >> 1] = 0;
  for (int i = 1; i < 1 << K; i += 2)
    if (count1(i) == x)
      for (int j = 1; j <= K; ++j)
        if (!(i & 1 << j)) P[0][i][i >> 1 | 1 << j - 1] = Cost[j];
  for (int i = (1); i < (30); ++i) P[i] = mul(P[i - 1], P[i - 1], sz);
}
void init() {
  scanf("%d%d%d%d", &x, &K, &n, &q);
  sz = 1 << K;
  Build_Matrix();
  for (int i = (0); i < (q); ++i) scanf("%lld%lld", &B[i].x, &B[i].y);
  std::sort(B, B + q);
}
long long work() {
  matrix ans;
  ans[0][(1 << x) - 1] = 0;
  for (int i = 0, j = 1; i < q; ++i) {
    for (int l = 29; j < B[i].x - K; --l)
      if (j + (1 << l) <= B[i].x - K) ans = mul(ans, P[l], sz), j += 1 << l;
    for (; j < B[i].x && j < n - x + 1; ++j) {
      matrix tmp = P[0];
      for (int l = i; l < q; ++l)
        if (B[l].x > j + K)
          break;
        else
          for (int o = 1; o < sz; o += 2)
            if (count1(o) == x && !(o & 1 << B[l].x - j))
              tmp[o][o >> 1 | 1 << B[l].x - j - 1] += B[l].y;
      ans = mul(ans, tmp, sz);
    }
  }
  for (int l = 29, j = B[q - 1].x; j < n - x + 1; --l)
    if (j + (1 << l) <= n - x + 1) ans = mul(ans, P[l], sz), j += 1 << l;
  return ans[0][(1 << x) - 1];
}
int main() {
  init();
  printf("%lld\n", work());
  return 0;
}
