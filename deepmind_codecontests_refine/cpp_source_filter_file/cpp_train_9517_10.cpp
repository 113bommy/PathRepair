#include <bits/stdc++.h>
using namespace std;
struct monoqueue {
  deque<pair<long long, long long>> dq;
  int sz = 0;
  long long mn() { return dq.size() ? dq.front().first : 0x3f3f3f3f3f3f3f3f; }
  void push(long long v) {
    sz++;
    int cnt = 1;
    while (dq.size() && v <= dq.back().first)
      cnt += dq.back().second, dq.pop_back();
    dq.push_back({v, cnt});
  }
  void pop() {
    sz--;
    if (dq.front().second == 1) return dq.pop_front();
    dq.front().second--;
  }
  int size() { return sz; }
};
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(9),
      cout << fixed;
  int n, m, d;
  cin >> n >> m >> d;
  vector<pair<long long, pair<long long, long long>>> arr(m);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].second.first >> arr[i].second.second >> arr[i].first;
  }
  sort(arr.begin(), arr.end());
  vector<vector<long long>> dp(2, vector<long long>(n + 1));
  for (int i = 1; i <= n; ++i) {
    int a = arr[m - 1].second.first;
    int b = arr[m - 1].second.second;
    dp[(m - 1) & 1][i] = b - abs(a - i);
  }
  for (int i = m - 2; ~i; --i) {
    monoqueue q;
    for (int j = 1;
         j <= min(n * 1ll, 1 + 1ll * d * (arr[i + 1].first - arr[i].first));
         ++j) {
      q.push(-dp[(i + 1) & 1][j]);
    }
    int l = 1,
        r = min(1ll * n, 1 + 1ll * d * (arr[i + 1].first - arr[i].first));
    for (int j = 1; j <= n; ++j) {
      dp[i & 1][j] =
          -q.mn() + arr[i].second.second - abs(arr[i].second.first - j);
      if (r < n) {
        ++r;
        q.push(-dp[(i + 1) & 1][r]);
      }
      if (j - l + 1 > 1LL * d * (arr[i + 1].first - arr[i].first)) {
        ++l;
        q.pop();
      }
    }
  }
  long long ans = LLONG_MIN;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, dp[0][i]);
  }
  cout << ans << '\n';
  return 0;
}
