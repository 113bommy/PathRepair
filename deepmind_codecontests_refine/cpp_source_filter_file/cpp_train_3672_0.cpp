#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 1;
long long h[N];
vector<long long> adj[N];
long long dp[N];
long long n;
long long solve(long long pos) {
  if (pos == n) return 0;
  if (dp[pos] != -1) return dp[pos];
  long long ans = 1e18;
  for (auto &x : adj[pos]) {
    ans = min(ans, 1 + solve(x));
  }
  dp[pos] = ans;
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> h[i];
  stack<long long> st1, st2;
  st1.push(n);
  st2.push(n);
  for (long long i = n - 1; i >= 1; i--) {
    while (!st1.empty() && h[st1.top()] < h[i]) {
      st1.pop();
    }
    if (st1.empty())
      adj[i].push_back(i + 1);
    else
      adj[i].push_back(st1.top());
    st1.push(i);
    while (!st2.empty() && h[st2.top()] > h[i]) {
      st2.pop();
    }
    if (st2.empty())
      adj[i].push_back(i + 1);
    else
      adj[i].push_back(st2.top());
    st2.push(i);
  }
  while (!st1.empty()) st1.pop();
  while (!st2.empty()) st2.pop();
  st1.push(1);
  st1.push(1);
  for (long long i = 2; i <= n; i++) {
    while (!st1.empty() && h[st1.top()] < h[i]) {
      st1.pop();
    }
    if (st1.empty())
      adj[i - 1].push_back(i);
    else
      adj[st1.top()].push_back(i);
    st1.push(i);
    while (!st2.empty() && h[st2.top()] > h[i]) {
      st2.pop();
    }
    if (st2.empty())
      adj[i - 1].push_back(i);
    else
      adj[st2.top()].push_back(i);
    st2.push(i);
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(1);
}
