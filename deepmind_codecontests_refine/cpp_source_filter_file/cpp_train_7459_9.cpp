#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int FFTMOD = 1007681537;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline long long isqrt(long long k) {
  long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
struct ZFuntion {
  int n;
  vector<int> f;
  void build(char* s) {
    n = strlen(s), f.resize(n);
    int l = 0, r = 0;
    f[0] = n;
    for (int i = 1; i < n; i++) {
      if (i > r) {
        l = r = i;
        while (r < n && s[r] == s[r - l]) r++;
        f[i] = r - l, r--;
      } else {
        int k = i - l;
        if (f[k] < r - i + 1)
          f[i] = f[k];
        else {
          l = i;
          while (r < n && s[r] == s[r - l]) r++;
          f[i] = r - l, r--;
        }
      }
    }
  }
} zf[2];
const int maxn = 2e6 + 5;
int n, m, k;
string s;
string t;
int a[maxn];
int b[maxn];
pair<int, int> st[maxn << 1];
void upd(int p, pair<int, int> val) {
  for (st[p += maxn] = val; p > 1;)
    p >>= 1, st[p] = max(st[p << 1], st[p << 1 | 1]);
}
pair<int, int> query(int l, int r) {
  pair<int, int> res = make_pair(-INF, -INF);
  for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) chkmax(res, st[l++]);
    if (r & 1) chkmax(res, st[--r]);
  }
  return res;
}
set<pair<int, int> > heap[maxn];
void add(int p, pair<int, int> val) {
  heap[p].insert(val);
  upd(p, *heap[p].rbegin());
}
void rem(int p, pair<int, int> val) {
  heap[p].erase(val);
  if (int((heap[p]).size())) {
    upd(p, *heap[p].rbegin());
  } else {
    upd(p, make_pair(-INF, -INF));
  }
}
void chemthan() {
  cin >> n >> m >> k;
  cin >> s >> t;
  zf[0].build((char*)(t + "$" + s).data());
  reverse((s).begin(), (s).end()), reverse((t).begin(), (t).end());
  zf[1].build((char*)(t + "$" + s).data());
  for (int i = (0); i < (2); ++i) {
    for (int& x : zf[i].f) {
      chkmin(x, k);
    }
    for (int j = (0); j < (n); ++j) {
      zf[i].f[j] = zf[i].f[j + m + 1];
    }
  }
  reverse(zf[1].f.begin(), zf[1].f.begin() + n);
  for (int i = (0); i < (n); ++i) a[i] = zf[0].f[i], b[i] = zf[1].f[i];
  for (int i = (0); i < (n - k + 1); ++i) {
    if (a[i] == m) {
      int lo = i;
      int hi = i + m - 1;
      while (lo > 0 && hi - lo + 1 < k + k) lo--;
      cout << "Yes\n";
      cout << lo + 1 << " " << lo + k + 1 << "\n";
      return;
    }
  }
  fill_n(st, maxn << 1, make_pair(-INF, -INF));
  vector<pair<int, int> > events1, events2;
  for (int i = (0); i < (n); ++i) {
    int ni = i - b[i] + k;
    if (ni < n) {
      add(b[i] + ni, make_pair(b[i], ni));
      events1.push_back(make_pair(ni, b[i]));
    }
  }
  for (int i = (0); i < (n); ++i) {
    int ni = i + a[i] - k;
    if (ni >= 0) {
      events2.push_back(make_pair(ni, a[i]));
    }
  }
  sort((events1).begin(), (events1).end()),
      sort((events2).begin(), (events2).end());
  int ptr = 0;
  for (int l = (0); l < (int((events2).size())); ++l) {
    while (ptr < int((events1).size()) &&
           events1[ptr].first < events2[l].first + k + k - 1) {
      int j = events1[ptr].first;
      int bj = events1[ptr].second;
      rem(bj + j, make_pair(bj, j));
      ptr++;
    }
    int i = events2[l].first;
    int ai = events2[l].second;
    int t = m + (n - 1) - (ai - i);
    pair<int, int> mx = query(0, t);
    if (ai + mx.first >= m) {
      int j = mx.second;
      int bj = mx.first;
      int dif = ai + bj - m;
      int z = min(i, dif);
      dif -= z;
      cout << "Yes\n";
      cout << i - z + 1 << " " << j - (k - 1) + dif + 1 << "\n";
      return;
    }
  }
  cout << "No\n";
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
