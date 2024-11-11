#include <bits/stdc++.h>
using namespace std;
vector<int> a[111111];
queue<int> q;
int d[111111], f[111111], is[111111];
int n, m, k, s, t;
int ok(int maxi) {
  while (!q.empty()) q.pop();
  for (int i = (1); i <= (n); ++i) {
    d[i] = 0;
    f[i] = 0;
  }
  f[s] = maxi;
  d[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (!f[u]) continue;
    d[u] = 2;
    for (int i = (0); i < (a[u].size()); ++i) {
      int v = a[u][i];
      if (v == t) return 1;
      int tmp = (is[v]) ? maxi : f[u] - 1;
      if (tmp > f[v]) {
        if (v == t) return 1;
        f[v] = tmp;
        if (d[v] != 1) q.push(v), d[v] = 1;
      }
    }
  }
  return 0;
}
int main() {
  int u, v;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = (1); i <= (k); ++i) {
    scanf("%d", &u);
    is[u] = 1;
  }
  for (int i = (1); i <= (m); ++i) {
    scanf("%d %d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  scanf("%d %d", &s, &t);
  int l, r, mid;
  l = 0;
  r = d[t];
  while (l < r) {
    mid = (l + r) / 2;
    if (ok(mid))
      r = mid;
    else
      l = mid + 1;
  }
  if (ok(l))
    printf("%d", l);
  else
    printf("-1");
  return 0;
}
