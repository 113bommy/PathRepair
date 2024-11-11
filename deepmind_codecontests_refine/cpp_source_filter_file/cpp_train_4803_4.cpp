#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct Edge {
  int from, to, nex, w, steins;
} edge[N];
int h[N], idx;
int cg[N], k;
int in[N], id[N];
int n, m;
void add(int u, int v, int w, int st) {
  Edge E = {u, v, h[u], w, st};
  edge[idx] = E;
  h[u] = idx++;
}
int check(int mid) {
  int kc = 0;
  memset(in, 0, sizeof(in));
  memset(id, 0, sizeof(id));
  for (int i = 1; i <= n; i++) {
    for (int j = h[i]; ~j; j = edge[j].nex) {
      if (edge[j].w <= mid) continue;
      int v = edge[j].to;
      ++in[v];
    }
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (!in[i]) q.push(i);
  }
  int cnt = 0;
  while (!q.empty()) {
    int t = q.front();
    id[t] = kc++;
    cnt++;
    q.pop();
    for (int i = h[t]; ~i; i = edge[i].nex) {
      if (edge[i].w <= mid) continue;
      int v = edge[i].to;
      --in[v];
      if (!in[v]) {
        q.push(v);
      }
    }
  }
  if (cnt != n) return 0;
  k = 0;
  for (int i = 1; i <= n; i++)
    for (int j = h[i]; ~j; j = edge[j].nex) {
      if (edge[j].w > mid) continue;
      int v = edge[j].to;
      if (id[v] < id[i]) {
        cg[++k] = edge[j].steins;
      }
    }
  return 1;
}
int main() {
  memset(h, -1, sizeof(h));
  scanf("%d%d", &n, &m);
  int r = 0;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c, i);
    r = max(r, c);
  }
  int l = 0, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid - 1, ans = mid;
    else
      l = mid + 1;
  }
  sort(cg + 1, cg + k + 1);
  printf("%d %d\n", ans, k);
  for (int i = 1; i <= k; ++i) printf("%d ", cg[i]);
  return 0;
}
