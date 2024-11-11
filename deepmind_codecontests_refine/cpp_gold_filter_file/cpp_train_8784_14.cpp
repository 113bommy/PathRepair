#include <bits/stdc++.h>
using namespace std;
int n, m, k, h, t, tot, c[100010], vis[100010], lazy[100010], q[10000010],
    in[10010];
long long a[100010], ope[30], dis[10010];
void spfa() {
  memset(dis, 63, sizeof(dis));
  h = t = 0;
  q[++t] = 0;
  dis[0] = 0;
  in[0] = 1;
  while (h < t) {
    int x = q[++h];
    for (int i = 1; i <= tot; ++i)
      if (dis[x] + ope[i] < dis[(x + ope[i]) % k]) {
        dis[(x + ope[i]) % k] = dis[x] + ope[i];
        if (!in[(x + ope[i]) % k]) {
          in[(x + ope[i]) % k] = 1;
          q[++t] = (x + ope[i]) % k;
        }
      }
    in[x] = 0;
  }
}
int main() {
  scanf("%I64d%d%d%d", &h, &n, &m, &k);
  priority_queue<pair<int, int> > q;
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d%d", &a[i], &c[i]);
    --a[i];
    if (a[i] % k == 0) {
      q.push(make_pair(c[i], -i));
      vis[i] = 1;
    }
  }
  for (int i = 1; i <= m; ++i) {
    int o, x, y;
    scanf("%d", &o);
    if (o == 1) {
      ++tot;
      scanf("%I64d", &ope[tot]);
      spfa();
      for (int j = 1; j <= n; ++j)
        if (!vis[j]) {
          if (dis[a[j] % k] <= a[j]) {
            vis[j] = 1;
            q.push(make_pair(c[j], -j));
          }
        }
    } else if (o == 2) {
      scanf("%d%d", &x, &y);
      lazy[x] += y;
    } else {
      if (q.empty()) {
        printf("0\n");
      } else {
        while (1) {
          pair<int, int> now = q.top();
          q.pop();
          if (lazy[-now.second]) {
            now.first -= lazy[-now.second];
            lazy[-now.second] = 0;
            q.push(now);
          } else {
            printf("%d\n", now.first);
            break;
          }
        }
      }
    }
  }
  return 0;
}
