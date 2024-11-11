#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int head[N], tot, n, m;
int cur[N];
struct node {
  int x, y;
} a[N];
struct Edge {
  int u, v, next;
  bool operator<(const Edge &rhs) const { return next < rhs.next; }
} edge[N * 10], o[N * 5];
void add(int u, int v) {
  edge[tot].v = v;
  edge[tot].next = head[u];
  head[u] = tot++;
}
bool dfs(int u, int f) {
  cur[u] = (cur[f] ^ 1);
  for (int i = head[u]; ~i; i = edge[i].next) {
    int v = edge[i].v;
    if (v == f || cur[v] == (cur[u] ^ 1)) continue;
    if (cur[v] == cur[u]) return false;
    if (!dfs(v, u)) return false;
  }
  return true;
}
int main() {
  memset(head, -1, sizeof(head)), tot = 0;
  memset(cur, -1, sizeof(cur));
  scanf("%d", &n);
  n *= 2;
  for (int i = 1; i <= n / 2; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    add(a[i].x, a[i].y);
    add(a[i].y, a[i].x);
  }
  for (int i = 1; i <= n; i += 2) {
    add(i, i + 1);
    add(i + 1, i);
  }
  for (int i = 1; i <= n; i++) {
    if (cur[i] != -1) continue;
    cur[i] = 0;
    dfs(i, i);
  }
  for (int i = 1; i <= n / 2; i++) {
    printf("%d %d\n", cur[a[i].x] + 1, cur[a[i].y] + 1);
  }
  return 0;
}
