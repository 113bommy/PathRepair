#include <bits/stdc++.h>
using namespace std;
using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = std::vector<long long>;
using vvi = std::vector<vi>;
template <typename T>
using maxpq = std::priority_queue<T, std::vector<T>, std::less<T>>;
template <typename T>
using minpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;
const ll MOD = 1e9 + 7;
const long long INF = 1e9 + 10;
const ll LLINF = 1e18 + 10;
const long long dx[] = {-1, 0, 1, 0};
const long long dy[] = {0, -1, 0, 1};
const long long dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const long long dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T>
inline T sq(T x) {
  return x * x;
}
inline ll madd(ll x, ll y, ll m = MOD) {
  if (x + y >= m) return x + y - m;
  return x + y;
}
inline ll msub(ll x, ll y, ll m = MOD) {
  if (x < y) return x - y + m;
  return x - y;
}
inline ll mmul(ll x, ll y, ll m = MOD) { return x * y % m; }
inline ll mpow(ll x, ll y, ll m = MOD) {
  ll r = 1;
  while (y) {
    if (y & 1) r = mmul(r, x, m);
    x = mmul(x, x);
    y /= 1;
  }
  return r;
}
inline ll minv(ll x, ll m = MOD) { return mpow(x, m - 2, m); }
template <typename T, typename U>
inline bool chmax(T &x, U y) {
  if (x >= y) return false;
  x = y;
  return true;
}
template <typename T, typename U>
inline bool chmin(T &x, U y) {
  if (x <= y) return false;
  x = y;
  return true;
}
template <typename T>
inline T &sort(T &c) {
  sort(std::begin(c), std::end(c));
  return c;
}
template <typename T>
inline T &reverse(T &c) {
  reverse(std::begin(c), std::end(c));
  return c;
}
template <typename T>
inline T &rsort(T &c) {
  sort(std::begin(c), std::end(c), greater<T>());
  return c;
}
template <typename T>
inline T &unique(T &c) {
  sort(std::begin(c), std::end(c));
  c.erase(unique(std::begin(c), std::end(c)), end(c));
  return c;
}
using pr = pair<long long, long long>;
long long n;
vector<long long> zx, zy;
vector<pair<long long, pr>> s[2];
void mergeseg(vector<pair<long long, pr>> &s) {
  vector<pair<long long, pr>> used;
  vector<pr> st;
  long long h = -1;
  for (long long i = (0); i < (long long)(s.size()); i += 1) {
    if (h != s[i].first) {
      for (long long j = (1); j < (long long)(st.size()); j += 1) {
        used.emplace_back(h, st[j]);
      }
      h = s[i].first;
      st.clear();
      st.emplace_back(-INF, -INF);
    }
    auto p = s[i].second;
    if (p.first <= st.back().second)
      chmax(st.back().second, p.second);
    else
      st.emplace_back(p);
  }
  for (long long i = (1); i < (long long)(st.size()); i += 1)
    used.emplace_back(h, st[i]);
  s = used;
}
const long long sz = 1 << 18;
set<long long> seg[sz * 2 - 1];
inline void add(long long l, long long r, long long x, long long k = 0,
                long long a = 0, long long b = sz) {
  if (r <= a || b <= l) return;
  if (l <= a && b <= r) {
    seg[k].insert(x);
    return;
  }
  long long m = (a + b) / 2;
  add(l, r, x, k * 2 + 1, a, m);
  add(l, r, x, k * 2 + 2, m, b);
}
inline long long query(long long l, long long r, long long k) {
  k += sz - 1;
  vector<long long> st;
  while (true) {
    for (long long x : seg[k]) {
      if (l <= x && x < r) st.emplace_back(x);
    }
    if (k == 0) break;
    k = (k - 1) / 2;
  }
  return unique(st).size();
}
long long bit[sz];
void bit_add(long long k, long long x) {
  k++;
  while (k < sz) {
    bit[k] += x;
    k += k & -k;
  }
}
void bit_add(long long l, long long r, long long x) {
  bit_add(l, x);
  bit_add(r, x);
}
long long bit_sum(long long k) {
  long long s = 0;
  while (k > 0) {
    s += bit[k];
    k -= k & -k;
  }
  return s;
}
long long bit_sum(long long l, long long r) { return bit_sum(r) - bit_sum(l); }
signed main() {
  scanf("%lld", &n);
  for (long long i = (0); i < (long long)(n); i += 1) {
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    if (a > c) swap(a, c);
    if (b > d) swap(b, d);
    if (a == c) {
      s[0].emplace_back(a, pr(b, d + 1));
    }
    if (b == d) {
      s[1].emplace_back(b, pr(a, c + 1));
    }
    for (long long j = (-1); j < (long long)(2); j += 1) {
      zx.emplace_back(a + j);
      zx.emplace_back(c + j);
      zy.emplace_back(b + j);
      zy.emplace_back(d + j);
    }
  }
  sort(s[0]);
  sort(s[1]);
  unique(zx);
  unique(zy);
  for (long long i = (0); i < (long long)(s[0].size()); i += 1) {
    s[0][i].first =
        (lower_bound(std::begin(zx), std::end(zx), (s[0][i].first)) -
         begin(zx));
    s[0][i].second.first =
        (lower_bound(std::begin(zy), std::end(zy), (s[0][i].second.first)) -
         begin(zy));
    s[0][i].second.second =
        (lower_bound(std::begin(zy), std::end(zy), (s[0][i].second.second)) -
         begin(zy));
  }
  for (long long i = (0); i < (long long)(s[1].size()); i += 1) {
    s[1][i].first =
        (lower_bound(std::begin(zy), std::end(zy), (s[1][i].first)) -
         begin(zy));
    s[1][i].second.first =
        (lower_bound(std::begin(zx), std::end(zx), (s[1][i].second.first)) -
         begin(zx));
    s[1][i].second.second =
        (lower_bound(std::begin(zx), std::end(zx), (s[1][i].second.second)) -
         begin(zx));
  }
  mergeseg(s[0]);
  mergeseg(s[1]);
  ll res = 0;
  for (auto p : s[0]) {
    res += zy[p.second.second] - zy[p.second.first];
  }
  for (auto p : s[1]) {
    res += zx[p.second.second] - zx[p.second.first];
  }
  vector<pair<long long, pr>> evs;
  for (auto p : s[0]) {
    evs.emplace_back(p.second.first, pr(p.first, 1));
    evs.emplace_back(p.second.second, pr(p.first, -1));
  }
  sort(evs);
  long long c = 0, d = 0;
  for (long long i = (0); i < (long long)(evs.back().first + 1); i += 1) {
    while (c < evs.size() && evs[c].first == i) {
      bit_add(evs[c].second.first, evs[c].second.second);
      c++;
    }
    while (d < s[1].size() && s[1][d].first == i) {
      res -= bit_sum(s[1][d].second.first, s[1][d].second.second);
      d++;
    }
  }
  cout << res << endl;
}
