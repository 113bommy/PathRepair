#include <bits/stdc++.h>
std::priority_queue<std::pair<long long, int> > vec[250005];
int app[250005], seq[250005], m[250005], p[250005], r[250005], x[250005],
    y[250005];
bool vis[250005];
int main() {
  int n;
  scanf("%d%d%d%d%d", x, y, p, r, &n);
  vis[0] = true;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d%d%d", x + i, y + i, m + i, p + i, r + i);
    app[i] = m[i];
  }
  std::sort(app + 1, app + n + 1);
  int cnt = std::unique(app + 1, app + n + 1) - app - 1;
  for (int i = 1; i <= n; i++) {
    int pos = std::lower_bound(app + 1, app + cnt + 1, m[i]) - app;
    long long d = (long long)(x[i] - x[0]) * (x[i] - x[0]) +
                  (long long)(y[i] - y[0]) * (y[i] - y[0]);
    for (int j = pos; j <= cnt; j += j & -j) vec[j].push(std::make_pair(-d, i));
  }
  int ans = 0;
  for (int i = 0; i <= ans; i++) {
    int pos = std::upper_bound(app + 1, app + cnt + 1, p[seq[i]]) - app - 1;
    for (int j = pos; j; j -= j & -j) {
      while (!vec[j].empty() &&
             -vec[j].top().first <= (long long)r[seq[i]] * r[seq[i]]) {
        if (!vis[vec[j].top().second]) {
          seq[++ans] = vec[j].top().second;
          vis[vec[j].top().second] = true;
        }
        vec[j].pop();
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
