#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> ans[N];
priority_queue<pair<int, int> > q;
int t, n, m, k, c, d, x, y, cnt, temp;
bool vis[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &m, &k);
    c = n / m;
    d = ceil(1.0 * n / m);
    x = 0;
    y = 0;
    temp = n;
    while (true) {
      if (temp % c == 0 && temp / c + x == m) break;
      temp -= d;
      x++;
    }
    while (!q.empty()) q.pop();
    for (int i = 1; i <= n; i++) q.push({0, i});
    for (int i = 1; i <= k; i++) {
      cnt = 0;
      for (int j = 1; j <= n; j++) vis[j] = 0;
      while (!q.empty() && cnt + 1 <= x * d) {
        int val = -q.top().first, u = q.top().second;
        q.pop();
        vis[u] = 1;
        cnt++;
        ans[i].push_back(u);
        q.push({-(val + 1), u});
      }
      for (int j = 1; j <= n; j++)
        if (!vis[j]) ans[i].push_back(j);
    }
    for (int i = 1; i <= k; i++) {
      for (int j = 0; j < x * d; j++) {
        if (!(j % d)) printf("%d ", d);
        if ((j + 1) % d)
          printf("%d ", ans[i][j]);
        else
          printf("%d\n", ans[i][j]);
      }
      for (int j = x * d; j < n; j++) {
        if (!((j - x * d) % c)) printf("%d ", c);
        if ((j - x * d + 1) % c)
          printf("%d ", ans[i][j]);
        else
          printf("%d\n", ans[i][j]);
      }
      ans[i].clear();
    }
    puts("");
  }
  return 0;
}
