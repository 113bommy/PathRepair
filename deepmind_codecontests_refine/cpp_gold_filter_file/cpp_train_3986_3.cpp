#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
const ll root = 62;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll binpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
ll modInv(ll a) { return binpow(a, MOD - 2); }
const double PI = atan(1);
const double eps = 1e-10;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 1000000;
ll dp[mxN];
ll arr[6];
int p10[6] = {1, 10, 100, 1000, 10000, 100000};
int k, n, q;
vector<pair<ll, int>> all;
int main() {
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin.tie(0)->sync_with_stdio(0);
  cin >> k;
  for (auto i = (0); i < (6); ++i) {
    cin >> arr[i];
  }
  int num = 3 * (k - 1);
  int pwr = 1;
  while (pwr <= num) {
    num -= pwr;
    for (auto i = (0); i < (6); ++i) {
      if (3LL * pwr * p10[i] > 1LL * mxN) break;
      all.push_back({1LL * pwr * arr[i], 3 * pwr * p10[i]});
    }
    pwr *= 2;
  }
  if (num) {
    for (auto i = (0); i < (6); ++i) {
      if (3LL * num * p10[i] > 1LL * mxN) break;
      all.push_back({1LL * num * arr[i], 3 * num * p10[i]});
    }
  }
  memset(dp, NINFLL, sizeof(dp));
  dp[0] = 0;
  for (auto p : all) {
    for (auto i = (mxN - p.second) - 1; i >= (0); --i) {
      dp[i + p.second] = max(dp[i + p.second], dp[i] + p.first);
    }
  }
  for (auto dig = (0); dig < (6); ++dig) {
    for (auto i = (mxN)-1; i >= (0); --i) {
      for (auto j = (1); j < (10); ++j) {
        if (i + p10[dig] * j >= mxN) continue;
        ll val = 0;
        if (j % 3 == 0) val = (j / 3) * arr[dig];
        dp[i + p10[dig] * j] = max(dp[i + p10[dig] * j], dp[i] + val);
      }
    }
  }
  cin >> q;
  while (q--) {
    cin >> n;
    cout << dp[n] << "\n";
  }
  return 0;
}
