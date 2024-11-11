#include <bits/stdc++.h>
using namespace std;
vector<int> all[2010];
int dist(pair<int, int> a, pair<int, int> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      all[i].push_back(j);
    }
  }
  for (int q = 0; q < k; q++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int d = sqrt(q);
    pair<int, int> ans(1000000, 1000000);
    for (int j = 0; j <= n && j <= dist(ans, make_pair(x, y)); j++) {
      for (int k = 0; k < 2; k++) {
        int i = j;
        if (k)
          i = min(n, i + k);
        else
          i = max(0, i - k);
        if (all[i].size() == 0) continue;
        int t = lower_bound(all[i].begin(), all[i].end(), y) - all[i].begin();
        int p1 = all[i][(t == all[i].size() ? t - 1 : t)];
        int p2 = all[i][(t - 1 == -1 ? t : t - 1)];
        pair<int, int> now(i, p2);
        if (abs(p1 - y) < abs(p2 - y)) now.second = p1;
        if (dist(make_pair(x, y), ans) > dist(make_pair(x, y), now)) ans = now;
        if (dist(make_pair(x, y), ans) == dist(make_pair(x, y), now) &&
            now < ans)
          ans = now;
      }
    }
    printf("%d %d\n", ans.first, ans.second);
    all[ans.first].erase(
        lower_bound(all[ans.first].begin(), all[ans.first].end(), ans.second));
  }
  return 0;
}
