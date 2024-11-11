#include <bits/stdc++.h>
using namespace std;
int n, L, p;
long long S;
vector<int> g[100005];
int w[100005];
int ans = 0;
int d = 0;
int dp1[100005];
long long dp2[100005];
long long ft[100005];
void update(int i, long long v) {
  for (; i <= 100000; i += (i & -i)) {
    ft[i] += v;
  }
}
long long query(int i) {
  long long res = 0;
  for (; i > 0; i -= (i & -i)) res += ft[i];
  return res;
}
void dfs(int u) {
  d++;
  update(d, w[u]);
  int cur = 0, idx = -1;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    dfs(v);
    int g1 = L - dp1[v], g2 = 0;
    int lo = 1, hi = d;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (query(d) - query(d - mid) + dp2[v] <= S)
        g2 = mid, lo = mid + 1;
      else
        hi = mid - 1;
    }
    int g = min(g1, g2);
    if (cur < g) {
      cur = g;
      idx = v;
    }
  }
  update(d, -w[u]);
  d--;
  if (cur == 0) {
    ans++;
    dp1[u] = 1;
    dp2[u] = w[u];
  } else {
    dp1[u] = dp1[idx] + 1;
    dp2[u] = dp2[idx] + w[u];
  }
}
int main() {
  scanf("%d%d%lld", &n, &L, &S);
  bool ok = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
    if (w[i] > S) ok = 0;
  }
  for (int i = 2; i <= n; i++) scanf("%d", &p), g[p].emplace_back(i);
  if (!ok) return !printf("-1\n");
  dfs(1);
  printf("%d\n", ans);
}
