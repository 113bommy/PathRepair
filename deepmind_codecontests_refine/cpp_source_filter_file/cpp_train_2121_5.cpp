#include <bits/stdc++.h>
using namespace std;
int n, size[200000 + 5], dep[200000 + 5], pre[200000 + 5], le[200000 + 5],
    ri[200000 + 5], son[200000 + 5][4], e[200000 + 5], a[4];
long long dp[200000 + 5];
void dfs(int u, int fa) {
  size[u] = 1;
  for (int i = 0; i < e[u]; i++) {
    int v = son[u][i];
    if (v == fa) continue;
    dfs(v, u), size[u] += size[v], pre[u] = pre[v], dep[u] = dep[v] + 1;
    if (!le[u])
      le[u] = v;
    else
      ri[u] = v;
  }
  if (ri[u]) pre[u] = u, dep[u] = 0;
}
long long cal(int, int);
long long getAns(int u) {
  if (!u) return 1;
  if (size[u] & 1) return 0;
  if (!pre[u]) return size[u] >> 1;
  if (dp[u] != -1) return dp[u];
  int p = pre[u], l = le[p], r = ri[p];
  long long sum = 0;
  dp[u] = 0;
  for (int i = 0; i < 2; i++, swap(l, r)) {
    if (!ri[r]) {
      if (!(dep[u] & 1) && size[r] > 1) sum += cal(l, le[r]);
      if (!pre[r] && dep[r] <= dep[u] && !(dep[r] + dep[u] & 1))
        sum += getAns(l) * (dep[u] - dep[r] >= 2 ? 2 : 1);
      sum %= 1000000007;
    } else {
      if (!pre[le[r]] && dep[le[r]] < dep[u] && (dep[u] + dep[le[r]] & 1))
        sum += cal(l, ri[r]);
      if (!pre[ri[r]] && dep[ri[r]] < dep[u] && (dep[u] + dep[ri[r]]) & 1)
        sum += cal(l, le[r]);
      sum %= 1000000007;
    }
  }
  return dp[u] = sum % 1000000007;
}
long long cal(int u, int v) {
  if (!u || !v) return getAns(u + v);
  if (ri[u] || ri[v]) return 0;
  if (le[u] && le[v]) return cal(le[u], le[v]);
  return getAns(le[u] + le[v]);
}
int main() {
  scanf("%d", &n);
  n <<= 1;
  int rt = 0;
  bool flag = 0;
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (e[u] == 3 || e[v] == 3) {
      flag = 1;
      break;
    }
    son[u][e[u]++] = v, son[v][e[v]++] = u;
    if (e[u] == 3) rt = u;
    if (e[v] == 3) rt = v;
  }
  if (flag) {
    puts("0");
    return 0;
  }
  if (!rt) {
    printf("%lld\n", n == 2 ? 2 : (n * (n / 2 - 1) + 4ll) % 1000000007);
    return 0;
  }
  long long ans = 0;
  dfs(rt, 0);
  a[0] = 0, a[1] = 1, a[2] = 2;
  memset(dp, -1, sizeof(dp));
  do {
    int l = son[rt][a[0]], m = son[rt][a[1]], r = son[rt][a[2]], u = le[m],
        v = ri[m];
    ans += cal(l, u) * cal(r, v) % 1000000007, ans %= 1000000007;
    if (u || v) ans += cal(l, v) * cal(r, u) % 1000000007, ans %= 1000000007;
  } while (next_permutation(a, a + 3));
  printf("%lld\n", ans * 2 % 1000000007);
  return 0;
}
