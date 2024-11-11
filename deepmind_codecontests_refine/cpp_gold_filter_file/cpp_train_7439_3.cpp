#include <bits/stdc++.h>
using namespace std;
long long modpow(long long a, long long b,
                 long long mod = (long long)(1e9 + 7)) {
  if (!b) return 1;
  a %= mod;
  return modpow(a * a % mod, b / 2, mod) * (b & 1 ? a : 1) % mod;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mxn = 1e6;
int n;
int a[mxn];
vector<pair<long long, long long> > minqueue, maxqueue;
long long dp[mxn];
void solve() {
  for (int i = 0; i < mxn; i++) dp[i] = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    dp[i] = i ? dp[i - 1] : 0;
    while (int((minqueue).size()) && minqueue.back().second <= a[i])
      minqueue.pop_back();
    while (int((maxqueue).size()) && maxqueue.back().second >= a[i])
      maxqueue.pop_back();
    if (int((minqueue).size()))
      (dp[i]) = max((dp[i]), (minqueue.back().first - a[i]));
    if (int((maxqueue).size()))
      (dp[i]) = max((dp[i]), (maxqueue.back().first + a[i]));
    if (!int((minqueue).size()) ||
        minqueue.back().first < (i ? dp[i - 1] : 0) + a[i])
      minqueue.push_back(
          pair<long long, long long>((i ? dp[i - 1] : 0) + a[i], a[i]));
    if (!int((maxqueue).size()) ||
        maxqueue.back().first < (i ? dp[i - 1] : 0) - a[i])
      maxqueue.push_back(
          pair<long long, long long>((i ? dp[i - 1] : 0) - a[i], a[i]));
  }
  cout << dp[n - 1] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
