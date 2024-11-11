#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
const ll mod = 1e9 + 7, inf = 1e18;
int main() {
  int n;
  cin >> n;
  ll sum = 0;
  vl a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % 3 != 0) {
    cout << 0;
    return 0;
  }
  vl dp(n);
  ll cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    cur += a[i];
    if (cur == sum / 3 && i >= 2) dp[i] += 1;
    if (i < n - 1) dp[i] += dp[i + 1];
  }
  cur = 0;
  ll ans = 0;
  for (int i = 0; i < n - 2; i++) {
    cur += a[i];
    if (cur == sum / 3) ans += dp[i + 2];
  }
  cout << ans;
  return 0;
}
