#include <bits/stdc++.h>
const int mod = 1000000007;
const int modx = 998244353;
using namespace std;
int n;
void func(vector<int> a, vector<int> &b) {
  int i;
  stack<int> s;
  s.push(0);
  for (i = 1; i < n; i++) {
    while (!s.empty() && a[s.top()] <= a[i]) {
      b[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  return;
}
void thunder() {
  cin >> n;
  vector<int> a(n), b(n);
  int i, j;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> g[n + 5];
  stack<int> s;
  s.push(0);
  for (i = 1; i < n; i++) {
    int p = 0;
    while (!s.empty() && a[s.top()] <= a[i]) {
      g[s.top()].push_back(i);
      g[i].push_back(s.top());
      if (a[s.top()] == a[i]) p = 1;
      s.pop();
    }
    if (!s.empty() && p == 0) {
      g[i].push_back(s.top());
      g[s.top()].push_back(i);
    }
    s.push(i);
  }
  while (!s.empty()) s.pop();
  s.push(0);
  for (i = 1; i < n; i++) {
    int p = 0;
    while (!s.empty() && a[s.top()] >= a[i]) {
      g[s.top()].push_back(i);
      g[i].push_back(s.top());
      if (a[s.top()] == a[i]) p = 1;
      s.pop();
    }
    if (!s.empty() && p == 0) {
      g[i].push_back(s.top());
      g[s.top()].push_back(i);
    }
    s.push(i);
  }
  queue<int> q;
  vector<int> dis(n + 5, -1), vis(n + 5, 0);
  dis[0] = 0;
  q.push(0);
  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    for (auto it : g[x]) {
      if (!vis[it]) {
        vis[it] = 1;
        dis[it] = dis[x] + 1;
        q.push(it);
      }
    }
  }
  vector<long long> dp(n + 5, INT_MAX);
  dp[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    for (auto u : g[i]) {
      if (u > i) dp[i] = min(dp[i], dp[u] + 1);
    }
  }
  cout << dp[0] << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) thunder();
}
