#include <bits/stdc++.h>
const int MAXN = 3000 + 5;
int x;
int p[MAXN];
inline bool chk(int n) {
  for (int l = 1; l <= n; ++l) {
    int sm = 0;
    for (int r = l; r <= n; ++r) {
      if (l == 1 && r == n) continue;
      sm += p[r];
      if (x % sm == 0) return 0;
    }
  }
  return 1;
}
int ch[MAXN * 20][9], tot = 1, rt = 1;
int ban[MAXN * 20];
inline void insert(int len) {
  int v = rt;
  for (int i = 1; i <= len; ++i) {
    if (!ch[v][p[i] - 1]) ch[v][p[i] - 1] = ++tot;
    v = ch[v][p[i] - 1];
  }
  ban[v] = 1;
}
int fail[MAXN * 20];
inline void build() {
  std::queue<int> q;
  for (int i = 0; i <= 8; ++i) {
    if (ch[rt][i])
      fail[ch[rt][i]] = rt, q.push(ch[rt][i]);
    else
      ch[rt][i] = rt;
  }
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 0; i <= 8; ++i) {
      if (ch[v][i])
        fail[ch[v][i]] = ch[fail[v]][i], q.push(ch[v][i]);
      else
        ch[v][i] = ch[fail[v]][i];
    }
  }
}
inline void dfs(int step, int now) {
  if (now == 0) {
    if (chk(step - 1)) {
      insert(step - 1);
    }
    return;
  }
  for (int i = 1; i <= std::min(now, 9); ++i)
    p[step] = i, dfs(step + 1, now - i);
}
char str[MAXN];
int n;
int f[2][MAXN * 20];
int main() {
  scanf("%s", str + 1);
  n = strlen(str + 1);
  scanf("%d", &x);
  dfs(1, x);
  build();
  int now = 0;
  memset(f, -0x3f, sizeof(f));
  f[now][rt] = 0;
  for (int i = 1; i <= n; ++i) {
    memset(f[now ^ 1], -0x3f, sizeof(f[now ^ 1]));
    for (int v = 1; v <= tot; ++v) {
      if (f[now][v] < 0) continue;
      if (ban[v]) continue;
      f[now ^ 1][v] = std::max(f[now ^ 1][v], f[now][v]);
      f[now ^ 1][ch[v][str[i] - '1']] =
          std::max(f[now ^ 1][ch[v][str[i] - '1']], f[now][v] + 1);
    }
    now ^= 1;
  }
  int ans = 0;
  for (int i = 1; i <= tot; ++i)
    if (!ban[i]) ans = std::max(ans, f[now][i]);
  printf("%d\n", n - ans);
  return 0;
}
