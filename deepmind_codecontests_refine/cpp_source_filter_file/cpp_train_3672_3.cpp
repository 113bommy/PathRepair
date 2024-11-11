#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t = 1, n;
  while (t--) {
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int b[n];
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; i++) {
      if (a[i] <= a[s.top()]) {
        s.push(i);
      } else {
        while (!s.empty() && a[i] > a[s.top()]) {
          b[s.top()] = i;
          s.pop();
        }
        s.push(i);
      }
    }
    while (!s.empty()) {
      b[s.top()] = -1;
      s.pop();
    }
    int c[n];
    stack<int> s1;
    s1.push(0);
    for (int i = 1; i < n; i++) {
      if (a[i] >= a[s1.top()]) {
        s1.push(i);
      } else {
        while (!s1.empty() && a[i] < a[s1.top()]) {
          c[s1.top()] = i;
          s1.pop();
        }
        s1.push(i);
      }
    }
    while (!s1.empty()) {
      c[s1.top()] = -1;
      s1.pop();
    }
    int d[n];
    s.push(n - 1);
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] <= a[s.top()]) {
        s.push(i);
      } else {
        while (!s.empty() && a[i] > a[s.top()]) {
          d[s.top()] = i;
          s.pop();
        }
        s.push(i);
      }
    }
    while (!s.empty()) {
      d[s.top()] = -1;
      s.pop();
    }
    int e[n];
    s1.push(n - 1);
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] >= a[s1.top()]) {
        s1.push(i);
      } else {
        while (!s1.empty() && a[i] < a[s1.top()]) {
          e[s1.top()] = i;
          s1.pop();
        }
        s1.push(i);
      }
    }
    while (!s1.empty()) {
      e[s1.top()] = -1;
      s1.pop();
    }
    vector<int> adj[n + 1];
    for (int i = 0; i < n; i++) {
      if (b[i] != -1) {
        adj[i].push_back(b[i]);
      }
      if (c[i] != -1) {
        adj[i].push_back(c[i]);
      }
      if (d[i] != -1) {
        adj[d[i]].push_back(i);
      }
      if (e[i] != -1) {
        adj[e[i]].push_back(i);
      }
    }
    int dp[n];
    for (int i = 0; i < n; i++) {
      dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      for (auto x : adj[i]) {
        dp[x] = min(dp[x], dp[i] + 1);
      }
    }
    cout << dp[n - 1] << endl;
  }
}
