#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> v;
long long x[N], y[N];
int st[N][20], depth[N];
bool cross(int a, int b, int c) {
  return x[a] * (y[b] - y[c]) + x[b] * (y[c] - y[a]) + x[c] * (y[a] - y[b]) < 0;
}
void pre(int n) {
  int i, j;
  for (j = 1; (1 << j) <= n; j++) {
    for (i = 0; i < n; i++) {
      st[i][j] = st[st[i][j - 1]][j - 1];
    }
  }
}
int lca(int x, int y) {
  if (depth[x] < depth[y]) swap(x, y);
  int log, i;
  for (log = 0; (1 << log) <= depth[x]; log++)
    ;
  log--;
  for (i = log; i >= 0; i--) {
    if (depth[x] - (1 << i) >= depth[y]) x = st[x][i];
  }
  if (x == y) return x;
  for (i = log; i >= 0; i--) {
    if (st[x][i] != st[y][i]) {
      x = st[x][i];
      y = st[y][i];
    }
  }
  return st[x][0];
}
int main() {
  int n, i, m;
  scanf("%d", &n);
  memset(st, -1, sizeof(st));
  for (i = 0; i < n; i++) scanf("%lld%lld", x + i, y + i);
  st[n - 1][0] = n - 1;
  v.push_back(n - 1);
  for (i = n - 2; i >= 0; i--) {
    while (v.size() >= 2 && cross(i, v[v.size() - 2], v[v.size() - 1]))
      v.pop_back();
    st[i][0] = v.back();
    depth[i] = 1 + depth[v.back()];
    v.push_back(i);
  }
  pre(n);
  scanf("%d", &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    printf("%d ", lca(a, b) + 1);
  }
}
