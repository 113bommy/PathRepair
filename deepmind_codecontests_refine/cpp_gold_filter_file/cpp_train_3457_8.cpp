#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[100001], b[100001], c[100001];
vector<int> rev[100001];
vector<int> e[100001];
int get(int far) {
  int cur = k;
  for (int i = 1; i <= n; i++) {
    int x = e[i].back();
    rev[x].push_back(i);
  }
  priority_queue<int, vector<int>, greater<int> > q;
  for (int i = 1; i <= n; i++) {
    if (cur >= a[i])
      cur += b[i];
    else {
      while (!q.empty() && cur < a[i]) q.pop(), cur++;
      if (cur < a[i]) return -1;
      cur += b[i];
    }
    for (int j = 0; j < rev[i].size(); j++) q.push(c[rev[i][j]]), cur--;
  }
  int ans = 0;
  while (cur < 0) q.pop(), cur++;
  while (!q.empty()) ans += q.top(), q.pop();
  return ans;
}
signed main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u > v) swap(u, v);
    e[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    e[i].push_back(i);
    sort(e[i].begin(), e[i].end());
  }
  int ans = get(n);
  printf("%d", ans);
  return 0;
}
