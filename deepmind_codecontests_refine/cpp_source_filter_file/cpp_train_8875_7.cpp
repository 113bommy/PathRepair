#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const int inf = 0x3f3f3f3f;
const int maxNodes = 5e3 + 10;
int n, x, dp[maxn][maxNodes];
char str[maxn], s[maxn];
struct AhoCorasick {
  int sz;
  int ch[maxNodes][10], val[maxNodes], f[maxNodes];
  void init() {
    sz = 1;
    memset(ch[0], 0, sizeof(ch[0]));
  }
  void insert(char *s) {
    int u = 0;
    int len = strlen(s);
    for (int i = 0, c; i < len; ++i) {
      c = s[i] - '0';
      if (!ch[u][c]) {
        memset(ch[sz], 0, sizeof(ch[sz]));
        val[sz] = 0;
        ch[u][c] = sz++;
      }
      u = ch[u][c];
    }
    val[u] = 1;
  }
  void getFail() {
    queue<int> q;
    f[0] = 0;
    for (int c = 0; c < 4; ++c) {
      int u = ch[0][c];
      if (u) {
        f[u] = 0;
        q.push(u);
      }
    }
    while (!q.empty()) {
      int r = q.front();
      q.pop();
      val[r] |= val[f[r]];
      for (int c = 0; c < 4; ++c) {
        int u = ch[r][c];
        if (!u) {
          ch[r][c] = ch[f[r]][c];
          continue;
        }
        q.push(u);
        int v = f[r];
        while (v && !ch[v][c]) v = f[v];
        f[u] = ch[v][c];
      }
    }
  }
} ac;
void upd(int &v, int x) {
  if (v > x) v = x;
}
int check(int len) {
  for (int i = 0; i < len; ++i) {
    int sd = 0;
    for (int j = i; j < len; ++j) {
      sd += s[j] - '0';
      if (x % sd == 0 && x != sd) return 0;
    }
  }
  return 1;
}
void dfs(int p, int sum) {
  if (sum > x) return;
  if (sum == x) {
    s[p] = 0;
    if (check(p)) ac.insert(s);
    return;
  }
  for (int i = 1; i <= 9; ++i) {
    s[p] = '0' + i;
    dfs(p + 1, sum + i);
  }
}
int main() {
  ac.init();
  scanf("%s%d", str, &x);
  n = strlen(str);
  dfs(0, 0);
  ac.getFail();
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < ac.sz; ++j)
      if (dp[i][j] < inf) {
        upd(dp[i + 1][j], dp[i][j] + 1);
        if (!ac.val[ac.ch[j][str[i] - '0']])
          upd(dp[i + 1][ac.ch[j][str[i] - '0']], dp[i][j]);
      }
  int ans = inf;
  for (int i = 0; i < ac.sz; ++i) ans = min(ans, dp[n][i]);
  printf("%d\n", ans);
  return 0;
}
