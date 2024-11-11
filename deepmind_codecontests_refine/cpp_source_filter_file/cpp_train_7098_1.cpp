#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
long long dp[maxn][2];
int head[maxn];
int cnt;
int n, k;
struct edge {
  int to, next, w;
} e[maxn * 2];
void add(int from, int to, int w) {
  ++cnt;
  e[cnt] = {to, head[from], w};
  head[from] = cnt;
}
bool cmp(int a, int b) { return a > b; }
void dfs(int u, int fa) {
  dp[u][1] = dp[u][0] = 0;
  vector<int> t;
  long long s1, s2;
  s1 = s2 = 0;
  for (int i = head[u]; ~i; i = e[i].next) {
    int v = e[i].to;
    int w = e[i].w;
    if (v == fa) continue;
    dfs(v, u);
    if (dp[v][0] + w > dp[v][1]) {
      t.push_back(dp[v][0] + w - dp[v][1]);
    }
    s1 += dp[v][1];
  }
  sort(t.begin(), t.end(), cmp);
  int sz = t.size();
  if (sz < k) {
    for (int i = 0; i < sz; i++) s2 += t[i];
    dp[u][1] = dp[u][0] = s1 + s2;
  } else {
    for (int i = 0; i < k - 1; i++) {
      s2 += t[i];
    }
    dp[u][1] = s1 + s2 + t[k - 1];
    dp[u][0] = s1 + s2;
  }
}
int main(void) {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) head[i] = -1;
    cnt = 0;
    for (int i = 1; i <= n - 1; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      add(u, v, w);
      add(v, u, w);
    }
    dfs(1, 0);
    int ans = max(dp[1][0], dp[1][1]);
    printf("%I64d\n", ans);
  }
}
