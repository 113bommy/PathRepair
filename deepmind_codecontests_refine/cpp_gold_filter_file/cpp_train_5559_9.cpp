#include <bits/stdc++.h>
const int N = 305;
const int M = 5050;
const int MAXM = 200000;
bool map[N][N];
int n, m, mz;
int s[N], t[N];
int ever[N], kind = 0, pre[N], depth[N];
int route[N], lan[N], jiea[N], jieb[N];
int add[N], del[N];
int a[MAXM], b[MAXM], c[MAXM], cc = 0;
void dfs(int x, int grand) {
  int i;
  ever[x] = kind;
  pre[x] = grand;
  depth[x] = depth[grand] + 1;
  for (i = 1; i <= n; i++) {
    if (map[x][i]) {
      if (!ever[i]) dfs(i, x);
    }
  }
}
void opt(int from, int to, int val) {
  if (!val) return;
  cc++;
  a[cc] = from;
  b[cc] = to;
  c[cc] = val;
  s[from] -= val;
  s[to] += val;
}
void trans(int from, int to, int val) {
  int i;
  jiea[0] = 0;
  jieb[0] = 0;
  while (depth[from] > depth[to]) {
    jiea[++jiea[0]] = from;
    from = pre[from];
  }
  while (depth[from] < depth[to]) {
    jieb[++jieb[0]] = to;
    to = pre[to];
  }
  while (from != to) {
    jiea[++jiea[0]] = from;
    from = pre[from];
    jieb[++jieb[0]] = to;
    to = pre[to];
  }
  jiea[++jiea[0]] = from;
  route[0] = 0;
  for (i = 1; i <= jiea[0]; i++) route[++route[0]] = jiea[i];
  for (i = jieb[0]; i >= 1; i--) route[++route[0]] = jieb[i];
  for (i = route[0] - 1; i >= 1; i--) {
    if (s[route[i]] < val) {
      lan[i] = val - s[route[i]];
      opt(route[i], route[i + 1], s[route[i]]);
    } else {
      lan[i] = 0;
      opt(route[i], route[i + 1], val);
    }
  }
  for (i = 1; i < route[0]; i++) {
    if (lan[i]) opt(route[i], route[i + 1], lan[i]);
  }
}
bool make(int x) {
  int i;
  kind++;
  dfs(x, 0);
  add[0] = 0;
  del[0] = 0;
  long long sum = 0;
  for (i = 1; i <= n; i++) {
    if (ever[i] == kind) {
      sum += s[i];
      sum -= t[i];
    }
  }
  if (sum != 0) return 0;
  for (i = 1; i <= n; i++) {
    if (ever[i] == kind) {
      if (s[i] < t[i]) add[++add[0]] = i;
      if (s[i] > t[i]) del[++del[0]] = i;
    }
  }
  int point = 1;
  for (i = 1; i <= del[0]; i++) {
    int now = del[i];
    while (s[now] - t[now] > t[add[point]] - s[add[point]]) {
      trans(now, add[point], t[add[point]] - s[add[point]]);
      point++;
    }
    trans(now, add[point], s[now] - t[now]);
    if (s[add[point]] == t[add[point]]) point++;
  }
  return 1;
}
int main() {
  int i, j;
  scanf("%d%d%d", &n, &mz, &m);
  for (i = 1; i <= n; i++) scanf("%d", &s[i]);
  for (i = 1; i <= n; i++) scanf("%d", &t[i]);
  for (i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u != v) {
      map[u][v] = 1;
      map[v][u] = 1;
    }
  }
  for (i = 1; i <= n; i++) {
    if (!ever[i]) {
      if (!make(i)) {
        printf("NO\n");
        return 0;
      }
    }
  }
  printf("%d\n", cc);
  for (i = 1; i <= cc; i++) printf("%d %d %d\n", a[i], b[i], c[i]);
  return 0;
}
