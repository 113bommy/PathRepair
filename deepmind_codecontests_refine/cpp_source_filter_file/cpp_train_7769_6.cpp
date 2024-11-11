#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vb = vector<bool>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vii = vector<ii>;
const ll MOD = 1000000007;
const int INF = 1000000000;
const double PI = 3.14159265358979323846;
long long pow(long long base, long long power, long long mod) {
  long long result = 1;
  while (power) {
    if (power & 1) result = result * base % mod;
    base = base * base % mod;
    power >>= 1;
  }
  return result;
}
long long inverse(long long a, long long mod) { return pow(a, mod - 2, mod); }
pair<ll, ll> operator*(const pair<ll, ll>& a, const pair<ll, ll>& b) {
  return {a.first * b.first % MOD, a.second * b.second % MOD};
}
void operator+=(pair<ll, ll>& a, const pair<ll, ll>& b) {
  a.first = (a.first * b.second + b.first * a.second) % MOD;
  a.second = a.second * b.second % MOD;
}
int main() {
  ios_base::sync_with_stdio(false);
  int k, a, b;
  cin >> k >> a >> b;
  int s = a + b;
  vector<vector<pair<ll, ll>>> dp(k + 1, vector<pair<ll, ll>>(k, {0, 1}));
  dp[1][0] = {1, 1};
  for (int i = (1), _i = (k); i < _i; ++i)
    for (int j = 0, _j = (k); j < _j; ++j) {
      if (j + i < k) {
        dp[i + 1][j] += dp[i][j] * pair<ll, ll>(a, s);
        dp[i][j + i] += dp[i][j] * pair<ll, ll>(b, s);
      }
    }
  auto S = [&](ll x) { return pair<ll, ll>(b * x + a, s - 1); };
  pair<ll, ll> ans{0, 1};
  for (int i = (1), _i = (k + 1); i < _i; ++i)
    for (int j = 0, _j = (k); j < _j; ++j)
      if (j + i >= k) ans += dp[i][j] * S(j + i);
  cout << ans.first * inverse(ans.second, MOD) % MOD << endl;
}
