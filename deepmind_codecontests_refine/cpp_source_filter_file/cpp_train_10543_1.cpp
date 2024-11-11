#include <bits/stdc++.h>
const long long P = 998244353;
using namespace std;
template <typename T>
inline void ckmax(T &a, T b) {
  (a < b) && (a = b);
}
template <typename T>
inline void ckmin(T &a, T b) {
  (a > b) && (a = b);
}
inline long long mul(long long a, long long b) { return 1ull * a * b % P; }
inline long long add(long long a, long long b) {
  return a + b >= P ? a + b - P : a + b;
}
inline long long sub(long long a, long long b) {
  return a - b >= 0 ? a - b : a - b + P;
}
inline void mulmod(long long &a, long long b) { a = mul(a, b); }
inline void addmod(long long &a, long long b) { ((a += b) >= P) && (a -= P); }
inline void submod(long long &a, long long b) { ((a -= b) < 0) && (a += P); }
inline long long ksm(long long a, long long b) {
  long long ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = 1ll * ans * a % P;
    a = 1ll * a * a % P;
  }
  return ans;
}
inline void fprint(const long long &x, char c = ' ') {
  fprintf(stderr, "%lld%c", x, c);
}
inline void fprint(const pair<long long, long long> &x, char c = '\n') {
  fprintf(stderr, "%lld %lld%c", x.first, x.second, c);
}
inline void fprint(const long long *f, const long long &n, char c = '\n') {
  for (long long i = 1; i <= n; i++) fprint(f[i]);
  fprintf(stderr, "%c", c);
}
inline void fprint(const vector<long long> &f, char c = '\n') {
  for (long long i = 0; i < (long long)f.size(); i++) fprint(f[i]);
  fprintf(stderr, "%c", c);
}
inline long long inv(long long a) { return ksm(a, P - 2); }
namespace FastIO {
const long long SIZE = 1 << 16;
char buf[SIZE], obuf[SIZE], str[64];
long long bi = SIZE, bn = SIZE, opt;
long long read(char *s) {
  while (bn) {
    for (; bi < bn && buf[bi] <= ' '; bi++)
      ;
    if (bi < bn) break;
    bn = fread(buf, 1, SIZE, stdin), bi = 0;
  }
  long long sn = 0;
  while (bn) {
    for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
    if (bi < bn) break;
    bn = fread(buf, 1, SIZE, stdin), bi = 0;
  }
  s[sn] = 0;
  return sn;
}
bool read(long long &x) {
  if (x) x = 0;
  long long bf = 0, n = read(str);
  if (!n) return 0;
  long long i = 0;
  if (str[i] == '-') bf = 1, i = 1;
  for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
  if (bf) x = -x;
  return 1;
}
void write(long long x) {
  if (!x)
    obuf[opt++] = '0';
  else {
    if (x < 0) obuf[opt++] = '-', x = -x;
    long long sn = 0;
    while (x) str[sn++] = x % 10 + '0', x /= 10;
    for (long long i = sn - 1; i >= 0; i--) obuf[opt++] = str[i];
  }
  if (opt >= (SIZE >> 1)) {
    fwrite(obuf, 1, opt, stdout);
    opt = 0;
  }
}
void write(char x) {
  obuf[opt++] = x;
  if (opt >= (SIZE >> 1)) {
    fwrite(obuf, 1, opt, stdout);
    opt = 0;
  }
}
void Fflush() {
  if (opt) fwrite(obuf, 1, opt, stdout);
  opt = 0;
}
};  // namespace FastIO
inline long long read() {
  long long x;
  FastIO::read(x);
  return x;
}
const long long MN = 2e5 + 5;
map<pair<long long, long long>, long long> mat;
long long qry(long long x, long long y) {
  if (mat.count(make_pair(x, y))) return mat[make_pair(x, y)];
  cout << "?" << ' ' << x << ' ' << y << endl;
  long long ans = 0;
  cin >> ans;
  mat[make_pair(x, y)] = ans;
  return ans;
}
vector<pair<long long, long long> > solve(vector<long long> a,
                                          vector<long long> b) {
  if (a.size() == 1) {
    pair<long long, long long> mn = make_pair(2e9, -1);
    for (long long i = 0; i < (long long)b.size(); i++) {
      long long v = qry(a[0], b[i]);
      mn = min(mn, make_pair(v, i));
    }
    return {mn};
  }
  if (a.size() >= b.size()) {
    vector<long long> tmp;
    for (long long i = 0; i < (long long)a.size(); i += 2) tmp.push_back(a[i]);
    vector<pair<long long, long long> > res = solve(tmp, b), ans;
    for (long long i = 0; i < (long long)a.size(); i++) {
      if (i % 2 == 0)
        ans.push_back(res[i / 2]);
      else {
        long long l = res[i / 2].second, r = (long long)b.size() - 1;
        if (i != (long long)a.size() - 1) r = res[i / 2 + 1].second;
        pair<long long, long long> mn = make_pair(2e9, -1);
        for (long long j = (l); j <= (r); j++) {
          long long v = qry(a[i], b[j]);
          mn = min(mn, make_pair(v, j));
        }
        ans.push_back(mn);
      }
    }
    return ans;
  } else {
    vector<long long> s(1, b[0]);
    long long top = 0;
    for (long long i = 1; i < (long long)b.size(); i++) {
      long long fl = 1;
      while (s.size()) {
        long long vl = qry(a[top], s[top]);
        long long vr = qry(a[top], b[i]);
        if (vl <= vr) {
          if (s.size() == a.size()) fl = 0;
          break;
        }
        s.pop_back();
        top--;
      }
      if (fl) ++top, s.push_back(i);
    }
    vector<pair<long long, long long> > ans = solve(a, s);
    long long pos = 0;
    for (long long i = 0; i < (long long)ans.size(); i++) {
      while (s[ans[i].second] > pos) pos++;
      ans[i].second = pos;
    }
    return ans;
  }
}
long long n, m;
signed main() {
  cin >> n >> m;
  vector<long long> a(n), b(m);
  for (long long i = (0); i <= (n - 1); i++) a[i] = i + 1;
  for (long long i = (0); i <= (m - 1); i++) b[i] = i + 1;
  vector<pair<long long, long long> > res = solve(a, b);
  long long ans = ((1 << 30) - 1);
  for (long long i = (0); i <= (n - 1); i++) {
    ckmin(ans, res[i].first);
  }
  cout << "!" << ' ' << ans << endl;
  return FastIO::Fflush(), 0;
}
