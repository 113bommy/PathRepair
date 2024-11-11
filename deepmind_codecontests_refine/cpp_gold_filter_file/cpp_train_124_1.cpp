#include <bits/stdc++.h>
using namespace std;
int n, m, k;
inline int id(int x, int y, int z) {
  return x * (m + 2) * (k + 2) + y * (k + 2) + z;
}
int num[2000005], up[2000005];
bool vis[2000005];
struct Point {
  int x, y, z;
  Point() {}
  Point(int a, int b, int c) : x(a), y(b), z(c) {}
};
queue<Point> q;
bool bfs() {
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= k; j++) {
      int u = id(0, i, j), v = id(n + 1, i, j);
      up[u] = 1;
      if (!vis[id(1, i, j)]) {
        int t = id(1, i, j);
        if (!num[u] || (num[t] != -1 && num[t] != num[u])) {
          num[t] = 0;
          vis[t] = 1;
          q.push(Point(1, i, j));
        } else
          num[t] = num[u];
      }
      up[v] = n;
      if (!vis[id(n, i, j)]) {
        int t = id(n, i, j);
        if (!num[v] || (num[t] != -1 && num[t] != num[v])) {
          num[t] = 0;
          vis[t] = 1;
          q.push(Point(n, i, j));
        } else
          num[t] = num[v];
      }
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++) {
      int u = id(i, 0, j), v = id(i, m + 1, j);
      up[u] = 1;
      if (!vis[id(i, 1, j)]) {
        int t = id(i, 1, j);
        if (!num[u] || (num[t] != -1 && num[t] != num[u])) {
          num[t] = 0;
          vis[t] = 1;
          q.push(Point(i, 1, j));
        } else
          num[t] = num[u];
      }
      up[v] = m;
      if (!vis[id(i, m, j)]) {
        int t = id(i, m, j);
        if (!num[v] || (num[t] != -1 && num[t] != num[v])) {
          num[t] = 0;
          vis[t] = 1;
          q.push(Point(i, m, j));
        } else
          num[t] = num[v];
      }
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int u = id(i, j, 0), v = id(i, j, k + 1);
      up[u] = 1;
      if (!vis[id(i, j, 1)]) {
        int t = id(i, j, 1);
        if (!num[u] || (num[t] != -1 && num[t] != num[u])) {
          num[t] = 0;
          vis[t] = 1;
          q.push(Point(i, j, 1));
        } else
          num[t] = num[u];
      }
      up[v] = k;
      if (!vis[id(i, j, k)]) {
        int t = id(i, j, k);
        if (!num[v] || (num[t] != -1 && num[t] != num[v])) {
          num[t] = 0;
          vis[t] = 1;
          q.push(Point(i, j, k));
        } else
          num[t] = num[v];
      }
    }
  while (!q.empty()) {
    Point t = q.front();
    q.pop();
    int x = t.x, y = t.y, z = t.z;
    int u = id(x, y, z);
    int v = id(0, y, z);
    while (up[v] <= n && vis[id(up[v], y, z)]) up[v]++;
    if (up[v] <= n && !vis[id(up[v], y, z)]) {
      int t = id(up[v], y, z);
      if (!num[v] || (num[t] != -1 && num[t] != num[v])) {
        num[t] = 0;
        vis[t] = 1;
        q.push(Point(up[v], y, z));
      } else
        num[t] = num[v];
    }
    v = id(n + 1, y, z);
    while (up[v] && vis[id(up[v], y, z)]) up[v]--;
    if (up[v] && !vis[id(up[v], y, z)]) {
      int t = id(up[v], y, z);
      if (!num[v] || (num[t] != -1 && num[t] != num[v])) {
        num[t] = 0;
        vis[t] = 1;
        q.push(Point(up[v], y, z));
      } else
        num[t] = num[v];
    }
    v = id(x, 0, z);
    while (up[v] <= m && vis[id(x, up[v], z)]) up[v]++;
    if (up[v] <= m && !vis[id(x, up[v], z)]) {
      int t = id(x, up[v], z);
      if (!num[v] || (num[t] != -1 && num[t] != num[v])) {
        num[t] = 0;
        vis[t] = 1;
        q.push(Point(x, up[v], z));
      } else
        num[t] = num[v];
    }
    v = id(x, m + 1, z);
    while (up[v] && vis[id(x, up[v], z)]) up[v]--;
    if (up[v] && !vis[id(x, up[v], z)]) {
      int t = id(x, up[v], z);
      if (!num[v] || (num[t] != -1 && num[t] != num[v])) {
        num[t] = 0;
        vis[t] = 1;
        q.push(Point(x, up[v], z));
      } else
        num[t] = num[v];
    }
    v = id(x, y, 0);
    while (up[v] <= k && vis[id(x, y, up[v])]) up[v]++;
    if (up[v] <= k && !vis[id(x, y, up[v])]) {
      int t = id(x, y, up[v]);
      if (!num[v] || (num[t] != -1 && num[t] != num[v])) {
        num[t] = 0;
        vis[t] = 1;
        q.push(Point(x, y, up[v]));
      } else
        num[t] = num[v];
    }
    v = id(x, y, k + 1);
    while (up[v] && vis[id(x, y, up[v])]) up[v]--;
    if (up[v] && !vis[id(x, y, up[v])]) {
      int t = id(x, y, up[v]);
      if (!num[v] || (num[t] != -1 && num[t] != num[v])) {
        num[t] = 0;
        vis[t] = 1;
        q.push(Point(x, y, up[v]));
      } else
        num[t] = num[v];
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int l = 1; l <= k; l++)
        if (num[id(i, j, l)] == -1) num[id(i, j, l)] = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= k; j++) {
      if (num[id(0, i, j)] && up[id(0, i, j)] > n) return 0;
      if (num[id(n + 1, i, j)] && up[id(n + 1, i, j)] < 1) return 0;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++) {
      if (num[id(i, 0, j)] && up[id(i, 0, j)] > m) return 0;
      if (num[id(i, m + 1, j)] && up[id(i, m + 1, j)] < 1) return 0;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (num[id(i, j, 0)] && up[id(i, j, 0)] > k) return 0;
      if (num[id(i, j, k + 1)] && up[id(i, j, k + 1)] < 1) return 0;
    }
  return 1;
}
int main() {
  memset(num, 255, sizeof(num));
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= k; j++) scanf("%d", &num[id(0, i, j)]);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= k; j++) scanf("%d", &num[id(n + 1, i, j)]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++) scanf("%d", &num[id(i, 0, j)]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++) scanf("%d", &num[id(i, m + 1, j)]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &num[id(i, j, 0)]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &num[id(i, j, k + 1)]);
  if (!bfs()) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int l = 1; l <= k; l++) printf("%d ", num[id(i, j, l)]);
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
