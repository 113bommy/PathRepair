#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct E {
  int nxt, to;
} e[N << 1];
int head[N], tot;
void add(int x, int y) {
  e[++tot].nxt = head[x];
  head[x] = tot;
  e[tot].to = y;
  e[++tot].nxt = head[y];
  head[y] = tot;
  e[tot].to = x;
}
int ind[N], outd[N], h[N], t[N];
long long f[N], g[N], stk[N];
bool vis[N];
bool cmp(const long long &a, const long long &b) { return a > b; }
void dfs(int x, int fa) {
  vis[x] = true;
  for (int i = head[x]; i; i = e[i].nxt)
    if (e[i].to != fa) dfs(e[i].to, x);
  int top = 0;
  long long nowans = 0;
  for (int i = head[x]; i; i = e[i].nxt)
    if (e[i].to != fa) {
      int y = e[i].to;
      nowans += g[y];
      stk[++top] = f[y] - g[y];
    }
  sort(stk + 1, stk + top + 1, cmp);
  for (int i = 0; i <= top; i++) {
    nowans += stk[i];
    if (fa != 0) {
      f[x] = max(f[x],
                 1ll * min(ind[x] + 1 + top - i, outd[x] + i) * t[x] + nowans);
      g[x] = max(g[x],
                 1ll * min(ind[x] + top - i, outd[x] + 1 - i) * t[x] + nowans);
    } else
      f[x] =
          max(f[x], 1ll * min(ind[x] + top - i, outd[x] + i) * t[x] + nowans);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
  int x, y;
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    if (h[x] == h[y])
      add(x, y);
    else {
      if (h[x] > h[y])
        outd[x]++, ind[y]++;
      else
        outd[y]++, ind[x]++;
    }
    ans += t[x] + t[y];
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      dfs(i, 0);
      ans -= f[i];
    }
  printf("%lld\n", ans);
  return 0;
}
