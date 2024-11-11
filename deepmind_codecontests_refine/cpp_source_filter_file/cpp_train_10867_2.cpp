#include <bits/stdc++.h>
using namespace std;
void read(int &k) {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  k = x * f;
}
int n, d, nn;
int a[105], p[105], dis[105], flag[105];
struct node {
  int x, y;
} city[105];
struct edge {
  int a, b, nt, w;
} e[100005 * 2];
void anode(int x, int y, int w) {
  nn++;
  e[nn].a = x;
  e[nn].b = y;
  e[nn].nt = p[x];
  p[x] = nn;
  e[nn].w = w;
}
int dist(node a, node b) { return abs(a.x - b.x) + abs(a.y - b.y); }
void spfa(int x) {
  queue<int> q;
  q.push(x);
  for (int i = 1; i <= n; i++) dis[i] = 0x7fffffff, flag[i] = 0;
  dis[x] = 0, flag[x] = 1;
  while (!q.empty()) {
    int k = q.front();
    q.pop();
    flag[k] = 0;
    for (int i = p[k]; i; i = e[i].nt) {
      int v = e[i].b;
      if (dis[v] > dis[k] + e[i].w) {
        dis[v] = dis[k] + e[i].w;
        if (!flag[v]) {
          flag[v] = 1;
          q.push(v);
        }
      }
    }
  }
}
int main() {
  read(n), read(d);
  for (int i = 1; i < n - 1; i++) read(a[i]);
  for (int i = 1; i <= n; i++) read(city[i].x), read(city[i].y);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      anode(i, j, d * dist(city[i], city[j]) - a[j]);
      anode(j, i, d * dist(city[i], city[j]) - a[i]);
    }
  spfa(1);
  printf("%d\n", dis[n]);
  return 0;
}
