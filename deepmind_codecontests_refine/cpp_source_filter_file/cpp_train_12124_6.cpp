#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int MAXA = 2000005;
const int MAXN = 100005;
int num[MAXA][25], cnt[MAXA];
int prime[MAXA];
int n, a[MAXN], q, t[MAXN], x[MAXN], y[MAXN];
vector<int> g[MAXN];
int pos[MAXN];
int mem[MAXN][25];
int val[MAXN];
int depth[MAXN];
void dfs(int u, int par, int d) {
  depth[u] = d;
  val[u] = -1;
  for (int i = 0; i < cnt[a[u]]; i++) {
    int p = num[a[u]][i];
    if (val[u] == -1 || depth[pos[p]] > depth[val[u]]) {
      val[u] = pos[p];
    }
    mem[u][i] = pos[p];
    pos[p] = u;
  }
  for (size_t i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v != par) {
      dfs(v, u, d + 1);
    }
  }
  for (int i = 0; i < cnt[a[u]]; i++) {
    int p = num[a[u]][i];
    pos[p] = mem[u][i];
  }
}
void go() {
  memset(pos, -1, sizeof(pos));
  dfs(1, 0, 0);
}
void solve() {
  go();
  for (int i = 0; i < q; i++) {
    if (t[i] == 1) {
      printf("%d\n", val[x[i]]);
    } else {
      a[x[i]] = y[i];
      go();
    }
  }
}
int main() {
  for (int i = 2; i < MAXA; i++) {
    prime[i] = true;
  }
  for (int i = 2; i < MAXA; i++) {
    if (prime[i]) {
      for (int j = i; j < MAXA; j += i) {
        prime[j] = false;
        num[j][cnt[j]++] = i;
      }
    }
  }
  while (scanf("%d %d", &n, &q) == 2) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
    }
    for (int i = 1; i <= n; i++) {
      g[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    for (int i = 0; i < q; i++) {
      scanf("%d %d", t + i, x + i);
      if (t[i] == 2) {
        scanf("%d", y + i);
      }
    }
    solve();
  }
}
