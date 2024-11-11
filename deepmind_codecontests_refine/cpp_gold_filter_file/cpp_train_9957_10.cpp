#include <bits/stdc++.h>
using namespace std;
int const maxn = 3e5 + 10;
set<int> q[maxn];
priority_queue<int> pq;
int dp[maxn], ans[maxn], vis[maxn];
int main() {
  int n, k;
  cin >> n >> k;
  int tk = k;
  int cnt = 0;
  ans[++cnt] = 1;
  for (int i = 2; i <= n; i++) dp[i]++, q[1].insert(i);
  pq.push(1);
  int mx = 1;
  while (mx < n && k && !pq.empty()) {
    int x = 0;
    while (pq.top() > k) pq.pop();
    x = pq.top();
    while (!q[x].empty() && *q[x].begin() < mx) q[x].erase(q[x].begin());
    if (q[x].empty()) {
      pq.pop();
      continue;
    }
    k -= x;
    int t = *q[x].begin();
    mx = t;
    vis[t] = 1;
    ans[++cnt] = t;
    for (int i = t; i <= n; i += t) {
      q[dp[i]].erase(i);
      if (q[dp[i]].empty()) pq.pop();
      if (i == t) continue;
      dp[i]++;
      if (q[dp[i]].empty()) pq.push(dp[i]);
      q[dp[i]].insert(i);
    }
    dp[t] = -1;
  }
  if (k) {
    for (int i = 2; i <= n; i++) {
      if (vis[i]) continue;
      int tmp = dp[i];
      for (int j = i + i; j <= n; j += i) {
        if (vis[j]) tmp++;
      }
      if (tmp <= k) {
        k -= tmp;
        ans[++cnt] = i;
        vis[i] = 1;
        if (!k) break;
        for (int j = i + i; j <= n; j += i) {
          dp[j]++;
        }
      }
    }
  }
  if (k) {
    k = tk;
    memset(vis, 0, sizeof(vis));
    memset(dp, 0, sizeof(dp));
    int sum = 0;
    int p;
    for (int i = 1; i <= n; i++) {
      sum += dp[i];
      vis[i] = 1;
      p = i;
      if (sum >= k) break;
      for (int j = i + i; j <= n; j += i) {
        dp[j]++;
      }
    }
    sum -= k;
    for (int i = p; i >= 1; i--) {
      int tmp = dp[i];
      for (int j = i + i; j <= p; j += i) {
        if (vis[j]) tmp++;
      }
      if (tmp <= sum) {
        vis[i] = 0;
        sum -= tmp;
        if (!sum) break;
      }
    }
    if (sum == 0) {
      k = 0;
      cnt = 0;
      for (int i = 1; i <= p; i++) {
        if (vis[i]) ans[++cnt] = i;
      }
    }
  }
  if (k) {
    memset(dp, 0, sizeof(dp));
    k = tk;
    cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (dp[i] <= k) {
        ans[++cnt] = i;
        k -= dp[i];
        if (!k) break;
        for (int j = i + i; j <= n; j += i) dp[j]++;
      }
    }
  }
  if (k) {
    memset(dp, 0, sizeof(dp));
    k = tk;
    cnt = 0;
    for (int i = n; i >= 1; i--) {
      int tmp = 0;
      for (int j = i + i; j <= n; j += i) {
        if (dp[j]) tmp++;
      }
      if (tmp <= k) {
        k -= tmp;
        ans[++cnt] = i;
        dp[i] = 1;
        if (!k) break;
      }
    }
  }
  if (k)
    cout << "No";
  else {
    cout << "Yes" << endl;
    cout << cnt << endl;
    for (int i = 1; i <= cnt; i++) cout << ans[i] << ' ';
  }
  cout << endl;
}
