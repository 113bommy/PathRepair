#include <bits/stdc++.h>
using namespace std;
template <class T>
using v2d = vector<vector<T> >;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const long long mod = 1e9 + 7;
long long n, m, ans;
long long power(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) {
      r = r * a % mod;
    }
    b /= 2;
    a = a * a % mod;
  }
  return r;
}
void solve() {
  cin >> n >> m;
  ans = (n % mod) * (m % mod) % mod;
  uin(m, n);
  for (int i = 1; i <= (int)(min(m, (long long)3e6)); ++i) {
    ans = (ans - (n / i) % mod * i + mod * mod) % mod;
  }
  long long inv = power(2, mod - 2);
  for (long long i = min(m, (long long)3e6) + 1, j; i <= m; i = j + 1) {
    long long d = n / i;
    j = n / d;
    long long l = i, r = min(j, m);
    long long sum = (l + r) % mod * ((r - l + 1) % mod) % mod * inv % mod;
    ans = (ans - d % mod * sum + mod * mod) % mod;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
