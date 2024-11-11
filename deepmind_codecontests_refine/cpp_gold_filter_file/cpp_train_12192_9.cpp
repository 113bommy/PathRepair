#include <bits/stdc++.h>
struct Point {
  int x, y;
  int id;
};
using std::vector;
Point a[1005];
int mapX[1005], mapY[1005];
vector<Point> row[1005];
vector<Point> col[1005];
int id[2000005];
vector<int> g[4005];
int vis[4005];
int match[4005];
int edgeSet[4005];
int tag[4005];
int p[4005];
int lx[4005], rx[4005], ly[4005], ry[4005];
int keepX[4005], keepY[4005];
int getId(int u, int n, int map[]) {
  int L = 1, R = n;
  int res = -1;
  while (L <= R) {
    int M = (L + R) / 2;
    if (map[M] <= u) {
      res = M;
      L = M + 1;
    } else
      R = M - 1;
  }
  return res;
}
int getMap(int n, int map[]) {
  std::sort(map + 1, map + 1 + n);
  int p = 1, size = 0;
  while (p <= n) {
    int np = p;
    while (np + 1 <= n && map[np + 1] == map[p]) np++;
    map[++size] = map[p];
    p = np + 1;
  }
  return size;
}
void preWork(int n) {
  int sizeX = getMap(n, mapX), sizeY = getMap(n, mapY);
  for (int i = 1; i <= n; i++) {
    a[i].x = getId(a[i].x, sizeX, mapX);
    a[i].y = getId(a[i].y, sizeY, mapY);
  }
}
void addEdge(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}
int dfs(int u) {
  for (int v : g[u]) {
    if (!vis[v]) {
      vis[v] = 1;
      if (!match[v] || dfs(match[v])) {
        match[v] = u;
        return 1;
      }
    }
  }
  return 0;
}
int matching(int n, int m) {
  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n + m; j++) vis[j] = 0;
    res += dfs(i);
  }
  for (int i = n + 1; i <= n + m; i++) {
    if (match[i] != 0) tag[match[i]] = 1;
  }
  return res;
}
void getPath(int u) {
  vis[u] = 1;
  for (int v : g[u]) {
    if (!vis[v]) {
      vis[v] = 1;
      getPath(match[v]);
    }
  }
}
int find(int u) {
  if (p[u] == u)
    return p[u];
  else
    return p[u] = find(p[u]);
}
void merge(int x, int y) {
  int u = find(x), v = find(y);
  p[v] = u;
  if (lx[u] > lx[v]) lx[u] = lx[v];
  if (rx[u] < rx[v]) rx[u] = rx[v];
  if (ly[u] > ly[v]) ly[u] = ly[v];
  if (ry[u] < ry[v]) ry[u] = ry[v];
}
int getEdge(int n, int m, int size) {
  for (int i = 1; i <= n + m; i++) vis[i] = 0;
  for (int i = 1; i <= n; i++) {
    if (tag[i] == 0) {
      getPath(i);
    }
  }
  for (int i = 1; i <= 2 * size; i++) {
    p[i] = i;
    int j = i;
    if (j > size) j -= size;
    lx[i] = rx[i] = a[j].x;
    ly[i] = ry[i] = a[j].y;
  }
  int res = 0;
  for (int i = 1; i <= n + m; i++) {
    if ((i <= n && vis[i]) || (i > n && !vis[i])) {
      res++;
      Point u = a[edgeSet[i] / 1001], v = a[edgeSet[i] % 1001];
      if (u.x == v.x)
        merge(u.id, v.id);
      else
        merge(u.id + size, v.id + size);
    }
  }
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    a[i].id = i;
    mapX[i] = a[i].x, mapY[i] = a[i].y;
  }
  preWork(n);
  std::sort(a + 1, a + 1 + n, [&](Point& u, Point& v) { return u.x < v.x; });
  for (int i = 1; i <= n; i++) col[a[i].y].push_back(a[i]);
  std::sort(a + 1, a + 1 + n, [&](Point& u, Point& v) { return u.y < v.y; });
  for (int i = 1; i <= n; i++) row[a[i].x].push_back(a[i]);
  int total = 0;
  for (int i = 1; i <= n; i++) {
    if (col[i].size() >= 2) {
      int size = col[i].size();
      for (int j = 0; j < size - 1; j++) {
        int u = col[i][j].id, v = col[i][j + 1].id;
        int mask = u * 1001 + v;
        if (id[mask] == 0) {
          id[mask] = ++total;
          edgeSet[total] = mask;
        }
      }
    }
  }
  int stop = total;
  for (int i = n; i >= 1; i--) {
    if (row[i].size() >= 2) {
      int size = row[i].size();
      for (int j = 0; j < size - 1; j++) {
        int u = row[i][j].id, v = row[i][j + 1].id;
        int mask = u * 1001 + v;
        if (id[mask] == 0) {
          id[mask] = ++total;
          edgeSet[total] = mask;
        }
        for (int k = row[i][j].y + 1; k <= row[i][j + 1].y - 1; k++) {
          while (col[k].size() >= 2) {
            int tail = col[k].size() - 2;
            if (col[k][tail].x > i)
              col[k].pop_back();
            else
              break;
          }
          if (col[k].size() >= 2) {
            int tail = col[k].size() - 2;
            Point down = col[k][tail], up = col[k][col[k].size() - 1];
            if (down.x < i && up.x > i) {
              int u = id[mask], v = id[down.id * 1001 + up.id];
              addEdge(u, v);
            }
          }
        }
      }
    }
  }
  int maxEdge = total - matching(stop, total - stop);
  std::sort(a + 1, a + 1 + n, [&](Point& u, Point& v) { return u.id < v.id; });
  int realEdge = getEdge(stop, total - stop, n);
  for (int i = 1; i <= 2 * n; i++) vis[i] = 0;
  int sizeX = 0, sizeY = 0;
  for (int i = 1; i <= 2 * n; i++) {
    int u = find(i);
    if (!vis[u]) {
      vis[u] = 1;
      if (i <= n)
        keepX[++sizeX] = u;
      else
        keepY[++sizeY] = u;
    }
  }
  printf("%d\n", sizeY);
  for (int i = 1; i <= sizeY; i++) {
    int u = keepY[i];
    printf("%d %d %d %d\n", mapX[lx[u]], mapY[ly[u]], mapX[rx[u]], mapY[ry[u]]);
  }
  printf("%d\n", sizeX);
  for (int i = 1; i <= sizeX; i++) {
    int u = keepX[i];
    printf("%d %d %d %d\n", mapX[lx[u]], mapY[ly[u]], mapX[rx[u]], mapY[ry[u]]);
  }
  return 0;
}
