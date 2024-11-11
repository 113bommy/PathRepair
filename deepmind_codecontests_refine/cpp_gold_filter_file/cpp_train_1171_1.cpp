#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e17;
long long MOD;
const long long MAX = 4000001;
const long double eps = 1E-14;
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  }
  return b;
}
long long min(long long a, long long b) {
  if (a > b) {
    return b;
  }
  return a;
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  if (a < b) {
    return gcd(b, a);
  }
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
struct edge {
  long long ind;
  long long fr;
  long long to;
  long long d;
};
class mint {
  long long x;

 public:
  mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}
  mint operator-() const { return mint(-x); }
  mint& operator+=(const mint& a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint& a) {
    if ((x += MOD - a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint& a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint& a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint& a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint& a) const {
    mint res(*this);
    return res *= a;
  }
  mint pow(long long t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }
  mint inv() const { return pow(MOD - 2); }
  mint& operator/=(const mint& a) { return (*this) *= a.inv(); }
  mint operator/(const mint& a) const {
    mint res(*this);
    return res /= a;
  }
  friend ostream& operator<<(ostream& os, const mint& m) {
    os << m.x;
    return os;
  }
};
mint pw(mint a, long long b) {
  if (b == 0) {
    return 1;
  }
  mint ret = pw(a, b >> 1);
  ret *= ret;
  if (b & 1) {
    ret *= a;
  }
  return ret;
}
int main() {
  long long N, H, M, K;
  cin >> N >> H >> M >> K;
  vector<long long> h(N + 1), m(N + 1);
  for (long long i = 1; i <= N; i++) cin >> h[i] >> m[i];
  long long hal = M / 2;
  vector<pair<long long, long long>> lis;
  for (long long i = 1; i <= N; i++) lis.push_back({m[i] % hal, i});
  for (long long i = 1; i <= N; i++) lis.push_back({m[i] % hal + hal, i});
  sort(lis.begin(), lis.end());
  vector<long long> t(2 * N);
  for (long long i = 0; i < 2 * N; i++) t[i] = lis[i].first;
  long long id = 1;
  long long now = INF;
  for (long long i = 0; i < N; i++) {
    auto itr = lower_bound(t.begin(), t.end(), t[i] + K);
    long long x = distance(t.begin(), itr);
    if (now > x - i - 1) {
      now = x - i - 1;
      id = i;
    }
  }
  cout << now << " " << (lis[id].first + K) % hal << endl;
  auto itr = lower_bound(t.begin(), t.end(), t[id] + K);
  long long x = distance(t.begin(), itr);
  for (long long j = id + 1; j < x; j++) {
    cout << lis[j].second << " ";
  }
  cout << endl;
}
