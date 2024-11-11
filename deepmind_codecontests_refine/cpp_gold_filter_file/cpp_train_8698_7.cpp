#include <bits/stdc++.h>
using namespace std;
const char IO_MODE = 3;
inline long long ReadInt() {
  long long x = 0, s = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') s = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return s * x;
}
inline void WriteInt(long long x) {
  char c[20];
  if (!x) {
    putchar('0');
    return;
  }
  if (x < 0) putchar('-'), x = -x;
  int i = 0;
  while (x > 0) c[++i] = x % 10, x /= 10;
  while (i) putchar(c[i--] + 48);
}
template <typename T>
inline void out(T x) {
  if (IO_MODE & 1)
    WriteInt(x);
  else if (typeid(x) == typeid(int))
    printf("%i", x);
  else
    printf("%lld", (long long)x);
}
template <typename T, typename... Args>
inline void out(T x, Args... args) {
  out(x);
  putc(' ', stdout);
  out(args...);
}
template <typename T>
inline void in(T &x) {
  if (IO_MODE & 2)
    x = ReadInt();
  else if (typeid(x) == typeid(int))
    scanf("%i", &x);
  else if (typeid(x) == typeid(long long))
    scanf("%lld", &x);
}
template <typename T, typename... Args>
inline void in(T &x, Args &...args) {
  in(x);
  in(args...);
}
int aa, bb, cc, dd, ee, ff, gg, hh, ii, jj, kk, mm, nn, oo, pp, qq, rr, ss, tt,
    uu, vv, ww, xx, yy, zz;
int tc;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug &operator<<(const c &) {
    return *this;
  }
};
struct DoubleHash {
  const int p1 = 31, p2 = 1337;
  const int m1 = 1e9 + 9, m2 = 1e9 + 7;
  vector<long long> pow1, pow2, h1, h2;
  void build(string s) {
    int n = s.size();
    pow1.resize(n);
    h1.resize(n);
    pow1[0] = 1;
    for (int i = 1; i < n; i++) pow1[i] = pow1[i - 1] * p1 % m1;
    h1[0] = s[0] - 'a' + 1;
    for (int i = 1; i < n; i++) h1[i] = (h1[i - 1] * p1 + s[i] - 'a' + 1) % m1;
    pow2.resize(n);
    h2.resize(n);
    pow2[0] = 1;
    for (int i = 1; i < n; i++) pow2[i] = pow2[i - 1] * p2 % m2;
    h2[0] = s[0] - 'a' + 1;
    for (int i = 1; i < n; i++) h2[i] = (h2[i - 1] * p2 + s[i] - 'a' + 1) % m2;
  }
  pair<int, int> getHash(int i, int j) {
    long long a = h1[j];
    if (i) a -= h1[i - 1] * pow1[j - i + 1];
    a = (a % m1 + m1) % m1;
    long long b = h2[j];
    if (i) b -= h2[i - 1] * pow2[j - i + 1];
    b = (b % m2 + m2) % m2;
    return make_pair(a, b);
  }
} hs;
int n, k, m;
string s;
map<pair<int, int>, int> mp;
int32_t main() {
  in(n, k);
  cin >> s;
  in(m);
  for (int i = 0; i < m; i++) {
    string t;
    cin >> t;
    hs.build(t);
    mp[hs.getHash(0, t.size() - 1)] = i;
  }
  s += s;
  hs.build(s);
  for (int i = 0; i < k; i++) {
    set<int> st;
    vector<int> v;
    for (int j = 0; j < n; j++) {
      auto h = hs.getHash(i + j * k, i + j * k + k - 1);
      if (!mp.count(h)) break;
      st.insert(mp[h]);
      v.push_back(mp[h]);
    }
    if (st.size() == n) {
      printf("YES\n");
      for (auto x : v) printf("%d ", x + 1);
      putc('\n', stdout);
      return 0;
    }
  }
  printf("NO\n");
}
