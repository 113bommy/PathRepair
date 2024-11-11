#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const int N = 500005;
int p[N * 2], sz[N * 2];
stack<int> s;
int find(int x) { return x == p[x] ? x : find(p[x]); }
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (sz[x] > sz[y]) swap(x, y);
  p[x] = y;
  sz[y] += sz[x];
  s.push(x);
}
void cancel() {
  int x = s.top(), y = p[x];
  s.pop();
  p[x] = x;
  sz[y] -= sz[x];
}
int a[N];
struct Node {
  int x, y;
} c[N], d[N];
bool cmp(Node p1, Node p2) {
  if (a[p1.x] == a[p2.x]) return a[p1.y] < a[p2.y];
  return a[p1.x] < a[p2.x];
}
bool flag[N];
int main() {
  int n, m, K;
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    p[i] = i, p[n + i] = n + i;
    sz[i] = sz[n + i] = 1;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (a[u] == a[v]) {
      if (find(u) == find(v)) flag[a[u]] = 1;
      merge(u, v + n);
      merge(u + n, v);
    }
    c[i] = {u, v};
  }
  int tot = 0;
  for (int i = 0; i < m; i++) {
    int x = c[i].x, y = c[i].y;
    if (a[x] == a[y] || flag[a[x]] || flag[a[y]]) continue;
    if (a[x] > a[y]) swap(x, y);
    d[tot++] = {x, y};
  }
  sort(d, d + tot, cmp);
  int cnt = K;
  for (int i = 1; i <= K; i++) {
    cnt -= flag[i];
  }
  long long ans = (long long)cnt * (cnt - 1) / 2;
  int cx = -1, cy, t = s.size(), ok = 1;
  for (int i = 0; i < tot; i++) {
    int x = d[i].x, y = d[i].y;
    if (a[x] != cx || a[y] != cy) {
      while (s.size() > t) cancel();
      t = s.size(), cx = a[x], cy = a[y], ok = 1;
    }
    if (ok == 0) continue;
    if (find(x) == find(y)) {
      ans--;
      ok = 0;
    } else {
      merge(x, y + n);
      merge(x + n, y);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
