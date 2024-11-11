#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
int n;
vector<int> G[15005];
int dp[2][15005 << 1], isrt[15005], rts[15005 << 1], s[15005 << 1], tot,
    siz[15005], w[15005], ans;
void find_cir(int u, int fa) {
  static int st[15005], top, ins[15005];
  st[++top] = u;
  ins[u] = 1;
  for (auto v : G[u]) {
    if (v == fa || tot) continue;
    if (ins[v]) {
      int t = 0;
      while (t ^ v) {
        t = st[top--];
        rts[++tot] = t;
        isrt[t] = 1;
      }
      break;
    } else
      find_cir(v, u);
  }
  --top;
}
void dfs(int u, int fa) {
  siz[u] = 1;
  for (auto v : G[u]) {
    if (isrt[v] || v == fa) continue;
    dfs(v, u);
    siz[u] += siz[v];
    w[u] += w[v];
  }
  w[u] += siz[u];
}
int calc(int u, int fa) {
  int mx = n + w[u] - siz[u];
  for (auto v : G[u]) {
    if (isrt[v] || v == fa) continue;
    mx = max(mx, calc(v, u) + n - siz[v] + w[u] - siz[u] - w[v]);
  }
  return mx;
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    int u = read() + 1, v = read() + 1;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  find_cir(1, 0);
  for (int i = 1; i <= tot; ++i) {
    dfs(rts[i], 0);
  }
  for (int i = 1; i <= tot; ++i) rts[i + tot] = rts[i];
  for (int i = 1; i <= (tot << 1); ++i) s[i] = s[i - 1] + siz[rts[i]];
  for (int len = 1; len < tot; ++len) {
    memset(dp[len & 1], 0, sizeof(dp[len & 1]));
    for (int l = 1; l + len - 1 <= (tot << 1); ++l) {
      int r = l + len - 1;
      dp[len & 1][l] = max(dp[(len - 1) & 1][l] + w[rts[r]] - siz[rts[r]],
                           dp[(len - 1) & 1][l + 1] + w[rts[l]] - siz[rts[l]]) +
                       s[r] - s[l - 1];
    }
  }
  for (int i = 1; i <= tot; ++i) {
    ans = max(ans, calc(rts[i], 0) + dp[(tot - 1) & 1][i + 1]);
  }
  printf("%d\n", ans);
  return 0;
}
