#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 500, INF = 999999;
vector<int> adj[MAX_N];
int ans[MAX_N], q[MAX_N], n, m;
int main() {
  cin >> n >> m;
  bool bus = 0;
  fill(ans, ans + n + 1, INF);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    if ((a == 1 && b == n) || (a == n && b == 1)) {
      bus = 1;
    }
  }
  if (!bus) {
    int h = 0, t = 0;
    ans[1] = 0;
    q[t++] = 1;
    while (h < t) {
      int v = q[h++];
      for (int u : adj[v]) {
        if (ans[v] + 1 < ans[u]) {
          ans[u] = ans[v] + 1;
          q[t++] = u;
        }
      }
    }
  } else {
    int h = 0, t = 0;
    ans[1] = 0;
    q[t++] = 1;
    while (h < t) {
      int v = q[h++];
      for (int i = 1; i <= n; i++) {
        bool jade = true;
        for (int u : adj[v]) {
          if (i == u) jade = false;
        }
        if (ans[v] + 1 < ans[i] && jade && i != v) {
          ans[i] = ans[v] + 1;
          q[t++] = i;
        }
      }
    }
  }
  if (ans[n] == INF) {
    cout << -1;
    return 0;
  }
  cout << ans[n];
}
