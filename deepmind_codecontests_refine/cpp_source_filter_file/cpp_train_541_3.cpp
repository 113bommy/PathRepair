#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> keks(n), kek;
  int sum = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> keks[i].second >> keks[i].first;
    sum += keks[i].second;
    keks[i].first++;
    keks[i].first %= m;
  }
  if (sum % m == 0) ans++;
  for (int i = 0; i < n; i++) {
    keks.push_back({(keks[i].first + m - 1) % m, -keks[i].second});
  }
  n *= 2;
  sort(keks.begin(), keks.end());
  for (int i = 0; i < n; i++) {
    if (kek.size() == 0 or keks[i].first != kek.back().first) {
      if (kek.size() != 0 and kek.back().second == 0) kek.pop_back();
      kek.push_back(keks[i]);
    } else {
      kek.back().second += keks[i].second;
    }
  }
  if (kek.size() == 1 and kek[0].second == 0) kek.pop_back();
  if (kek.size() == 0) {
    cout << -1 << endl;
    return;
  }
  int F = kek.size();
  int q = -1;
  for (int i = 0; i < F; i++) {
    int nxt = (i + 1) % F;
    if (kek[nxt].first - kek[i].first > 20 and q == -1)
      if (kek[nxt].first - kek[i].first > 20 and q == -1) q = i;
  }
  for (int k = 2; k <= n + 1; k++) {
    int lft = 0;
    int deg = 0;
    int flag = 0;
    for (int pos = 0; pos < kek.size() and flag == 0; pos++) {
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  int k2 = (1 << n);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    a[i]--;
  }
  vector<vector<int>> dp(k2 * 2);
  for (int i = 0; i < k2 * 2; i++) {
    dp[i].resize(4);
    for (int j = 0; j < 4; j++) {
      dp[i][j] = -100000;
    }
  }
  for (int i = 0; i < k; i++) {
    dp[a[i] + k2][1] = 0;
  }
  for (int i = 0; i < k2; i++) {
    if (dp[i + k2][1] != 0) dp[i + k2][0] = 0;
  }
  for (int j = k2 - 1; j >= k2 / 2; j--) {
    dp[j][0] = dp[j * 2][0] + dp[j * 2 + 1][0];
    dp[j][1] =
        max(dp[j * 2][1] + dp[j * 2 + 1][0], dp[j * 2][0] + dp[j * 2 + 1][1]) +
        1;
    dp[j][2] =
        max(dp[j * 2][1] + dp[j * 2 + 1][0], dp[j * 2][0] + dp[j * 2 + 1][1]) +
        1;
    dp[j][2] = max(dp[j][2], max(dp[j * 2][2] + dp[j * 2 + 1][0],
                                 dp[j * 2][0] + dp[j * 2 + 1][2]) +
                                 1);
    dp[j][2] = max(dp[j][2], dp[j * 2][2] + dp[j * 2 + 1][2] + 1);
    dp[j][3] =
        max(dp[j * 2][3] + dp[j * 2 + 1][0], dp[j * 2][0] + dp[j * 2 + 1][3]) +
        1;
    dp[j][3] = max(dp[j][3], max(dp[j * 2][1] + dp[j * 2 + 1][2],
                                 dp[j * 2][2] + dp[j * 2 + 1][1]) +
                                 1);
    dp[j][3] = max(dp[j][3], dp[j * 2][1] + dp[j * 2 + 1][1] + 1);
    dp[j][3] = max(dp[j][3], max(dp[j * 2][1] + dp[j * 2 + 1][3],
                                 dp[j * 2][3] + dp[j * 2 + 1][1]) +
                                 1);
    dp[j][3] = max(dp[j][3], max(dp[j * 2][2] + dp[j * 2 + 1][3],
                                 dp[j * 2][3] + dp[j * 2 + 1][2]) +
                                 1);
    dp[j][3] = max(dp[j][3], dp[j * 2][3] + dp[j * 2 + 1][3] + 1);
  }
  for (int j = k2 / 2 - 1; j >= 1; j--) {
    dp[j][0] = dp[j * 2][0] + dp[j * 2 + 1][0];
    dp[j][1] =
        max(dp[j * 2][1] + dp[j * 2 + 1][0], dp[j * 2][0] + dp[j * 2 + 1][1]) +
        1;
    dp[j][2] =
        max(dp[j * 2][1] + dp[j * 2 + 1][0], dp[j * 2][0] + dp[j * 2 + 1][1]) +
        2;
    dp[j][2] = max(dp[j][2], max(dp[j * 2][2] + dp[j * 2 + 1][0],
                                 dp[j * 2][0] + dp[j * 2 + 1][2]) +
                                 2);
    dp[j][2] = max(dp[j][2], dp[j * 2][2] + dp[j * 2 + 1][2] + 2);
    dp[j][3] =
        max(dp[j * 2][3] + dp[j * 2 + 1][0], dp[j * 2][0] + dp[j * 2 + 1][3]) +
        3;
    dp[j][3] = max(dp[j][3], max(dp[j * 2][1] + dp[j * 2 + 1][2],
                                 dp[j * 2][2] + dp[j * 2 + 1][1]) +
                                 3);
    dp[j][3] = max(dp[j][3], dp[j * 2][1] + dp[j * 2 + 1][1] + 2);
    dp[j][3] = max(dp[j][3], max(dp[j * 2][1] + dp[j * 2 + 1][3],
                                 dp[j * 2][3] + dp[j * 2 + 1][1]) +
                                 3);
    dp[j][3] = max(dp[j][3], max(dp[j * 2][2] + dp[j * 2 + 1][3],
                                 dp[j * 2][3] + dp[j * 2 + 1][2]) +
                                 3);
    dp[j][3] = max(dp[j][3], dp[j * 2][3] + dp[j * 2 + 1][3] + 3);
  }
  int ans = -100000;
  for (int i = 0; i < 4; i++) {
    ans = max(dp[1][i], ans);
  }
  if (k > 0) ans++;
  cout << ans << endl;
}
