#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-12;
const int inf = 2000000000;
const long long int infLL = (long long int)1e18;
long long int MOD = 1000000007;
int MOD1 = 1000000007;
int MOD2 = 1000000009;
inline bool checkBit(long long int n, long long int i) {
  return n & (1LL << i);
}
inline long long int setBit(long long int n, long long int i) {
  return n | (1LL << i);
  ;
}
inline long long int resetBit(long long int n, long long int i) {
  return n & (~(1LL << i));
}
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline bool isLeapYear(long long int year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
inline void normal(long long int &a) {
  a %= MOD;
  (a < 0) && (a += MOD);
}
inline long long int modMul(long long int a, long long int b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a * b) % MOD;
}
inline long long int modAdd(long long int a, long long int b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a + b) % MOD;
}
inline long long int modSub(long long int a, long long int b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long int modPow(long long int b, long long int p) {
  long long int r = 1LL;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1LL;
  }
  return r;
}
inline long long int modDiv(long long int a, long long int b) {
  return modMul(a, modPow(b, MOD - 2));
}
bool comp(const pair<long long int, pair<long long int, long long int>> &p1,
          const pair<long long int, pair<long long int, long long int>> &p2) {
  return p1.first > p2.first;
}
bool comp1(const pair<long long int, long long int> &p1,
           const pair<long long int, long long int> &p2) {
  if (p1.first == p2.first) {
    return p1.second > p2.second;
  }
  return p1.first < p2.first;
}
long long int converter(string a) {
  long long int i, mul = 1LL, r, t, ans = 0LL;
  if (a.length() == 0) return 0;
  for (i = a.length() - 1; i >= 0; i--) {
    t = a[i] - '0';
    r = t % 10;
    ans += (mul * r);
    mul = mul * 10;
  }
  return ans;
}
int msb(unsigned x) {
  union {
    double a;
    int b[2];
  };
  a = x;
  return (b[1] >> 20) - 1023;
}
const int MAX = 125005;
int parent[MAX], sz[MAX];
string T, P;
vector<pair<char, char>> ids[MAX];
int n, m;
int a[MAX], b[MAX];
struct base {
  double real, imag;
  base(double _real, double _imag) {
    real = _real;
    imag = _imag;
  }
  base() {}
};
base operator+(const base &c1, const base &c2) {
  return base(c1.real + c2.real, c1.imag + c2.imag);
}
base operator-(const base &c1, const base &c2) {
  return base(c1.real - c2.real, c1.imag - c2.imag);
}
base operator*(const base &c1, const base &c2) {
  return base(c1.real * c2.real - c1.imag * c2.imag,
              c1.real * c2.imag + c2.real * c1.imag);
}
void fft(vector<base> &a, int invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    base wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      base w(1.0, 0.0);
      for (int j = 0; j < len / 2; j++) {
        base u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w = w * wlen;
      }
    }
  }
  if (invert)
    for (int i = 0; i < n; i++) a[i].real /= n, a[i].imag /= n;
}
vector<int> multiply(int a[], int b[], int mx, int m) {
  vector<base> fa, fb;
  vector<int> res;
  int l = mx, n = 1;
  while (n < l) n <<= 1;
  n <<= 1;
  for (int i = 0; i < n; i++) fa.push_back(base(a[i] * 1.0, 0));
  for (int i = 0; i < n; i++) fb.push_back(base(b[i] * 1.0, 0));
  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++) fa[i] = fa[i] * fb[i];
  fft(fa, true);
  for (int i = m - 1; i < mx; i++) res.push_back((int)(fa[i].real + 0.5));
  fa.clear();
  fb.clear();
  return res;
}
void process(char c1, char c2) {
  for (int i = 0; i < n; ++i) {
    a[i] = 0;
    a[i] = (T[i] == c1);
  }
  for (int i = 0; i < n; ++i) {
    b[i] = 0;
    if (i < m) b[i] = (P[m - i - 1] == c2);
  }
  vector<int> res = multiply(a, b, n, m);
  for (int i = 0; i < res.size(); ++i) {
    if (res[i] > 0) ids[i].push_back(make_pair(c1, c2));
  }
}
void init() {
  for (int i = 0; i < 6; i++) parent[i] = i, sz[i] = 1;
}
int root(int u) {
  if (u == parent[u]) return u;
  return parent[u] = root(parent[u]);
}
int union_make(int u, int v) {
  int ru = root(u);
  int rv = root(v);
  if (ru == rv) return false;
  if (sz[ru] >= sz[rv]) {
    parent[rv] = parent[ru];
    sz[ru] += sz[rv];
  } else {
    parent[ru] = parent[rv];
    sz[rv] += sz[ru];
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout.unsetf(ios::floatfield);
  cout.precision(20);
  cout.setf(ios::fixed, ios::floatfield);
  ;
  cin >> T >> P;
  n = T.size();
  m = P.size();
  for (char c1 = 'a'; c1 <= 'f'; ++c1) {
    for (char c2 = 'a'; c2 <= 'f'; ++c2) {
      if (c1 == c2) continue;
      process(c1, c2);
    }
  }
  for (int i = 0; i < n - m + 1; ++i) {
    init();
    int out = 0;
    for (int j = 0; j < ids[i].size(); ++j) {
      out += union_make(ids[i][j].first - 'a', ids[i][j].second - 'a');
    }
    cout << out << " ";
  }
  return 0;
}
