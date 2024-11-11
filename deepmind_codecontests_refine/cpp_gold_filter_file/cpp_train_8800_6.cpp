#include <bits/stdc++.h>
using namespace std;
template <class T>
bool remin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool remax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
int nxt() {
  int first;
  scanf("%d", &first);
  return first;
}
long long gcd(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
struct pt {
  long double first, second;
  pt() {}
  pt(long double first, long double second) : first(first), second(second) {}
  inline pt operator-(const pt &r) const {
    return pt(first - r.first, second - r.second);
  }
  inline pt operator+(const pt &r) const {
    return pt(first + r.first, second + r.second);
  }
  inline pt operator*(const long double &r) const {
    return pt(first * r, second * r);
  }
  inline long double sqlen() const {
    return abs(first * first + second * second);
  }
  pt rot(long double co, long double si) const {
    return pt(first * co - si * second, si * first + co * second);
  }
  pt rot(long double ang) const { return rot(cosl(ang), sinl(ang)); }
  long double len() const { return sqrtl(sqlen()); }
  inline bool operator<(const pt &r) const {
    if (first != r.first) return first < r.first;
    return second < r.second;
  }
  inline bool operator==(const pt &r) const {
    return first == r.first && second == r.second;
  }
};
ostream &operator<<(ostream &os, const pt &p) {
  return os << "(" << p.first << "," << p.second << ")";
}
inline long double cross(const pt &l, const pt &r) {
  return l.first * r.second - l.second * r.first;
}
inline long double dot(const pt &l, const pt &r) {
  return l.first * r.first + l.second * r.second;
}
long long pwmod(long long a, long long n, long long mod) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = ret * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ret;
}
template <typename T>
inline T sqr(T first) {
  return first * first;
}
bool remin(long long &first, long long second) {
  if (first > second) {
    first = second;
    return 1;
  }
  return 0;
}
const long long mod = 1000000007;
const int N = 200 * 1000 + 10;
pair<int, int> a[N];
long long f[N];
long long fi[N];
long long bin(long long n, long long k) {
  if (n < 0) return 0;
  if (k < 0 || k > n) return 0;
  return f[n] * fi[n - k] % mod * fi[k] % mod;
}
vector<int> t;
int sz;
void init(int nn) {
  sz = nn;
  t.assign(sz, 0);
}
int sum(int r) {
  int result = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) result += t[r];
  return result;
}
void inc(int i, int delta) {
  for (; i < sz; i = (i | (i + 1))) t[i] += delta;
}
int sum(int l, int r) { return sum(r) - sum(l - 1); }
void solve(int test) {
  f[0] = fi[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = f[i - 1] * i % mod;
    fi[i] = pwmod(f[i], mod - 2, mod);
  }
  int n = nxt();
  int k = nxt();
  for (int i = 0; i < (int)(n); i++) {
    a[i].first = nxt();
    a[i].second = nxt() + 1;
  }
  sort(a, a + n);
  vector<int> q;
  for (int i = 0; i < (int)(n); i++) {
    q.push_back(a[i].first);
    q.push_back(a[i].second);
  }
  sort((q).begin(), (q).end());
  q.resize(unique((q).begin(), (q).end()) - q.begin());
  init(q.size());
  long long ans = 0;
  for (int i = 0, j = 0; i + 1 < q.size(); ++i) {
    while (j < n && a[j].first <= q[i]) {
      int ps = lower_bound((q).begin(), (q).end(), a[j].second) - q.begin();
      inc(ps, 1);
      ++j;
    }
    long long cur = (q[i + 1] - q[i]) % mod;
    ans += cur * bin(sum(i + 1, (int)q.size() - 1), k) % mod;
  }
  cout << ans % mod << "\n";
}
int main() {
  int t = 1;
  for (int i = 0; i < (int)(t); i++) {
    solve(i + 1);
  }
  return 0;
}
