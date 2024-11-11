#include <bits/stdc++.h>
using std::cin;
using std::cout;
template <class _Tp>
inline _Tp abs(const _Tp &x) {
  return x < 0 ? -x : x;
}
template <class _Tp>
inline _Tp max(const _Tp &a, const _Tp &b) {
  return a > b ? a : b;
}
template <class _Tp>
inline _Tp min(const _Tp &a, const _Tp &b) {
  return a < b ? a : b;
}
template <class _Tp>
inline void inc(_Tp &a, const _Tp &b) {
  if (a < b) a = b;
}
template <class _Tp>
inline void dec(_Tp &a, const _Tp &b) {
  if (a > b) a = b;
}
template <class _Tp>
inline void swap(_Tp &a, _Tp &b) {
  _Tp c = a;
  a = b;
  b = c;
}
template <class _Tp>
inline bool operator==(const _Tp &A, const _Tp &B) {
  return !memcmp(&A, &B, sizeof(_Tp));
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  return b ? exgcd(b, a % b, y, x) + (y -= a / b * x) - y : (x = 1, y = 0, a);
}
struct mll {
  long long v;
  mll(const long long &x = 0) : v(x) {}
  mll operator+(const mll &A) const { return mll((v + A.v) % 1000000007LL); }
  mll operator*(const mll &A) const { return mll(v * A.v % 1000000007LL); }
};
long long n, m, A[100005], B[100005], cnt = 1, x, y;
mll f[100005][2];
int main() {
  scanf("%lld%lld", &n, &m);
  for (int i = (1); i < (n + 1); ++i) scanf("%lld", A + i);
  for (int i = (1); i < (n + 1); ++i) scanf("%lld", B + i);
  f[0][0] = mll(1);
  for (int i = (1); i < (n + 1); ++i) {
    if (!A[i] && !B[i]) {
      cnt = cnt * (m * m % 1000000007LL) % 1000000007LL;
      f[i][0] = f[i - 1][0] * mll(m);
      f[i][1] = f[i - 1][1] * mll(m * m % 1000000007LL) +
                f[i - 1][0] * mll(m * (m - 1) / 2 % 1000000007LL);
    } else if (A[i] && B[i]) {
      if (A[i] == B[i]) f[i][0] = f[i - 1][0];
      f[i][1] = f[i - 1][1] + f[i - 1][0] * (A[i] > B[i] ? 1 : 0);
    } else {
      cnt = cnt * m % 1000000007LL;
      f[i][0] = f[i - 1][0];
      f[i][1] =
          f[i - 1][1] * mll(m) + f[i - 1][0] * mll(B[i] ? m - B[i] : A[i] - 1);
    }
  }
  exgcd(cnt, 1000000007LL, x, y);
  x %= 1000000007LL;
  printf("%lld\n", f[n][1].v * (x < 0 ? x + 1000000007LL : x) % 1000000007LL);
  return 0;
}
