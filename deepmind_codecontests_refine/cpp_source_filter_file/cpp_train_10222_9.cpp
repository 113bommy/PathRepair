#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T>
inline bool setmin(T &a, T b) {
  if (a > b) return a = b, 1;
  return 0;
}
template <class T>
inline bool setmax(T &a, T b) {
  if (a < b) return a = b, 1;
  return 0;
}
template <class T>
inline T fast(T a, T b, T mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
template <class T>
inline T russian(T a, T b, T mod) {
  long long res = 0;
  while (b) {
    if (b & 1) res = (res + a) % mod;
    a = (a + a) % mod;
    b >>= 1;
  }
  return res;
}
template <class T>
istream &operator>>(istream &os, vector<T> &container) {
  for (auto &u : container) os >> u;
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &container) {
  for (auto &u : container) os << u << " ";
  return os;
}
template <typename T>
inline T gcd(T a, T b) {
  while (b) swap(a %= b, b);
  return a;
}
const long long T = 1 << 20;
const long long INF = 1e9 + 7;
const long long mod = 998244353;
const long long BIG_INF = 1e18 + 7;
const long long N = 20000 + 7;
const int LOG = 17;
int nn, m, k, q;
long long dp[2][N];
long long tab[N];
long long tab2[N];
const long long root = 31;
const long long root_1 = 128805723;
const long long root_pw = 1 << 23;
long long inverse(long long x, long long y) { return fast(x, y - 2, y); }
void fft(vector<long long> &a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    long long wlen = invert ? root_1 : root;
    for (int i = len; i < root_pw; i <<= 1)
      wlen = (long long)(1LL * wlen * wlen % mod);
    for (int i = 0; i < n; i += len) {
      long long w = 1;
      for (int j = 0; j < len / 2; j++) {
        long long u = a[i + j], v = (1LL * a[i + j + len / 2] * w % mod);
        a[i + j] = u + v < mod ? u + v : u + v - mod;
        a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
        w = (1LL * w * wlen % mod);
      }
    }
  }
  if (invert) {
    int n_1 = inverse(n, mod);
    for (long long &x : a) x = (int)(1LL * x * n_1 % mod);
  }
}
vector<long long> multiply(vector<long long> const &a,
                           vector<long long> const &b) {
  vector<long long> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  long long n = 1;
  while (n < (int)(a).size() + (int)(b).size()) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++) fa[i] = ((fa[i] * fb[i] % mod) + mod) % mod;
  fft(fa, true);
  vector<long long> result(n);
  for (int i = 0; i < n; i++) fa[i] = ((fa[i] % mod) + mod) % mod;
  return fa;
}
vector<long long> rec(int pocz, int kon) {
  if (pocz == kon) return {1ll, tab2[pocz] + mod};
  int mid = (pocz + kon) / 2;
  vector<long long> A = rec(pocz, mid);
  vector<long long> B = rec(mid + 1, kon);
  vector<long long> C = multiply(A, B);
  if ((int)(C).size() > k + 1) C.resize(k + 1);
  return C;
}
void solve() {
  vector<long long> solution = rec(1, nn);
  cout << solution.back() << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> nn >> k;
  for (int i = 1; i <= nn; i++) cin >> tab[i];
  cin >> q;
  while (q--) {
    int rodz;
    cin >> rodz;
    if (rodz == 1) {
      int a, b, c;
      cin >> a >> b >> c;
      for (int i = 1; i <= nn; i++) {
        if (i == b)
          tab2[i] = a - c;
        else
          tab2[i] = a - tab[i];
      }
    } else {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      for (int i = 1; i <= nn; i++) {
        if (i >= b && i <= c)
          tab2[i] = a - (tab[i] + d);
        else
          tab2[i] = a - tab[i];
      }
    }
    solve();
  }
}
