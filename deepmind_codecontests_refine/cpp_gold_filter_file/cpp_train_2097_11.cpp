#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
const int INF = 1e9 + 7;
const long long INFLL = 4e18 + 17;
const long double EPS = 1e-9;
const int MAXN = 1e3 + 17;
const int MAXLOG = 17;
mt19937 myRand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 myRand64(chrono::steady_clock::now().time_since_epoch().count());
long long dp[MAXN], n, m;
unordered_map<long long, long long> calc;
long long dc(long long len) {
  if (len < MAXN) return dp[len];
  long long mid = len >> 1, ans = 0, l, r;
  if (calc.find(mid - 1) == calc.end()) calc[mid - 1] = dc(mid - 1);
  if (calc.find(len - mid) == calc.end()) calc[len - mid] = dc(len - mid);
  ans = calc[mid - 1] * calc[len - mid] % INF;
  for (int j = 0; j < m; ++j) {
    l = mid - 1 - j;
    r = len - (mid - j + m - 1);
    if (calc.find(l) == calc.end()) calc[l] = dc(l);
    if (calc.find(r) == calc.end()) calc[r] = dc(r);
    ans = (ans + (calc[l] * calc[r] % INF)) % INF;
  }
  return ans;
}
signed main(void) {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  dp[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    dp[i] = (dp[i] + dp[i - 1]) % INF;
    if (i - m >= 0) dp[i] = (dp[i] + dp[i - m]) % INF;
  }
  cout << dc(n);
}
