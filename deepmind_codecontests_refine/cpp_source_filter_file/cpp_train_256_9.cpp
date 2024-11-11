#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll inf = 1E17;
const ll mod = 1;
ll a[300010];
int n, k, chnk;
ll dp[501][501];
ll solve(int pos, int xtra, int l) {
  if (pos == 0) {
    if (xtra == 0) return 0;
    return inf;
  }
  ll &ret = dp[pos][xtra];
  if (ret != -1) return ret;
  ret = a[l + chnk - 1] - a[l] + solve(pos - 1, xtra, l + chnk);
  if (xtra)
    ret = min(ret, a[l + chnk] - a[l] + solve(pos - 1, xtra - 1, l + chnk + 1));
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  while (cin >> n >> k) {
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    memset(dp, -1, sizeof dp);
    chnk = n / k;
    cout << solve(k, n % k, 1) << endl;
  }
  return 0;
}
