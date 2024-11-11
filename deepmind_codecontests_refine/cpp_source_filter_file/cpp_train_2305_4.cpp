#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const long long mod = 998244353;
long long dp[N][2], num[N], cnt[N], mul[N], c[N];
struct node {
  int to, next;
} e[N * 2];
int tot, head[N];
void add(int x, int y) {
  e[tot].to = y;
  e[tot].next = head[x];
  head[x] = tot++;
}
int f = 0;
int son[N], siz;
void dfs(int x, int fa) {
  cnt[x] = c[x] > 0;
  for (int i = head[x]; ~i; i = e[i].next) {
    int ne = e[i].to;
    if (ne == fa) continue;
    dfs(ne, x);
    if (f) return;
    if (c[x] == 0)
      c[x] = c[ne];
    else if (c[ne] && c[x] != c[ne]) {
      f = 1;
      return;
    }
    cnt[x] += cnt[ne];
  }
  mul[0] = 1;
  siz = 0;
  for (int i = head[x]; ~i; i = e[i].next) {
    if (e[i].to == fa) continue;
    son[++siz] = e[i].to;
    mul[siz] = mul[siz - 1] * (dp[e[i].to][0] + dp[e[i].to][1]) % mod;
  }
  if (c[x])
    dp[x][1] = mul[siz];
  else {
    dp[x][0] = mul[siz];
    long long ret = 1;
    for (int i = siz; i; i--) {
      dp[x][1] += dp[son[i]][1] * mul[i - 1] % mod * ret % mod;
      ret = ret * (dp[son[i]][1] + dp[son[i]][0]) % mod;
    }
  }
  if (num[c[x]] == cnt[x]) c[x] = 0;
}
int main() {
  memset(head, -1, sizeof(head));
  int n, k, x, y;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]), num[c[i]]++;
  for (int i = 1; i < n; i++) scanf("%d%d", &x, &y), add(x, y), add(y, x);
  dfs(1, 0);
  printf("%lld\n", f ? 0ll : dp[1][1]);
}
