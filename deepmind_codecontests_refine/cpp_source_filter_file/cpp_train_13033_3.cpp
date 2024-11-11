#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
template <class T>
inline void chmax(T& a, const T& b) {
  if ((a) < (b)) (a) = (b);
}
template <class T>
inline void chmin(T& a, const T& b) {
  if ((a) > (b)) (a) = (b);
}
template <typename T>
using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast {
  Fast() {
    std::cin.tie(0);
    ios::sync_with_stdio(false);
  }
} fast;
long long mod = 1e9 + 7;
struct mint {
  long long x;
  mint(long long x = 0) : x((x % mod + mod) % mod) {}
  mint& operator+=(const mint a) {
    (x += a.x) %= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    (x += mod - a.x) %= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint& operator/=(const mint& rhs) { return *this *= rhs.inv(); }
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  mint operator/(const mint& rhs) const { return mint(*this) /= rhs; }
  mint pow(long long n) const {
    mint res(1), x(*this);
    while (n) {
      if (n & 1) res *= x;
      x *= x;
      n >>= 1;
    }
    return res;
  }
  mint inv() const { return pow(mod - 2); }
  friend ostream& operator<<(ostream& os, const mint& m) { return os << m.x; }
  bool operator<(const mint& r) const { return x < r.x; }
  bool operator==(const mint& r) const { return x == r.x; }
};
map<long long, long long> prime_factor(long long n) {
  map<long long, long long> res;
  for (long long i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n != 1) res[n] += 1;
  return res;
}
long long solve() {
  long long x, n;
  cin >> x >> n;
  mint ans = 1;
  auto ps = prime_factor(x);
  42;
  for (auto&& el : ps) {
    long long p = el.first;
    42;
    long long pk = p;
    long long R = ((n) + (p)-1) / (p);
    while (pk <= n) {
      mint ad = mint(p).pow(n / pk);
      ans *= ad;
      if (pk >= R) {
        break;
      } else {
        pk *= p;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
signed main() {
  solve();
  return 0;
}
