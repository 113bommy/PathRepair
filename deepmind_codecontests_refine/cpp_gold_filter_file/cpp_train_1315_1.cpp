#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
vector<vector<int>> g;
int in[N], out[N], mx[N], mn[N], t[N], cc;
long long cs[N];
void dfs(int u, int p) {
  in[u] = out[u] = cc++;
  for (auto i : g[u]) {
    if (!(in[i] + 1)) {
      dfs(i, u);
      out[u] = min(out[u], out[i]);
    } else if (i != p)
      out[u] = min(out[u], in[i]);
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  g.resize(n + 1);
  memset(in, -1, sizeof in);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  fill(t, t + N, n);
  fill(mn, mn + N, 1e9);
  for (int i = 1; i <= n; i++)
    if (!(in[i] + 1)) dfs(i, -1);
  for (int i = 1; i <= n; i++)
    mx[out[i]] = max(mx[out[i]], i), mn[out[i]] = min(mn[out[i]], i);
  for (int i = 1; i <= n; i++)
    if (mn[out[i]] == i && mx[out[i]] != i) t[i] = mx[out[i]] - 1;
  for (int i = n; i; i--) {
    t[i] = min(t[i], t[i + 1]);
    cs[i] = t[i] - i + 1;
  }
  for (int i = 1; i <= n; i++) cs[i] += cs[i - 1];
  scanf("%d", &n);
  while (n--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int L = l, R = r;
    while (L <= R) {
      int mid = (L + R) / 2;
      if (t[mid] > r)
        R = mid - 1;
      else
        L = mid + 1;
    }
    L--;
    printf("%lld\n", cs[L] - cs[l - 1] + (r - L) * (r - L + 1LL) / 2);
  }
}
