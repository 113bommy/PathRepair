#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int tot, head[maxn];
int n;
int dfn[maxn], DFN;
int loop[2 * maxn];
int vis[maxn];
int nxt[maxn];
int fa[maxn];
int cnt;
multiset<pair<long long, int>, greater<pair<long long, int> > > s1, s2;
struct Edge {
  int to, w, nxt;
} edge[2 * maxn];
void addedge(int u, int v, int w) {
  tot++;
  edge[tot].to = v;
  edge[tot].w = w;
  edge[tot].nxt = head[u];
  head[u] = tot;
}
void getloop(int u) {
  dfn[u] = ++DFN;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa[u]) continue;
    if (dfn[v]) {
      if (dfn[v] < dfn[u]) continue;
      loop[++cnt] = v, vis[v] = 1, nxt[u] = edge[i].w;
      for (; v != u; v = fa[v]) loop[++cnt] = fa[v], vis[fa[v]] = 1;
    } else
      fa[v] = u, nxt[v] = edge[i].w, getloop(v);
  }
}
long long ans;
long long dp[maxn];
long long sum[maxn];
void dfs(int u, int Fa) {
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == Fa || vis[v]) continue;
    dfs(v, u);
    ans = max(ans, dp[u] + dp[v] + edge[i].w);
    dp[u] = max(dp[u], dp[v] + edge[i].w);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    addedge(u, v, w);
    addedge(v, u, w);
  }
  getloop(1);
  for (int j = 1; j <= cnt; j++) {
    loop[j + cnt] = loop[j];
    dfs(loop[j], 0);
  }
  long long minn = 1e18;
  for (int i = 1; i <= 2 * cnt; i++) {
    sum[i] = sum[i - 1] + nxt[loop[i]];
    s1.insert(make_pair(dp[loop[i]] + sum[i - 1], i));
    s2.insert(make_pair(dp[loop[i]] - sum[i - 1], i));
    if (i >= cnt) {
      if (s1.begin()->second == s2.begin()->second) {
        multiset<pair<long long, int>,
                 greater<pair<long long, int> > >::iterator it1,
            it2;
        it1 = s1.begin();
        it1++;
        it2 = s2.begin();
        it2++;
        minn = min(minn, max(s1.begin()->first + it2->first,
                             s2.begin()->first + it1->first));
      } else {
        minn = min(minn, s1.begin()->first + s2.begin()->first);
      }
      s1.erase(make_pair(dp[loop[i - cnt + 1]] + sum[i - cnt], i - cnt + 1));
      s2.erase(make_pair(dp[loop[i - cnt + 1]] - sum[i - cnt], i - cnt + 1));
    }
  }
  cout << max(ans, minn) << endl;
  return 0;
}
