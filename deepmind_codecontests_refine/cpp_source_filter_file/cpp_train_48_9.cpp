#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int N = 105, mod = 1e9 + 7;
int n;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long ksm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
struct node {
  vector<pair<long long, long long> > p;
  node() { p.clear(); }
  inline void in() {
    int x = read();
    for (int i = 2; i * i <= x; i++)
      if (x % i == 0) {
        int k = 0;
        while (x % i == 0) k++, x /= i;
        p.push_back(make_pair(i, k));
      }
    if (x > 1) p.push_back(make_pair(x, 1));
  }
  inline void out() {
    long long ans = 1;
    for (auto o : p) ans = ans * ksm(o.first, o.second) % mod;
    printf("%lld\n", ans);
  }
  inline friend node operator*(const node &x, const node &y) {
    node z;
    int i = 0, j = 0;
    while (i < x.p.size() && j < y.p.size()) {
      if (x.p[i].first == y.p[j].first)
        z.p.push_back(make_pair(x.p[i].first, x.p[i].second + y.p[j].second)),
            i++, j++;
      else if (x.p[i].first < y.p[j].first)
        z.p.push_back(x.p[i]), i++;
      else
        z.p.push_back(y.p[j]), j++;
    }
    while (i < x.p.size()) z.p.push_back(x.p[i]), i++;
    while (j < y.p.size()) z.p.push_back(y.p[j]), j++;
    return z;
  }
  inline friend bool operator%(const node &x, const node &y) {
    for (int i = 0, j = 0; j < y.p.size(); i++, j++) {
      while (i < x.p.size() && x.p[i].first != y.p[j].first) i++;
      if (i == x.p.size() || x.p[i].second < y.p[j].second) return 1;
    }
    return 0;
  }
  inline friend node operator/(const node &x, const node &y) {
    node z;
    for (int i = 0, j = 0; i < x.p.size(); i++) {
      if (j < y.p.size() && x.p[i].first == y.p[j].first) {
        z.p.push_back(make_pair(x.p[i].first, x.p[i].second - y.p[j].second));
        j++;
        if (!z.p.back().second) z.p.pop_back();
      } else
        z.p.push_back(x.p[i]);
    }
    return z;
  }
  inline friend node operator&(const node &x, const node &y) {
    node z;
    for (int i = 0, j = 0; i < x.p.size(); i++) {
      if (j < y.p.size() && x.p[i].first == y.p[j].first)
        z.p.push_back(make_pair(x.p[i].first, x.p[i].second - y.p[j].second)),
            j++;
      else
        z.p.push_back(x.p[i]);
    }
    return z;
  }
  inline friend bool operator|(const node &x, const node &y) {
    if (!x.p.size()) return 0;
    long long k = 0;
    for (int i = 0, j = 0; i <= x.p.size(); i++, j++) {
      while (j < y.p.size() && !y.p[j].second) j++;
      if (i == x.p.size()) return j != y.p.size();
      if (j == y.p.size()) return 1;
      if (x.p[i].first != y.p[j].first || x.p[i].second % y.p[j].second)
        return 1;
      if (!i)
        k = x.p[i].second / y.p[j].second;
      else if (x.p[i].second / y.p[j].second != k)
        return 1;
    }
    return 0;
  }
  inline friend node operator^(node x, long long y) {
    for (auto &o : x.p) o.second = o.second * y % mod;
    return x;
  }
  inline friend node operator+(const node &x, const node &y) {
    node z;
    for (int i = 0; i < x.p.size(); i++)
      z.p.push_back(make_pair(
          x.p[i].first,
          x.p[i].second * y.p[i].second / gcd(x.p[i].second, y.p[i].second)));
    return z;
  }
} a[N], b[N], c[N], A, B;
inline bool check(node x) {
  for (int i = 1; i <= n; i++)
    if ((x % a[i]) || ((x / a[i]) | b[i])) return 0;
  return 1;
}
struct pro {
  long long k, b, p;
  inline pro(long long k = 0, long long b = 0, long long p = 0)
      : k(k), b(b), p(p) {}
  inline friend bool operator==(const pro &a, const pro &b) {
    return a.k == b.k && a.b == b.b && a.p == b.p;
  }
};
inline long long slove(pro x, pro y) {
  long long a = x.b * y.p - x.p * y.b, b = x.k * y.p - x.p * y.k;
  if (!b || (a % b)) puts("-1"), exit(0);
  return a / b;
}
long long exgcd(long long a, long long b, long long &x, long long &y,
                long long d = 0) {
  return b ? (d = exgcd(b, a % b, y, x), y -= a / b * x, d) : (x = 1, y = 0, a);
}
inline bool merge(int o) {
  vector<pro> v;
  for (int i = 0; i < A.p.size(); i++) {
    long long k1 = B.p[i].second, b1 = A.p[i].second, k2 = b[o].p[i].second,
              b2 = a[o].p[i].second;
    if (!k1 && !k2) {
      if (b1 != b2) puts("-1"), exit(0);
      continue;
    }
    if (!k1) {
      if (b1 < b2 || (b1 - b2) % k2) puts("-1"), exit(0);
      A = a[o] * (b[o] ^ ((b1 - b2) / k2));
      return 0;
    }
    if (!k2) {
      if (b2 < b1 || (b2 - b1) % k1) puts("-1"), exit(0);
      A = A * (B ^ ((b2 - b1) / k1));
      return 0;
    }
    long long d = gcd(k1, k2), g = b2 - b1;
    if (g % d) puts("-1"), exit(0);
    g /= d;
    k1 /= d;
    k2 /= d;
    if (v.size()) {
      if (v[0] == pro(k1, g, k2)) continue;
      A = A * (B ^ slove(v[0], pro(k1, g, k2)));
      return 0;
    }
    v.push_back(pro(k1, g, k2));
  }
  if (v.size()) {
    long long k = v[0].k, b = v[0].b, p = v[0].p, x, y;
    b = (b % p + p) % p;
    exgcd(k, p, x, y);
    x = (x * b % p + p) % p;
    A = A * (B ^ x);
    B = B + ::b[o];
  }
  return 1;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i].in(), b[i].in(), c[i] = a[i] * b[i];
  for (int i = 1; i <= n; i++)
    if (check(a[i])) return a[i].out(), 0;
  for (int i = 1; i <= n; i++) {
    if (c[i].p.size() != c[1].p.size()) puts("-1"), exit(0);
    for (int j = 0; j < c[1].p.size(); j++)
      if (c[i].p[j].first != c[1].p[j].first) puts("-1"), exit(0);
    a[i] = c[i] & b[i];
    b[i] = c[i] & a[i];
  }
  A = a[1];
  B = b[1];
  for (int i = 2; i <= n; i++)
    if (!merge(i)) {
      if (check(A)) return A.out(), 0;
      puts("-1"), exit(0);
    }
  A.out();
  return 0;
}
