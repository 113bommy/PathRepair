#include <bits/stdc++.h>
using namespace std;
void swap(long long &x, long long &y) {
  long long temp = x;
  x = y;
  y = temp;
}
void google(long long t) { cout << "Case #" << t << ": "; }
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long expom(long long x, long long y, long long m) {
  if (y == 0) return 1;
  x = x % m;
  if (y % 2 == 0) return expom(x * x, y / 2, m) % m;
  return (x * expom(x * x, y / 2, m)) % m;
}
inline long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
inline long long ceil(long long a, long long b) {
  return (a % b == 0) ? a / b : a / b + 1;
}
long long dx[] = {1, 0, -1, 0};
long long dy[] = {0, 1, 0, -1};
vector<long long> pri(200000 + 6);
void prime_factorization_sieve() {
  pri[1] = 1;
  for (long long i = 2; i <= 200000 + 5; i++) {
    pri[i] = -1;
  }
  for (long long i = 2; i <= 200000 + 5; i++) {
    if (pri[i] == -1) {
      for (long long j = i; j <= 200000 + 5; j += i) {
        if (pri[j] == -1) pri[j] = i;
      }
    }
  }
}
vector<long long> get_factors(long long n) {
  vector<long long> res;
  while (pri[n] != 1) {
    res.push_back(pri[n]);
    n = n / pri[n];
  }
  return res;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> arr(n + 1);
  for (long long i = 1; i <= n; i++) cin >> arr[i];
  long long ans = INT_MIN;
  long long x = (n >= 500) ? n - 500 : n;
  if (n >= 500) {
    for (long long i = x + 1; i <= n; i++) {
      for (long long j = 1; j <= n; j++) {
        if (i != j) {
          ans = ((ans) < (i * j - k * (arr[i] | arr[j]))
                     ? (i * j - k * (arr[i] | arr[j]))
                     : (ans));
        }
      }
    }
  } else {
    for (long long i = 1; i <= x; i++) {
      for (long long j = 1; j <= n; j++) {
        if (i != j) {
          ans = ((ans) < (i * j - k * (arr[i] | arr[j]))
                     ? (i * j - k * (arr[i] | arr[j]))
                     : (ans));
        }
      }
    }
  }
  cout << ans << "\n";
}
signed main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
