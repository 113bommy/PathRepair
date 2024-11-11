#include <bits/stdc++.h>
using namespace std;
vector<long long> adj[100005];
int main() {
  long long i, j, k, n, m, c, t;
  scanf("%lld", &n);
  vector<long long> a;
  for (i = 0; i < n; i++) {
    scanf("%lld", &c);
    if (c) a.push_back(c);
  }
  n = a.size();
  if (n > 185) {
    printf("3\n");
    return 0;
  }
  for (i = 0; i <= 61; i++) {
    vector<long long> v;
    for (j = 0; j < n; j++) {
      if ((a[j] >> i) & 1) v.push_back(j);
    }
    if (v.size() == 3) {
      printf("3");
      return 0;
    }
    if (v.size() == 2) {
      adj[v[0]].push_back(v[1]);
      adj[v[1]].push_back(v[0]);
    }
  }
  long long mx = 1e10, ans = 1e10;
  for (i = 0; i < n; i++) {
    vector<long long> dis(n, mx), pre(n, -1);
    dis[i] = 0;
    queue<long long> q;
    q.push(i);
    while (!q.empty()) {
      k = q.front();
      q.pop();
      for (auto x : adj[k]) {
        if (dis[x] == mx) {
          pre[x] = k;
          dis[x] = dis[k] + 1;
          q.push(x);
        } else if (pre[k] != x && pre[x] != k) {
          ans = min(ans, dis[k] + dis[x] + 1);
        }
      }
    }
  }
  if (ans == mx) ans = -1;
  printf("%lld\n", ans);
}
