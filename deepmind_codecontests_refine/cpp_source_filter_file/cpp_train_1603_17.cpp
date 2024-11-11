#include <bits/stdc++.h>
int n, m, ans, a[200005], b[200005];
bool vis[2000005], first;
std::priority_queue<int> q[2000005];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
    scanf("%d%d", &a[i], &b[i]), q[a[i]].push(a[i] + b[i] - 1);
  for (int i = 1; i <= n; i++) {
    if (!first) {
      for (; q[i].empty(); i++)
        ;
      first = 1;
    }
    int maxr = q[i].top(), k;
    for (int j = i + 1; j <= q[i].top() && j <= n; j++) {
      if (!q[j].empty()) {
        if (q[j].top() > maxr) {
          k = j;
          maxr = q[j].top();
        }
      }
    }
    vis[i] = 1;
    ans++;
    if (maxr > q[i].top()) {
      i = k - 1;
    } else {
      for (i = q[i].top() + 1; q[i].empty() && i <= n + 1; i++)
        ;
      i--;
    }
  }
  printf("%d\n", m - ans);
  for (int i = 1; i <= m; i++) {
    if (vis[a[i]]) {
      if (a[i] + b[i] - 1 != q[a[i]].top())
        printf("%d ", i);
      else
        vis[a[i]] = 0;
    } else
      printf("%d ", i);
  }
  return 0;
}
