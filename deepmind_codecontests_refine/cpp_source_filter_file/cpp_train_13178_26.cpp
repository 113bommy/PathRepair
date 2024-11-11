#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 1, mod = 1e9 + 9;
int dp[maxn], n, h[maxn], h_rev[maxn], seed = 313, poww[maxn];
long long ans;
string s;
void prepare() {
  poww[0] = 1;
  for (int i = 1; i < maxn; i++) {
    poww[i] = (poww[i - 1] * seed) % mod;
  }
  for (int i = 1; i <= n; i++) {
    h[i] = ((1ll * h[i - 1] * seed) % mod + (s[i - 1])) % mod;
  }
  for (int i = n; i >= 1; i--) {
    h_rev[i] = ((1ll * h_rev[i + 1] * seed) % mod + (s[i - 1])) % mod;
  }
  return;
}
int get(int R) { return h[R]; }
int get_rev(int L, int R) {
  return (h_rev[L] - (1ll * h_rev[R + 1] * poww[R - L + 1]) % mod + mod) % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  n = s.size();
  prepare();
  for (int i = 1; i <= n; i++) {
    int t2, t3, t4;
    if (i == 1) {
      t2 = 1;
      t3 = 1;
      t4 = 1;
    } else {
      t2 = i / 2;
      t3 = (i + 1) / 2 + 1;
      t4 = i;
    }
    if (get(t2) == get_rev(t3, t4)) {
      dp[i] = dp[i / 2] + 1;
    }
    ans += dp[i];
  }
  cout << ans << endl;
  return 0;
}
