#include <bits/stdc++.h>
using namespace std;
inline void proc_status() {
  ifstream t("/proc/self/status");
  cerr << string(istreambuf_iterator<char>(t), istreambuf_iterator<char>())
       << endl;
}
template <class T>
inline T read() {
  register int x = 0;
  register int f = 1;
  register char c;
  while (!isdigit(c = getchar()))
    if (c == '-') f = -1;
  while (x = (x << 1) + (x << 3) + (c xor 48), isdigit(c = getchar()))
    ;
  return x * f;
}
template <typename T>
inline bool chkmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
const int maxN = 3e5;
const int mod = 998244353;
const int G = 3;
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
long long Inv(long long a) { return qpow(a, mod - 2); }
namespace Poly {
int omg[maxN << 2], iomg[maxN << 2], rev[maxN << 2];
void init(int lim, int lg2) {
  for (register int i = 0; i < lim; ++i)
    rev[i] = rev[i >> 1] >> 1 | (i & 1) << (lg2 - 1);
  omg[0] = 1, omg[1] = qpow(G, (mod - 1) / lim);
  iomg[0] = 1, iomg[1] = qpow(omg[1], mod - 2);
  for (register int i = 2; i < lim; ++i) {
    omg[i] = 1ll * omg[i - 1] * omg[1] % mod;
    iomg[i] = 1ll * iomg[i - 1] * iomg[1] % mod;
  }
}
void NTT(int a[], int lim, int omg[]) {
  for (register int i = 0; i < lim; ++i)
    if (rev[i] > i) swap(a[i], a[rev[i]]);
  for (register int len = 2; len <= lim; len <<= 1) {
    register int m = len >> 1;
    for (register int *p = a; p != a + lim; p += len)
      for (register int i = 0; i < m; ++i) {
        register int t = 1ll * omg[lim / len * i] * p[i + m] % mod;
        p[i + m] = (1ll * p[i] - t + mod) % mod;
        p[i] = (1ll * p[i] + t) % mod;
      }
  }
}
void DFT(int a[], int lim) { NTT(a, lim, omg); }
void IDFT(int a[], int lim) {
  NTT(a, lim, iomg);
  int inv = Inv(lim);
  for (register int i = 0; i < lim; ++i) a[i] = 1ll * a[i] * inv % mod;
}
void Mul(int a[], int n, int b[], int m, int c[], int len) {
  static int A[maxN << 2], B[maxN << 2];
  int lg2 = log2(n + m) + 1;
  int lim = 1 << lg2;
  init(lim, lg2);
  copy(a, a + n, A);
  fill(A + n, A + lim, 0);
  copy(b, b + m, B);
  fill(B + m, B + lim, 0);
  DFT(A, lim);
  DFT(B, lim);
  for (register int i = 0; i < lim; ++i) A[i] = 1ll * A[i] * B[i] % mod;
  IDFT(A, lim);
  copy(A, A + len, c);
}
}  // namespace Poly
using namespace Poly;
int n, m, k;
char s[maxN + 2], t[maxN + 2];
int g[4][maxN << 1], f[4][maxN << 1];
int F[4][maxN << 1];
void Input() {
  n = read<int>(), m = read<int>(), k = read<int>();
  scanf("%s", s);
  scanf("%s", t);
  for (int i = 0; i < n; ++i)
    if (s[i] == 'A')
      s[i] = 'a';
    else if (s[i] == 'G')
      s[i] = 'b';
    else if (s[i] == 'C')
      s[i] = 'c';
    else
      s[i] = 'd';
  for (int i = 0; i < m; ++i)
    if (t[i] == 'A')
      t[i] = 'a';
    else if (t[i] == 'G')
      t[i] = 'b';
    else if (t[i] == 'C')
      t[i] = 'c';
    else
      t[i] = 'd';
}
void Init() {
  reverse(t, t + m);
  for (char ch = 'a'; ch <= 'd'; ++ch) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == ch)
        cnt = k, f[ch - 'a'][i] = 1;
      else if (cnt)
        cnt--, f[ch - 'a'][i] = 1;
    }
    cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == ch)
        cnt = k, f[ch - 'a'][i] = 1;
      else if (cnt)
        cnt--, f[ch - 'a'][i] = 1;
    }
    for (int i = 0; i < m; ++i) g[ch - 'a'][i] = t[i] == ch;
  }
}
void Solve() {
  for (int i = 0; i < 4; ++i) Mul(f[i], n, g[i], m, F[i], n + m - 1);
  int ans = 0;
  for (int i = 0; i < n + m - 1; ++i) {
    if (F[0][i] + F[1][i] + F[2][i] + F[3][i] == 4) ans++;
  }
  cout << ans << endl;
}
int main() {
  Input();
  Init();
  Solve();
  return 0;
}
