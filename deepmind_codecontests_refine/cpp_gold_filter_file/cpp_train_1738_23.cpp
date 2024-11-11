#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n < 2) return 0;
  if (n < 4) return 1;
  if (n % 2 == 0 or n % 3 == 0) return 0;
  for (long long i = 5; i * i <= n; i += 6)
    if (n % i == 0 or n % (i + 2) == 0) return 0;
  return 1;
}
long long modexpo(long long x, long long p) {
  long long res = 1;
  x = x % 1000000007;
  while (p) {
    if (p % 2) res = res * x;
    p >>= 1;
    x = x * x % 1000000007;
    res %= 1000000007;
  }
  return res;
}
long long max(long long a, long long b) { return (a > b ? a : b); }
long long min(long long a, long long b) { return (a < b ? a : b); }
struct edge {
  long long u, v, w;
  edge(long long a, long long b, long long c) {
    u = a;
    v = b;
    w = c;
  }
};
struct compare {
  bool operator()(const edge a, const edge b) const {
    if (a.u == b.u) {
      if (a.v == b.v) {
        return a.w < b.w;
      }
      return a.v < b.v;
    }
    return a.u < b.u;
  }
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long ex = max(n - 11, 0);
  n = min(n, 11);
  set<long long> st;
  for (long long i = 0; i <= n; i++) {
    for (long long j = 0; j <= n && i + j <= n; j++) {
      for (long long k = 0; k <= n && i + j + k <= n; k++) {
        long long rest = n - i - j - k;
        st.insert(i * 1 + j * 5 + k * 10 + rest * 50);
      }
    }
  }
  long long ans = st.size() + ex * 49;
  cout << ans << "\n";
}
