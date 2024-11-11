#include <bits/stdc++.h>
using namespace std;
long long const INF = 987654321;
const long long MOD = 1e9 + 7;
const int N = 200002;
void SpeedForce() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int simple(int n) {
  int i, sq;
  if (n % 2 == 0) {
    return 0;
  }
  sq = (int)sqrt(n);
  for (i = 3; i <= sq; i++) {
    if ((n % i) == 0) {
      return 0;
    }
  }
  return 1;
}
long long gcd(long long a, long long b) {
  if (a > b) swap(a, b);
  if (!a) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long is_prime(long long n) {
  if (n <= 1 || n > 3 && (n % 2 == 0 || n % 3 == 0)) return 0;
  for (long long i = 5, t = 2; i * i <= n; i += t, t = 6 - t)
    if (n % i == 0) return 0;
  return 1;
}
long long binpow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2) {
      res = (res * x) % MOD;
    }
    x = (x * x) % MOD;
    n /= 2;
  }
  return res;
}
int n, x, ans[N];
void solve() {
  int n, k, m, t;
  cin >> n >> k >> m >> t;
  while (t--) {
    int a;
    cin >> a;
    if (a) {
      int x;
      cin >> x;
      n++;
      if (x <= k) ++k;
    } else {
      int x;
      cin >> x;
      if (x <= k) {
        k -= x;
        n -= x;
      } else
        n = x;
    }
    cout << n << ' ' << k << '\n';
  }
}
int main() {
  SpeedForce();
  int T = 1;
  while (T--) {
    solve();
  }
}
