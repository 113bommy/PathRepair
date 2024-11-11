#include <bits/stdc++.h>
const long double eps = 1e-9;
using namespace std;
template <class T>
inline T MAX(const T &_a, const T &_b) {
  return ((_a > _b) ? _a : _b);
}
template <class T>
inline T MIN(const T &_a, const T &_b) {
  return ((_a < _b) ? _a : _b);
}
template <class T>
inline T MAX3(const T &_a, const T &_b, const T &_c) {
  return MAX(MAX(_a, _b), _c);
}
template <class T>
inline T MIN3(const T &_a, const T &_b, const T &_c) {
  return MIN(MIN(_a, _b), _c);
}
template <class T>
inline T MAX4(const T &_a, const T &_b, const T &_c, const T &_d) {
  return MAX(MAX3(_a, _b, _c), _d);
}
template <class T>
inline T MIN4(const T &_a, const T &_b, const T &_c, const T &_d) {
  return MIN(MIN3(_a, _b, _c), _d);
}
template <class T>
inline T ABS(const T &_a) {
  return ((_a < 0) ? -_a : _a);
}
template <class T>
inline T SQR(const T &_a) {
  return _a * _a;
}
template <class T>
inline T gcd(T _a, T _b) {
  for (T _r; (_r = _a % _b); _b = _r) _a = _b;
  return _b;
}
template <class T>
inline T lcm(const T &_a, const T &_b) {
  return (_a / gcd(_a, _b)) * _b;
}
template <class T>
inline bool BETW(const T &_a, const T &_b, const T &_c) {
  return (_a >= MIN(_b, _c) && _a <= MAX(_b, _c));
}
template <class T>
inline bool EXT(const T &_a, const T &_b, const T &_c) {
  return !BETW(_a, _b, _c);
}
const int MAXN = 100010, MAXT = 400010;
const long long _OO = -1000000000000000000LL;
int N;
long long d[MAXN], h[MAXN], sum[MAXN];
long long T[MAXT], maxL[MAXT], maxR[MAXT];
void build(int p = 1, int L = 1, int R = N) {
  if (L == R) {
    T[p] = maxL[p] = maxR[p] = h[L];
    return;
  }
  const int mid = (L + R) >> 1;
  long long sumL = sum[mid + 1] - sum[L], sumR = sum[R] - sum[mid];
  build(p * 2, L, mid);
  build(1 + p * 2, mid + 1, R);
  maxL[p] = MAX(maxL[1 + p * 2], maxL[p * 2] + sumR);
  maxR[p] = MAX(maxR[p * 2], maxR[1 + p * 2] + sumL);
  T[p] =
      MAX3(T[1 + p * 2], T[p * 2], maxL[p * 2] + maxR[1 + p * 2] + d[mid + 1]);
}
long long queryL(const int &X, const int &Y, int p = 1, int L = 1, int R = N) {
  if (X > R || Y < L) return _OO;
  if (X <= L && Y >= R) return maxL[p];
  const int mid = (L + R) >> 1;
  return MAX(queryL(X, Y, 1 + p * 2, mid + 1, R),
             queryL(X, Y, p * 2, L, mid) + sum[MIN(R, Y)] - sum[mid]);
}
long long queryR(const int &X, const int &Y, int p = 1, int L = 1, int R = N) {
  if (X > R || Y < L) return _OO;
  if (X <= L && Y >= R) return maxR[p];
  const int mid = (L + R) >> 1;
  return MAX(queryR(X, Y, p * 2, L, mid), queryR(X, Y, 1 + p * 2, mid + 1, R) +
                                              sum[mid + 1] - sum[MAX(L, X)]);
}
long long query(const int &X, const int &Y, int p = 1, int L = 1, int R = N) {
  if (X > R || Y < L) return _OO;
  if (X <= L && Y >= R) return T[p];
  const int mid = (L + R) >> 1;
  return MAX3(query(X, Y, p * 2, L, mid), query(X, Y, 1 + p * 2, mid + 1, R),
              ((Y > mid && X <= mid)
                   ? queryL(X, Y, p * 2, L, mid) +
                         queryR(X, Y, 1 + p * 2, mid + 1, R) + d[mid + 1]
                   : 0LL));
}
int main() {
  int i, a, b, M;
  scanf("%d%d", &N, &M);
  for (i = 2; i <= N + 1; ++i) scanf("%I64d", d + i);
  for (i = 1; i <= N; ++i) {
    scanf("%I64d", h + i);
    h[i] <<= 1;
  }
  for (i = 2; i <= N + 1; ++i) sum[i] = sum[i - 1] + d[i];
  build();
  while (M--) {
    scanf("%d%d", &a, &b);
    if (a > b)
      printf("%I64d\n", query(b + 1, a - 1));
    else {
      if (a == 1)
        printf("%I64d\n", query(b + 1, N));
      else if (b == N)
        printf("%I64d\n", query(1, a - 1));
      else
        printf("%I64d\n", MAX3(query(1, a - 1), query(b + 1, N),
                               queryR(1, a - 1) + queryL(b + 1, N) + d[N + 1]));
    }
  }
  return 0;
}
