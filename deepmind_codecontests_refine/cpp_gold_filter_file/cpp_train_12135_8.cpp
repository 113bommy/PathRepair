#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long __gcd(long long a, long long b) { return b ? __gcd(b, a % b) : a; }
struct pair_hash {
  inline std::size_t operator()(
      const std::pair<long long, long long>& v) const {
    return v.first * 31 + v.second;
  }
};
const long long mod = 1e9 + 7;
vector<long long> binarycut(long long x) {
  vector<long long> v;
  while (x) {
    if (x & 1)
      v.push_back(1);
    else
      v.push_back(0);
    x >>= 1;
  }
  reverse(v.begin(), v.end());
  return v;
}
long long takemod(long long a) { return ((a % mod) + mod) % mod; }
long long fast_exp(long long base, long long expo) {
  long long res = 1;
  while (expo > 0) {
    if (expo & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    expo >>= 1;
  }
  return res;
}
long long modinv(long long a) { return takemod(fast_exp(takemod(a), mod - 2)); }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  time_t t1, t2;
  t1 = clock();
  long long n, m;
  cin >> n >> m;
  long long a[n + 1][m + 1];
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  bool f = true;
  for (long long i = 1; i <= n; i++) {
    long long wrong = 0;
    for (long long j = 1; j <= m; j++) {
      if (a[i][j] != j) {
        wrong++;
      }
    }
    if (wrong > 2) {
      f = false;
      break;
    }
  }
  if (f) {
    cout << "YES";
    return 0;
  }
  for (long long r1 = 1; r1 <= m; r1++) {
    for (long long r2 = r1 + 1; r2 <= m; r2++) {
      long long b[n + 1][m + 1];
      for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= m; j++) {
          b[i][j] = a[i][j];
        }
      }
      for (long long i = 1; i <= n; i++) {
        swap(b[i][r1], b[i][r2]);
      }
      bool f = true;
      for (long long i = 1; i <= n; i++) {
        long long wrong = 0;
        for (long long j = 1; j <= m; j++) {
          if (b[i][j] != j) wrong++;
        }
        if (wrong > 2) {
          f = false;
          break;
        }
      }
      if (f) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
  t2 = clock();
  cerr << "time taken: " << t2 - t1;
  return 0;
}
