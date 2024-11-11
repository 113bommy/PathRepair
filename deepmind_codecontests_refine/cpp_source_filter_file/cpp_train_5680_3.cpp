#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int inf = INT_MAX;
int n, m, s, ans, now = 1, w[N], v[N], c[N], nex[N], head[N];
void add(int x, int y, int co, int z) {
  nex[++now] = head[x], w[now] = z;
  head[x] = now, v[now] = y, c[now] = co;
}
int vi[N], dis[N], way[N], bfe[N];
queue<int> que;
bool spfa() {
  for (int i = 0; i < s; i++) dis[i] = inf;
  que.push(s), dis[s] = 0, way[s] = inf;
  while (!que.empty()) {
    int x = que.front();
    que.pop(), vi[x] = 0;
    for (int i = head[x]; i; i = nex[i])
      if (w[i] && dis[x] + c[i] < dis[v[i]]) {
        dis[v[i]] = dis[x] + c[i];
        bfe[v[i]] = i ^ 1, way[v[i]] = min(way[x], w[i]);
        if (!vi[v[i]]) que.push(v[i]), vi[v[i]] = 1;
      }
  }
  return dis[0] != inf;
}
int flow[N];
int main() {
  scanf("%d%d", &n, &m), s = n + 1;
  for (int i = 1, x, y, c, f; i <= m; i++) {
    scanf("%d%d%d%d", &x, &y, &c, &f);
    flow[x] -= f, flow[y] += f;
    if (c < f) {
      ans += f - c;
      add(x, y, 2, inf), add(y, x, -2, 0);
      add(y, x, 0, f - c), add(x, y, 0, 0);
      add(y, x, 2, inf), add(x, y, -2, 0);
    } else {
      add(x, y, 2, inf), add(y, x, -2, 0);
      add(y, x, 1, inf), add(x, y, -1, 0);
      if (c != f) add(x, y, 1, c - f), add(y, x, -1, 0);
    }
  }
  add(n, 1, 0, inf), add(1, n, 0, 0);
  for (int i = 2; i < n; i++)
    if (flow[i] < 0) {
      add(i, 0, 0, -flow[i]), add(0, i, 0, 0);
      add(s, n, 0, -flow[i]), add(n, s, 0, 0);
    } else if (flow[i] > 0) {
      add(s, i, 0, flow[i]), add(i, s, 0, 0);
      add(1, 0, 0, flow[i]), add(0, 1, 0, 0);
    }
  while (spfa()) {
    int x = 0;
    while (x != s) {
      w[bfe[x]] += way[0];
      w[bfe[x] ^ 1] -= way[0];
      x = v[bfe[x]];
    }
    ans += way[0] * dis[0];
  }
  printf("%d\n", ans);
  return 0;
}
