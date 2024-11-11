#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using uint8 = unsigned char;
using uint16 = unsigned short int;
using uint32 = unsigned int;
using uint64 = unsigned long long;
using int8 = signed char;
using int16 = short int;
using int32 = int;
using int64 = long long;
using pi32 = std::pair<int32, int32>;
using pi64 = std::pair<int64, int64>;
namespace Useful {
const int Dirx4[4] = {1, 0, -1, 0};
const int Diry4[4] = {0, 1, 0, -1};
const int Dirx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int Diry8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const double exp = 1e-8;
template <typename _Tp>
inline _Tp Gcd(_Tp x, _Tp y) {
  return y ? gcd(x, y) : x;
}
template <typename _Tp>
inline void Sort(_Tp &x, _Tp &y) {
  if (x > y) std::swap(x, y);
}
template <typename _Tp>
inline bool InRange(_Tp x, _Tp l, _Tp r) {
  return l <= x && x <= r;
}
template <typename _Tp>
inline bool InMap(_Tp x, _Tp y, _Tp n, _Tp m) {
  return 1 <= x && x <= n && 1 <= y && y <= m;
}
template <typename _Tp>
inline _Tp Power(_Tp x, int64 m) {
  return m == 1 ? x : (m & 1 ? power(x * x, m / 2) * x : power(x * x, m / 2));
}
template <typename _Tp1, typename _Tp2>
inline std::pair<_Tp1, _Tp2> operator+(std::pair<_Tp1, _Tp2> x,
                                       std::pair<_Tp1, _Tp2> y) {
  return x.first += y.first, x.second += y.second, x;
}
}  // namespace Useful
using namespace std;
using namespace Useful;
const int maxn = 1000;
int a[maxn], cnt;
int main() {
  int n;
  int ans1 = 0, ans2 = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int k, kk;
    scanf("%d", &k);
    kk = k / 2;
    for (int i = 1; i <= kk; i++) {
      int tmp;
      scanf("%d", &tmp);
      ans1 += tmp;
    }
    if (k & 1) {
      int tmp;
      scanf("%d", &tmp);
      a[cnt++] = tmp;
    }
    for (int i = 1; i <= kk; i++) {
      int tmp;
      scanf("%d", &tmp);
      ans2 += tmp;
    }
  }
  sort(a, a + cnt);
  reverse(a, a + n);
  for (int i = 0; i < cnt; i++)
    if ((i & 1) == 0)
      ans1 += a[i];
    else
      ans2 += a[i];
  printf("%d %d\n", ans1, ans2);
}
