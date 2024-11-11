#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vii = vector<pi>;
using vvi = vector<vi>;
const ll MOD = 1e9 + 7;
struct unordered_custom {
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
  size_t operator()(pair<int64_t, int64_t> Y) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
  }
};
struct DSU {
 public:
  ll sz[26];
  ll p[26];
  DSU() {
    for (int i = (0); (i) < (26); ++(i)) p[i] = i, sz[i] = 0;
  }
  void make(ll V) { sz[V] = 1; }
  void merge(ll U, ll V) {
    if (U == V) return;
    U = find(U);
    V = find(V);
    if (sz[U] > sz[V]) swap(U, V);
    p[U] = V;
    sz[V] += sz[U];
  }
  ll find(ll V) {
    if (V == p[V]) return V;
    return find(p[V]);
  }
};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t generate(int64_t L, int64_t R) {
  uniform_int_distribution<int64_t> generator(L, R);
  return generator(rng);
}
inline int64_t generate() {
  uniform_int_distribution<int64_t> generator(INT64_MIN, INT64_MAX);
  return generator(rng);
}
inline ll read_int() {
  ll x;
  cin >> x;
  return x;
}
inline string read_str() {
  string x;
  cin >> x;
  return x;
}
inline void read(vi &x) {
  for (auto &i : (x)) cin >> i;
}
inline void out(vi &x) {
  for (auto &i : (x)) cout << i << ' ';
  cout << '\n';
  ;
}
inline void out(string S) {
  cout << S << '\n';
  ;
}
inline void out(ll x) {
  cout << x << '\n';
  ;
}
inline ll exp(ll A, ll B) {
  ll ANS = 1;
  while (B) {
    if (B & 1) ANS = ANS * A % MOD;
    A = A * A % MOD;
    B >>= 1;
  }
  return ANS;
}
inline ll first(pi A) { return A.first; }
inline ll second(pi A) { return A.second; }
inline vi primes(ll N) {
  vector<bool> F(N + 1, 1);
  for (ll i = 2; i * i <= N; i++) {
    if (F[i]) {
      for (ll j = i; j <= N; j += i) {
        F[j] = 0;
      }
    }
  }
  vi PRIMES;
  for (int i = (2); (i) < (N + 1); ++(i))
    if (F[i]) PRIMES.push_back(i);
  return PRIMES;
}
int tc;
struct comp {
  bool operator()(const pi &x, const pi &y) const {
    if (x.second - x.first == y.second - y.first) {
      return x.first < y.first;
    }
    return x.second - x.first > y.second - y.first;
  }
};
vi ANS(1000001);
void process() {
  for (ll i = 2; i * i <= 1000000; i++) {
    if (!ANS[i]) {
      ANS[i * i] += 2;
      for (ll j = i * i + i; j <= 1000000; j += i) {
        ANS[j]++;
      }
    }
  }
  for (int i = (1); (i) < (1000001); ++(i)) {
    ANS[i] += ANS[i - 1];
  }
}
void test_case() {
  ll N = read_int();
  out(N - ANS[N]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll TC = 1;
  TC = read_int();
  process();
  for (int i = (0); (i) < (TC); ++(i)) tc++, test_case();
  return 0;
}
