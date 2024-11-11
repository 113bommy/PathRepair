#include <bits/stdc++.h>
using namespace std;
long long a[200200], ans;
struct Node {
  long long v, id, t, x;
} node[200200];
int n;
long long x, y, fx;
vector<int> g[200200];
long long dfs(int i) {
  x = i;
  if (x >= 1 && x <= n) {
    x += a[x];
    if (x >= 1 && x <= n) {
      x -= a[x];
    } else
      return 0;
  } else
    return 0;
  return x;
}
long long fuck(int i) {
  long long tmp = 0;
  x = i;
  if (x >= 1 && x <= n) {
    tmp += a[x];
    x += a[x];
    if (x >= 1 && x <= n) {
      tmp += a[x];
      x -= a[x];
    } else
      return tmp;
  } else
    return tmp;
  return tmp;
}
void work(int i, long long tmp) {
  if (node[i].t == -1) {
    node[i].x = fuck(i);
    for (int k = 0; k < g[i].size(); k++) {
      work(g[i][k], node[i].x);
    }
  } else {
    node[i].x += fuck(i) + tmp;
    for (int k = 0; k < g[i].size(); k++) {
      work(g[i][k], node[i].x);
    }
  }
}
long long solve() {
  x = 1;
  y = 0;
  if (x >= 1 && x <= n) {
    y += a[x];
    x += a[x];
    if (x >= 1 && x <= n) {
      y += a[x];
      x -= a[x];
    } else
      return y;
  } else
    return y;
  if (x < 1 || x >= n)
    return y;
  else if (node[x].x == 0)
    return -1;
  else
    return y + node[x].x;
}
int main() {
  while (~scanf("%d", &n)) {
    a[1] = 1;
    for (int i = 1; i <= n; i++) {
      node[i].id = i;
      g[i].clear();
    }
    memset(node, 0, sizeof(node));
    for (int i = 2; i <= n; i++) {
      scanf("%I64d", &a[i]);
    }
    for (int i = 2; i <= n; i++) {
      fx = dfs(i);
      if (fx < 1 || fx > n)
        node[i].t = -1;
      else {
        g[fx].push_back(i);
        node[i].v++;
      }
    }
    for (int i = 2; i <= n; i++) {
      if (node[i].t == -1 && !node[i].v) {
        work(i, 0);
      }
    }
    for (int i = 1; i < n; i++) {
      a[1] = i;
      ans = solve();
      printf("%I64d\n", ans);
    }
  }
  return 0;
}
