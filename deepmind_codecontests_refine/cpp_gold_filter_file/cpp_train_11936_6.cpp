#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr int MOD = 1e9 + 7;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
template <typename T1, typename T2>
using safe_map = unordered_map<T1, T2, custom_hash>;
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) {
  istream >> p.first >> p.second;
  return istream;
}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v) {
  for (auto &it : v) cin >> it;
  return istream;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) {
  ostream << p.first << " " << p.second;
  return ostream;
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
  for (auto &it : c) cout << it << " ";
  return ostream;
}
template <typename T>
void print(T &&t) {
  cout << t << "\n";
}
template <typename T, typename... Args>
void print(T &&t, Args &&...args) {
  cout << t << " ";
  print(forward<Args>(args)...);
}
template <typename T>
int32_t size_i(T &container) {
  return static_cast<int32_t>(container.size());
}
long long GCD(long long a, long long b) {
  if (!b) return a;
  return GCD(b, a % b);
}
long long LCM(long long a, long long b) { return (a * b) / GCD(a, b); }
long long modpow(ll x, long long n, long long m = MOD) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = (res * x) % m;
    x = (x * x) % m;
    n >>= 1;
  }
  return res;
}
long long binpow(long long x, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * x;
    x = (x * x);
    n >>= 1;
  }
  return res;
}
long long modinv(long long x, long long m = MOD) { return modpow(x, m - 2, m); }
mt19937 rng;
long long getRandomNumber(long long l, long long r) {
  uniform_int_distribution<long long> dist(l, r);
  return dist(rng);
}
void preSolve() {
  rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
}
void solve(long long tc) {
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n), b(n);
  cin >> a >> b;
  vector<long long> sa(n + 1), sb(n + 1);
  for (long long i = n - 1; i >= 0; i--) {
    sa[i] = sa[i + 1] + (a[i] == 0);
    sb[i] = sb[i + 1] + (b[i] == 0);
  }
  long long P = 0;
  long long Q = (modpow(m, sa[0]) * modpow(m, sb[0])) % MOD;
  long long equalConf = 1;
  for (long long i = 0; i < n; i++) {
    if (a[i] != 0 && b[i] != 0) {
      if (b[i] > a[i]) break;
      if (a[i] > b[i]) {
        P += (equalConf * ((modpow(m, sa[i]) * modpow(m, sb[i])) % MOD)) % MOD;
        P %= MOD;
        break;
      }
    } else {
      long long k = ((modpow(m, sa[i + 1]) * modpow(m, sb[i + 1])) % MOD);
      long long x;
      if (a[i] == 0 && b[i] == 0) {
        x = (m * (m - 1)) / 2;
      } else if (a[i] == 0) {
        x = m - (b[i]);
      } else if (b[i] == 0) {
        x = (a[i]) - 1;
      }
      x %= MOD;
      P += (((equalConf * x) % MOD) * k) % MOD;
      P %= MOD;
      if (a[i] == 0 && b[i] == 0) {
        equalConf *= m;
        equalConf %= MOD;
      }
    }
  }
  long long ans = P * modinv(Q);
  ans %= MOD;
  print(ans);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(12) << fixed;
  preSolve();
  long long tests = 1;
  for (long long t = 1; t <= tests; t++) solve(t);
  return 0;
}
