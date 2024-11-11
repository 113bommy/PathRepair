#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
const int INF = 0x3f3f3f3f, N = 5e5 + 5;
const ll LINF = 1e18 + 5;
constexpr int mod = 1e9 + 7;
int k, n;
int t[N], d[N];
ll dp[N];
int cal(ll x) {
  for (int i = 2; i <= n; i++) {
    if (dp[i - 1] <= dp[i - 2] + t[i] - t[i - 1] - x) {
      dp[i] = dp[i - 1];
      d[i] = d[i - 1];
    } else {
      dp[i] = dp[i - 2] + t[i] - t[i - 1] - x;
      d[i] = d[i - 2] + 1;
    }
  }
  return d[n];
}
int main() {
  scanf("%d%d", &k, &n);
  for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
  sort(t + 1, t + n + 1);
  ll l = 0, r = 1e10, c = 0;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if (cal(mid) <= k)
      c = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  cal(c);
  printf("%lld\n", dp[n] + k * c);
  return 0;
}
