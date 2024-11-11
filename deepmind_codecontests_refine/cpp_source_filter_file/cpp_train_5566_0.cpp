#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  bool first = true;
  os << "[";
  for (unsigned int i = 0; i < v.size(); i++) {
    if (!first) os << ", ";
    os << v[i];
    first = false;
  }
  return os << "]";
}
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const std::set<T>& v) {
  bool first = true;
  os << "[";
  for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end();
       ++ii) {
    if (!first) os << ", ";
    os << *ii;
    first = false;
  }
  return os << "]";
}
template <typename T1, typename T2>
inline std::ostream& operator<<(std::ostream& os, const std::map<T1, T2>& v) {
  bool first = true;
  os << "[";
  for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end();
       ++ii) {
    if (!first) os << ", ";
    os << *ii;
    first = false;
  }
  return os << "]";
}
template <typename T, typename T2>
void printarray(T a[], T2 sz, T2 beg = 0) {
  for (T2 i = beg; i < sz; i++) cout << a[i] << " ";
}
inline long long binpow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res *= x;
    x *= x;
    n >>= 1;
  }
  return res;
}
inline long long powmod(long long x, long long n, long long _mod) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * x) % _mod;
    x = (x * x) % _mod;
    n >>= 1;
  }
  return res;
}
inline long long mulmod(long long x, long long n, long long _mod) {
  long long res = 0;
  while (n) {
    if (n & 1) res = (res + x) % _mod;
    x = (x + x) % _mod;
    n >>= 1;
  }
  return res;
}
inline long long __gcd(long long a, long long b) {
  long long t;
  while (b) {
    a = a % b;
    t = a;
    a = b;
    b = t;
  }
  return a;
}
inline int __gcd(int a, int b) {
  int t;
  while (b) {
    a = a % b;
    t = a;
    a = b;
    b = t;
  }
  return a;
}
inline long long lcm(int a, int b) { return a / __gcd(a, b) * (long long)b; }
inline long long lcm(long long a, long long b) { return a / __gcd(a, b) * b; }
inline long long __gcd(long long a, long long b, long long c) {
  return __gcd(__gcd(a, b), c);
}
inline int __gcd(int a, int b, int c) { return __gcd(__gcd(a, b), c); }
inline long long lcm(long long a, long long b, long long c) {
  return lcm(lcm(a, b), c);
}
inline long long lcm(int a, int b, int c) {
  return lcm(lcm(a, b), (long long)c);
}
inline long long max(long long a, long long b) { return (a > b) ? a : b; }
inline double max(double a, double b) { return (a > b) ? a : b; }
inline long long max(long long a, long long b, long long c) {
  return max(a, max(b, c));
}
inline int max(int a, int b, int c) { return max(a, max(b, c)); }
inline double max(double a, double b, double c) { return max(a, max(b, c)); }
inline long long min(long long a, long long b) { return (a < b) ? a : b; }
inline int min(int a, int b) { return (a < b) ? a : b; }
inline double min(double a, double b) { return (a < b) ? a : b; }
inline long long min(long long a, long long b, long long c) {
  return min(a, min(b, c));
}
inline int min(int a, int b, int c) { return min(a, min(b, c)); }
inline double min(double a, double b, double c) { return min(a, min(b, c)); }
using namespace std;
long long int a, b, c, d, x, y, i, j, k, K, n, m, t, ar[1000001], ar2[1000001],
    flag, dp[2][5001], ans = 0, cur = 0, mod = 1000000007LL;
string ch;
int main() {
  cin >> n >> a >> b >> k;
  dp[0][a] = 1;
  for (i = 0; i < k; i++) {
    if (i % 2)
      c = 1;
    else
      c = 0;
    d = 1 - c;
    for (j = 1; j <= n; j++) dp[d][j] = 0;
    for (j = 1; j <= n; j++) {
      if (j == b) continue;
      x = max(1, j - abs(j - b + 1));
      y = min(n, j + abs(j - b + 1));
      dp[d][x] += dp[c][j];
      dp[d][j] -= dp[c][j];
      dp[d][j + 1] += dp[c][j];
      dp[d][y + 1] -= dp[c][j];
    }
    cur = 0;
    for (j = 1; j <= n; j++) {
      cur += dp[d][j];
      dp[d][j] = cur;
      dp[d][j] %= mod;
    }
  }
  for (i = 1; i <= n; i++) {
    if (i == b) continue;
    ans += dp[d][i];
    ans %= mod;
  }
  cout << ans;
  return 0;
}
