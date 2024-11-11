#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 123;
const long long LINF = (long long)1e18 + 123;
const long double EPS = (long double)1e-7;
const long long MOD = (long long)1e9 + 7;
long long power(long long x, long long y, long long mod = MOD) {
  if (y == 0) {
    return 1;
  }
  if (y & 1) {
    return power(x, y - 1, mod) * x % mod;
  } else {
    long long tmp = power(x, y / 2, mod);
    return tmp * tmp % mod;
  }
}
template <typename A, typename B>
bool mini(A &x, const B &y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}
template <typename A, typename B>
bool maxi(A &x, const B &y) {
  if (y > x) {
    x = y;
    return true;
  }
  return false;
}
void add(long long &x, long long y) {
  x += y;
  if (x >= MOD) x -= MOD;
  if (x < 0) x += MOD;
}
void run();
int main() {
  if (strlen("")) {
    freopen(
        ""
        ".in",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(12);
  run();
  return 0;
}
const int N = (int)1e6 + 123;
int n, k;
long long fact[N];
long long rfact[N];
long long cnk(int n, int k) {
  if (k > n) {
    return 0;
  }
  return fact[n] * rfact[k] % MOD * rfact[n - k] % MOD;
}
long long dp[N], us[N];
void run() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  for (int i = 0; i < N; i++) {
    rfact[i] = power(fact[i], MOD - 2);
  }
  cin >> n >> k;
  for (int i = k + 1; i < n + 1; i++) {
    us[i] = fact[i - 1];
    add(us[i], -(dp[i - k - 1] * cnk(i - 1, k) * fact[k] % MOD));
    dp[i] = us[i];
    add(dp[i], dp[i - 1] * i % MOD);
  }
  long long ans = 0;
  for (int i = 1; i < n + 1; i++) {
    add(ans, dp[i - 1] * cnk(n - 1, i - 1) % MOD * fact[n - i] % MOD);
  }
  cout << ans << "\n";
}
