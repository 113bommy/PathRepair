#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, cnt[maxn][2], sz[maxn], d[maxn];
vector<int> to[maxn];
long long ans;
void dfs1(int u, int f) {
  sz[u] = 1;
  d[u] = d[f] + 1;
  for (int v : to[u]) {
    if (v == f) continue;
    dfs1(v, u);
    sz[u] += sz[v];
  }
}
void dfs2(int u, int f, int res) {
  if (u != 1) {
    cnt[u][0] = cnt[f][1];
    cnt[u][1] = cnt[f][0];
  }
  ans += (res + cnt[u][1]) / 2;
  for (int v : to[u]) {
    if (v == f) continue;
    int x = n - sz[v], y = sz[v];
    dfs2(v, u, res - y + x);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d", &u);
    scanf("%d", &v);
    to[u].push_back(v);
    to[v].push_back(u);
  }
  d[0] = -1;
  dfs1(1, 0);
  ans = 0;
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    cnt[1][d[i] % 2]++;
    res += d[i];
  }
  dfs2(1, 0, res);
  cout << ans / 2 << endl;
  return 0;
}
