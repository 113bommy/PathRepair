#include <bits/stdc++.h>
using namespace std;
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
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
struct comp {
  bool operator()(pair<pair<long long, long long>, long long> a,
                  pair<pair<long long, long long>, long long> b) {
    if (a.second == b.second) return a.first.first < b.first.first;
    return a.second > b.second;
  }
};
long long fb(long long n) {
  if (n == 0) return 0;
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  n = n + 1;
  return (n >> 1);
}
bool perfectSquare(long double x) {
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
long long modexp(long long n, long long p, long long c) {
  if (p == 0) return 1;
  long long ans = 1;
  if (p % 2) ans = n % c;
  return ((ans) * (modexp((n * n) % c, p / 2, c) % c)) % c;
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
long long M = 1e9 + 9;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto StArT = chrono::high_resolution_clock::now();
  {
    long long n, m, k;
    cin >> n >> m >> k;
    long long d = n / k, r = n % k;
    long long mx = d * (k - 1) + r;
    if (mx >= m) {
      cout << m;
      return 0;
    }
    long long add = m - mx, aval = n - mx, connected = 0, dis = 0;
    long long ans = 0;
    if (n == m) {
      ans = r;
      long long cur = (modexp(2, d + 1, M) - 2 + M) % M;
      cur = (cur * k) % M;
      ans = (ans + cur) % M;
    } else {
      connected = add * k + k - 1;
      dis = m - connected;
      ans = dis;
      long long num = connected / k;
      ans += connected % k;
      long long cur = (modexp(2, num + 1, M) - 2 + M) % M;
      cur = (cur * k) % M;
      ans = (ans + cur) % M;
    }
    cout << ans << "\n";
  }
  auto eNd = chrono::high_resolution_clock::now();
  double time__taken =
      chrono::duration_cast<chrono::nanoseconds>(eNd - StArT).count();
  time__taken *= 1e-9;
  cerr << "Time taken by program is : " << fixed << time__taken
       << setprecision(9);
  cerr << " sec" << endl;
}
