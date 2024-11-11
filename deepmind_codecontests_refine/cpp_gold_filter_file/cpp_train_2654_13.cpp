#include <bits/stdc++.h>
using namespace std;
vector<long> a[500005];
long long ans, n, m, i, c0, c1;
long x, y;
int color[100005];
bool bfs(long i) {
  if (color[i] != -1) return true;
  color[i] = 1;
  c1++;
  queue<long> q;
  q.push(i);
  while (!q.empty()) {
    long u = q.front();
    q.pop();
    for (long v = 0; v < a[u].size(); v++) {
      if (color[a[u][v]] == -1) {
        color[a[u][v]] = 1 - color[u];
        if (color[a[u][v]] == 0)
          c0++;
        else
          c1++;
        q.push(a[u][v]);
      } else if (color[u] == color[a[u][v]])
        return false;
    }
  }
  return true;
}
bool check() {
  for (i = 0; i < n; i++) color[i + 1] = -1;
  for (i = 0; i < n; i++) {
    c1 = 0;
    c0 = 0;
    if (bfs(i + 1)) {
      ans += (c1 * (c1 - 1)) / 2 + (c0 * (c0 - 1)) / 2;
    } else
      return true;
  }
  return false;
}
int main() {
  scanf("%lld%lld", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%ld%ld", &x, &y);
    a[x].push_back(y);
    a[y].push_back(x);
  }
  ans = (n * (n - 1) * (n - 2)) / 6;
  if (m == 0) {
    printf("3 %lld", ans);
    return 0;
  }
  ans = 0;
  if (check())
    printf("0 1");
  else if (ans == 0)
    printf("2 %lld", m * (n - 2));
  else
    printf("1 %lld", ans);
  return 0;
}
