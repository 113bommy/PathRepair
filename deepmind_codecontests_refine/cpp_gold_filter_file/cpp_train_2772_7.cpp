#include <bits/stdc++.h>
using namespace std;
const long long N = 1000010;
const long long INF = 0x3f3f3f3f;
const long long iinf = 1 << 30;
const long long linf = 2e18;
const long long MOD = 1000000007;
const double eps = 1e-7;
void print(long long x) {
  cout << x << endl;
  exit(0);
}
void PRINT(string x) {
  cout << x << endl;
  exit(0);
}
void douout(double x) { printf("%lf\n", x + 0.0000000001); }
long long low[N], dfn[N], vis[N], bl[N], st[N], dp[N], F[N], val[N];
long long tot, top, scc, n, m, s;
vector<pair<long long, long long> > g[N], e[N];
void tarjan(long long now) {
  low[now] = dfn[now] = ++tot;
  vis[now] = 1;
  st[++top] = now;
  for (long long i = (0); i <= (((long long)e[now].size()) - 1); i++) {
    long long to = e[now][i].first;
    if (!dfn[to]) {
      tarjan(to);
      low[now] = min(low[now], low[to]);
    } else if (vis[to])
      low[now] = min(low[now], dfn[to]);
  }
  if (low[now] == dfn[now]) {
    scc++;
    long long x;
    do {
      x = st[top--];
      vis[x] = 0;
      bl[x] = scc;
    } while (x != now);
  }
}
long long calc(long long c) {
  long long l = 0, r = c;
  while (l < r) {
    long long m = (l + r + 1) >> 1;
    if (m * (m + 1) / 2 <= c)
      l = m;
    else
      r = m - 1;
  }
  return c * (l + 1) - F[l];
}
long long dfs(long long now) {
  if (dp[now] != -1) return dp[now];
  long long res = val[now], tmp = 0;
  for (long long i = (0); i <= (((long long)g[now].size()) - 1); i++) {
    pair<long long, long long> to = g[now][i];
    tmp = max(tmp, to.second + dfs(to.first));
  }
  return dp[now] = res + tmp;
}
signed main() {
  for (long long i = 1, now = 0; i <= 50000; i++) {
    now += i;
    F[i] = F[i - 1] + now;
  }
  scanf("%lld%lld", &n, &m);
  for (long long i = (1); i <= (m); i++) {
    long long x, y, w;
    scanf("%lld%lld%lld", &x, &y, &w);
    e[x].push_back(make_pair(y, w));
  }
  scanf("%lld", &s);
  for (long long i = (1); i <= (n); i++)
    if (!dfn[i]) tarjan(i);
  for (long long i = (1); i <= (n); i++) {
    for (long long id = (0); id <= (((long long)e[i].size()) - 1); id++) {
      long long j = e[i][id].first, c = e[i][id].second;
      if (bl[i] == bl[j])
        val[bl[i]] += calc(c);
      else
        g[bl[i]].push_back(make_pair(bl[j], c));
    }
  }
  for (long long i = (1); i <= (scc); i++) dp[i] = -1;
  printf("%lld\n", dfs(bl[s]));
  return 0;
}
