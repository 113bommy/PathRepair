#include <bits/stdc++.h>
using namespace std;
int n, l, p[100010], nl[100010], vp[100010], depth[100010];
int out[100010];
bool visited[100010];
long long w[100010], ns[100010], s, wsum[100010];
int lift[100010][20], h[100010];
vector<int> children[100010];
void dfs(int u, long long p, int d) {
  wsum[u] = p;
  depth[u] = d;
  int child_count = children[u].size(), v;
  for (int i = 0; i < child_count; i++) {
    v = children[u][i];
    dfs(v, p + w[u], d + 1);
  }
}
int find_height(int u, long long s, int p) {
  int sh = 0, eh = min(depth[u], l - nl[u]), mh;
  int v;
  while (sh < eh) {
    mh = (sh + eh + 1) / 2;
    v = u;
    for (int i = 20 - 1; i >= 0; i--) {
      if ((mh >> i) & 1) {
        v = lift[v][i];
      }
    }
    if (wsum[u] - wsum[v] <= s) {
      sh = mh;
    } else {
      eh = mh - 1;
    }
  }
  return sh;
}
void topo(int u) {
  visited[u] = true;
  out[p[u]]--;
  int child_count = children[u].size(), v, mh = 0, bv = 0, vpsum = 0;
  for (int i = 0; i < child_count; i++) {
    v = children[u][i];
    if (h[v] > mh) {
      mh = h[v];
      bv = v;
    }
    vpsum += vp[v];
  }
  if (mh > 0) {
    vp[u] = vpsum;
    ns[u] = w[u] + ns[bv];
    ns[u] = nl[bv] + 1;
  } else {
    vp[u] = vpsum + 1;
    ns[u] = w[u];
    nl[u] = 1;
  }
  if (u == 1) {
    return;
  } else {
    h[u] = find_height(u, s - ns[u], p[u]);
  }
  if (out[p[u]] == 0) {
    topo(p[u]);
  }
}
int main() {
  scanf("%d %d %lld", &n, &l, &s);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &w[i]);
    out[i] = 0;
  }
  for (int i = 2; i <= n; i++) {
    scanf("%d", &p[i]);
    out[p[i]]++;
    children[p[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (w[i] > s) {
      printf("-1\n");
      return 0;
    }
  }
  for (int i = 0; i < 20; i++) {
    lift[1][i] = 0;
    lift[0][i] = 0;
  }
  for (int i = 2; i <= n; i++) {
    lift[i][0] = p[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < 20; j++) {
      lift[i][j] = lift[lift[i][j - 1]][j - 1];
    }
  }
  dfs(1, 0, 0);
  for (int i = n; i >= 1; i--) {
    if (!visited[i]) {
      topo(i);
    }
  }
  printf("%d\n", vp[1]);
  return 0;
}
