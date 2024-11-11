#include <bits/stdc++.h>
using namespace std;
const long long int mod = (long long int)(998244353);
const long long int mod2 = (long long int)1e9 + 7;
long long int test = 1;
vector<long long int> read(int n) {
  vector<long long int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  return v;
}
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
const int MAX = 2e5 + 5;
long long int dp[2][MAX];
long long int n, a, b;
string s;
long long int go(long long int idx, long long int lev = 0) {
  if (idx == n) {
    return 0;
  }
  if (dp[lev][idx] != -1) return dp[lev][idx];
  if (idx == n - 1) {
    if (lev == 0) {
      return dp[lev][idx] = a + b + go(idx + 1, 0);
    } else {
      return dp[lev][idx] = 2 * a + b + go(idx + 1, 0);
    }
  } else {
    if (lev == 0) {
      if (s[idx] == '0') {
        if (s[idx + 1] == '1')
          return dp[lev][idx] = 2 * a + 2 * b + go(idx + 1, 1);
        long long int op1 = 2 * a + 2 * b + go(idx + 1, 1);
        long long int op2 = a + b + go(idx + 1, 0);
        return dp[lev][idx] = min(op1, op2);
      } else {
        return dp[lev][idx] = 2 * a + 2 * b + go(idx + 1, 1);
      }
    } else {
      if (s[idx] == '0') {
        if (s[idx + 1] == '1') return dp[lev][idx] = a + 2 * b + go(idx + 1, 1);
        long long int op1 = a + 2 * b + go(idx + 1, 1);
        long long int op2 = 2 * a + b + go(idx + 1, 0);
        return dp[lev][idx] = min(op1, op2);
      } else {
        return dp[lev][idx] = a + 2 * b + go(idx + 1, 1);
      }
    }
  }
}
void solve() {
  long long int i, j, k, m, cnt = 0, ans = 0, sum = 0;
  cin >> n >> a >> b;
  cin >> s;
  i = 0;
  long long int prev = -1;
  ;
  memset(dp, -1, sizeof dp);
  ans = b + go(0, 0);
  cout << ans << "\n";
  test++;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int i = 1;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
