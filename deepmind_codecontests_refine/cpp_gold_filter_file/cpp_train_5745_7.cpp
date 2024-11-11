#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
template <typename _sp>
inline void qread(_sp &_x) {
  char _ch = getchar(), _lst = ' ';
  while (_ch < '0' || _ch > '9') _lst = _ch, _ch = getchar();
  while (_ch >= '0' && _ch <= '9')
    _x = (_x << 3) + (_x << 1) + (_ch ^ 48), _ch = getchar();
  if (_lst == '-') _x = -_x;
}
template <typename _sp>
inline _sp mmax(_sp __a, _sp __b) {
  return __a > __b ? __a : __b;
}
template <typename _sp>
inline _sp mmin(_sp __a, _sp __b) {
  return __a < __b ? __a : __b;
}
template <typename _sp>
inline _sp mabs(_sp __x) {
  return __x > 0 ? __x : (-__x);
}
template <typename _sp>
inline void mswap(_sp __a, _sp __b) {
  _sp __t = __a;
  __a = __b;
  __b = __t;
}
template <typename _sp>
inline _sp mlowbit(_sp __x) {
  return __x & (-__x);
}
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
int T;
long long n, m, k;
long long h[1005];
int main() {
  qread(T);
  while (T--) {
    n = 0, m = 0, k = 0;
    qread(n);
    qread(m);
    qread(k);
    for (register int i = 1; i <= n; i++) {
      h[i] = 0;
      qread(h[i]);
    }
    for (register int i = 1; i <= n - 1; i++) {
      if (h[i] >= mmax(0ll, h[i + 1] - k))
        m += (h[i] - mmax(0ll, h[i + 1] - k));
      else
        m -= (h[i + 1] - k - h[i]);
      if (m < 0) break;
    }
    if (m >= 0)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
