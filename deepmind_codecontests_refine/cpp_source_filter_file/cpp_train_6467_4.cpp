#include <bits/stdc++.h>
using namespace std;
long long a[300005], ma, s[300005], ans1, ans;
int tot, n, net[300005], head[300005], a1, a2, to[300005], fa[300005];
long long gets() {
  long long v = 0;
  bool f = 0;
  char ch;
  while (!isdigit(ch)) {
    f |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) {
    v = (v << 3) + (v << 1) + ch - 48;
    ch = getchar();
  }
  return f ? -v : v;
}
void ins(int frm, int to2) {
  to[++tot] = to2, net[tot] = head[frm], head[frm] = tot;
  to[++tot] = frm, net[tot] = head[to2], head[to2] = tot;
}
void dfs(int x, int f) {
  s[x] = a[x];
  for (int t = head[x]; t; t = net[t])
    if (to[t] != fa[x]) {
      fa[to[t]] = x;
      dfs(to[t], f);
      if (s[to[t]] > 0ll) s[x] += s[to[t]];
    }
  if (f)
    ans = max(ans, s[x]);
  else if (ans == s[x])
    s[x] = 0, ans1++;
}
int main() {
  n = gets();
  ma = ans = -1000000007;
  for (int i = 1; i <= n; i++) a[i] = gets(), ma = max(ma, a[i]);
  for (int i = 1; i < n; i++) a1 = gets(), a2 = gets(), ins(a1, a2);
  dfs(1, 1);
  dfs(1, 0);
  printf("%I64d %I64d\n", ans1 * ans, ans1);
  return 0;
}
