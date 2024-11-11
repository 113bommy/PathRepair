#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
const long long mod = 1e9 + 7;
const int maxn = 1e6 + 5;
long long n, l, k;
pair<int, int> a[maxn];
long long dp[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> l >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + n);
  dp[0] = 1;
  long long blocks = l / n;
  long long last = l % n;
  long long ans = 0;
  for (int len = 1; len <= k && len <= blocks + 1; len++) {
    long long cur = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
      while (j < n && a[j].first <= a[i].first) {
        cur += dp[j];
        cur %= mod;
        j++;
      }
      dp[i] = cur;
    }
    for (int i = 0; i < n; i++) {
      ans += (1LL * (blocks - len + 1) % mod * dp[i] % mod);
      ans %= mod;
    }
    for (int i = 0; i < n; i++) {
      if (a[i].second < last) {
        ans += dp[i];
        ans %= mod;
      }
    }
  }
  ans %= mod;
  ans += mod;
  ans %= mod;
  out(ans);
  return 0;
}
