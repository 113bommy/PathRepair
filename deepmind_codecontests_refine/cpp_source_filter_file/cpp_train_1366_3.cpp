#include <bits/stdc++.h>
using namespace std;
template <class _T>
inline void ina(_T a[], int n) {
  for (int i = 0; i < n; i++) cin >> (a[i]);
}
int TEST_CASE = 0;
template <class _T>
inline _T pow(_T a, _T b, _T m) {
  a %= m;
  _T ans = 1 % m;
  while (b) {
    if (b & 1) ans *= a, ans %= m;
    a *= a;
    a %= m;
    b >>= 1;
  }
  return ans;
}
template <class _T>
inline _T pow(_T a, _T b) {
  _T ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b >>= 1;
  }
  return ans;
}
template <class _T>
inline _T add(_T a, _T b, _T m) {
  return a >= m - b ? a - (m - b) : a + b;
}
template <class _T>
inline _T multiply(_T a, _T b, _T m) {
  _T ans = 0;
  if (b > a) swap(a, b);
  while (b) {
    if (b & 1) ans = add(ans, a, m);
    b >>= 1;
    a = add(a, a, m);
  }
  return ans;
}
template <class _T>
inline _T bigpow(_T a, _T b, _T m) {
  a %= m;
  _T ans = 1 % m;
  while (b) {
    if (b & 1) ans = multiply(ans, a, m);
    a = multiply(a, a, m);
    b >>= 1;
  }
  return ans;
}
template <class _T>
inline _T modinvers(_T a, _T m) {
  return m > 2000000000LL ? bigpow(a, m - 2, m) : pow(a, m - 2, m);
}
template <class _T>
_T _egcd(_T a, _T b, _T &x, _T &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  _T _g = _egcd(b, a % b, x, y);
  _T xt = x;
  x = y, y = xt - (a / b) * y;
  return _g;
}
template <class _T>
inline _T fmodinvers(_T a, _T m) {
  _T x, y;
  _egcd(a, m, x, y);
  x %= m;
  if (x < 0) x += m;
  return x;
}
template <class _T>
inline _T _lcm(_T a, _T b) {
  return (a * b) / __gcd(a, b);
}
template <class T>
inline T SQ(T a) {
  return a * a;
}
long long SQRT(long long n) {
  long long e = sqrt(n * 1.0);
  long long l = max(0LL, e - 2), r = min(n, e + 2);
  long long ans = 0;
  while (l <= r) {
    long long m = ((l + r) >> 1);
    if (m * m <= n)
      ans = m, l = m + 1;
    else
      r = m - 1;
  }
  return ans;
}
long long CBRT(long long n) {
  long long e = cbrt(n * 1.0);
  long long l = max(0LL, e - 2), r = min(n, e + 2);
  long long ans = 0;
  while (l <= r) {
    long long m = ((l + r) >> 1);
    if (m * m * m <= n)
      ans = m, l = m + 1;
    else
      r = m - 1;
  }
  return ans;
}
unsigned long long __SEED = 3;
unsigned long long __MULTI = 6364136223846793005ULL;
unsigned long long __INC = 1442695040888963407ULL;
unsigned long long lcg() { return __SEED = __SEED * __MULTI + __INC; }
template <class _T>
inline _T random(_T L, _T R) {
  return lcg() % (R - L + 1) + L;
}
const long double EPS = 1e-9;
const long double PI = acos(-1.0);
const int MX = 6e5 + 5;
long long mod = 1e9 + 7;
vector<unsigned> bl, blk, wt;
vector<int> sm, smb, smw;
bool posi = 1;
void bloc(unsigned mask, int i, vector<int> block, vector<int> white) {
  if (!posi) return;
  if (((int)(white).size()) == 0 && ((int)(block).size())) {
    bl.push_back(mask);
    sm.push_back(31 - i);
    return;
  }
  if (((int)(block).size()) == 0) return;
  int suffix_len = 31 - i;
  int mn_b = 32, mn_w = 32;
  for (int j : block) {
    mn_b = min(mn_b, smb[j]);
  }
  for (int j : white) {
    mn_w = min(mn_w, smw[j]);
  }
  if (mn_w <= suffix_len && mn_b <= suffix_len) {
    posi = 0;
    return;
  }
  vector<int> bl0, wt0;
  vector<int> bl1, wt1;
  for (int j : block) {
    if (smb[j] <= suffix_len) {
      bl0.clear();
      bl1.clear();
      bl0.push_back(j);
      bl1.push_back(j);
      break;
    }
    if ((blk[j] >> i) & 1)
      bl1.push_back(j);
    else
      bl0.push_back(j);
  }
  for (int j : white) {
    if (smw[j] <= suffix_len) {
      wt0.clear();
      wt1.clear();
      wt0.push_back(j);
      wt1.push_back(j);
      break;
    }
    if ((wt[j] >> i) & 1)
      wt1.push_back(j);
    else
      wt0.push_back(j);
  }
  bloc(mask, i - 1, bl0, wt0);
  bloc(mask | (1 << i), i - 1, bl1, wt1);
}
int main() {
  int n;
  scanf("%d\n", &n);
  for (int i = n; i--;) {
    char sn, k;
    unsigned a, b, c, d;
    scanf("%c%u.%u.%u.%u%c", &sn, &a, &b, &c, &d, &k);
    unsigned msk = (a << 24) | (b << 16) | (c << 8) | d;
    int sd = 32;
    if (k == '/') {
      scanf("%d\n", &sd);
    }
    if (sn == '-')
      blk.push_back(msk), smb.push_back(sd);
    else
      wt.push_back(msk), smw.push_back(sd);
  }
  vector<int> b, w;
  for (int i = 0; i < ((int)(blk).size()); i++) b.push_back(i);
  for (int i = 0; i < ((int)(wt).size()); i++) w.push_back(i);
  bloc(0, 31, b, w);
  if (posi) {
    printf("%d\n", ((int)(bl).size()));
    for (int i = 0; i < ((int)(bl).size()); i++) {
      printf("%u.%u.%u.%u/%d\n", (bl[i] >> 24) & 255, (bl[i] >> 16) & 255,
             (bl[i] >> 8) & 255, b[i] & 255, sm[i]);
    }
  } else
    cout << -1 << '\n';
  return 0;
}
