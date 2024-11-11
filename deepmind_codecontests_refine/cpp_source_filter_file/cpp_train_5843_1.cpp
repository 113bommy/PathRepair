#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using piii = pair<int, pii>;
using plll = pair<ll, pll>;
using pib = pair<int, bool>;
using pdi = pair<double, int>;
using pid = pair<int, double>;
using ld = long double;
using piiii = pair<pii, pii>;
int n, k, x, arr[5001];
ll dp[2][5001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  memset(dp, -1, sizeof dp);
  dp[0][0] = 0;
  for (int i = 1; i <= x; i++) {
    deque<pii> dq;
    for (int j = 0; j < i; j++) {
      while (!dq.empty() && dq.back().first <= dp[~i & 1][j]) dq.pop_back();
      dq.push_back({dp[~i & 1][j], j});
    }
    for (int j = i; j <= n; j++) {
      if (dq.front().second == j - k - 1) dq.pop_front();
      if (dq.front().first == -1) {
        dp[i & 1][j] = -1;
      } else
        dp[i & 1][j] = dq.front().first + arr[j];
      while (!dq.empty() && dq.back().first <= dp[~i & 1][j]) dq.pop_back();
      dq.push_back({dp[~i & 1][j], j});
    }
    for (int j = 0; j <= n; j++) {
      dp[~i & 1][j] = -1;
    }
  }
  ll ans = -1;
  for (int i = n - k + 1; i <= n; i++) {
    ans = max(ans, dp[x & 1][i]);
  }
  cout << ans << "\n";
  return 0;
}
