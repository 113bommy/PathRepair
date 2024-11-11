#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = N;
int n, m, ans;
struct E {
  int u, v, w;
} ed[M];
int dp[N];
vector<int> vs[N], fwk[N];
void inc(int idx, int i, int v) {
  int ni = fwk[idx].size() - 1;
  for (; i <= ni; i += i & (-i)) fwk[idx][i] = max(v, fwk[idx][i]);
}
int get(int idx, int i) {
  int m = 0;
  for (; i; i -= i & (-i)) {
    m = max(m, fwk[idx][i]);
  }
  return m;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &ed[i].u, &ed[i].v, &ed[i].w);
    vs[ed[i].u].push_back(ed[i].w);
  }
  for (int i = 1; i <= n; i++) {
    sort(vs[i].begin(), vs[i].end());
    fwk[i] = vector<int>(vs[i].size() + 1);
  }
  for (int i = 0; i < m; i++) {
    int u = ed[i].u, v = ed[i].v, w = ed[i].w,
        idx = lower_bound(vs[u].begin(), vs[u].end(), w) - vs[u].begin() + 1;
    dp[i] = get(u, idx) + 1;
    idx = upper_bound(vs[v].begin(), vs[v].end(), w) - vs[v].begin() + 1;
    inc(v, idx, dp[i]);
  }
  for (int i = 0; i < m; i++) ans = max(ans, dp[i]);
  printf("%d\n", ans);
}
