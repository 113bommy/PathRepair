#include <bits/stdc++.h>
using namespace std;
char L[1010], R[1010];
int ll, lr;
int n;
struct AC_AM {
  int s[20020][11], tot;
  int sum[16006][2020];
  int nxt(int x, char c) {
    c -= '0';
    return s[x][c] ? s[x][c] : s[x][c] = ++tot;
  }
  void build() {
    int u = 0, v = 0;
    if (ll == lr) {
      for (int i = 1; i <= ll; ++i) {
        if (u == v)
          for (char c = L[i] + 1; c < R[i]; ++c) sum[nxt(u, c)][ll - i]++;
        else {
          for (char c = L[i] + 1; c <= '9'; ++c) sum[nxt(u, c)][ll - i]++;
          for (char c = '0' + (i == 1); c < R[i]; ++c) sum[nxt(u, c)][ll - i]++;
        }
        u = nxt(u, L[i]), v = nxt(v, R[i]);
      }
      sum[u][0]++;
      if (u != v) sum[v][0]++;
      return;
    } else {
      for (int i = 1; i <= ll; ++i) {
        for (char c = L[i] + 1; c <= '9'; ++c) sum[nxt(u, c)][ll - i]++;
        u = nxt(u, L[i]);
      }
      sum[u][0]++;
      v = 0;
      for (int i = 1; i <= lr; ++i) {
        for (char c = '0' + (i == 1); c < R[i]; ++c) sum[nxt(v, c)][lr - i]++;
        v = nxt(v, R[i]);
      }
      sum[v][0]++;
      for (int i = ll + 1; i < lr; ++i)
        for (char c = '1'; c <= '9'; ++c) sum[nxt(0, c)][i - 1]++;
    }
  }
  int fa[16006];
  void getfail() {
    queue<int> q;
    for (int i = 0; i <= 9; ++i)
      if (s[0][i]) q.push(s[0][i]);
    int u, v;
    while (!q.empty()) {
      u = q.front();
      q.pop();
      for (int l = 0; l <= lr; ++l) sum[u][l] += sum[fa[u]][l];
      for (int c = 0; c <= 9; ++c)
        if (s[u][c]) {
          v = s[u][c];
          fa[v] = s[fa[u]][c];
          q.push(v);
        } else
          s[u][c] = s[fa[u]][c];
    }
    for (int i = 0; i <= tot; ++i)
      for (int j = 1; j <= n; ++j) sum[i][j] += sum[i][j - 1];
  }
  int f[2020][16006];
  bool on[2020][16006];
  void solve() {
    memset(f, -1, sizeof(f));
    f[0][0] = 0;
    int v;
    for (int i = 0; i < n; ++i)
      for (int x = 0; x <= tot; ++x)
        if (f[i][x] >= 0)
          for (int c = 0; c <= 9; ++c) {
            v = s[x][c];
            f[i + 1][v] = max(f[i + 1][v], f[i][x] + sum[v][n - i - 1]);
          }
    int ans = 0;
    for (int i = 0; i <= tot; ++i) ans = max(ans, f[n][i]);
    for (int i = 0; i <= tot; ++i)
      if (f[n][i] == ans) on[n][i] = 1;
    for (int i = n - 1; i >= 0; --i)
      for (int x = 0; x <= tot; ++x) {
        if (f[i][x] < 0) continue;
        for (int c = 0; c <= 9; ++c) {
          v = s[x][c];
          if (on[i + 1][v] && f[i][x] + sum[v][n - i - 1] == f[i + 1][v])
            on[i][x] = 1;
        }
      }
    int u = 0;
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i) {
      for (int c = 0; c <= 9; ++c) {
        v = s[u][c];
        if (on[i][s[u][c]] && f[i - 1][u] + sum[v][n - i] == f[i][v]) {
          printf("%d", c);
          u = v;
          break;
        }
      }
    }
    puts("");
  }
} AC;
int main() {
  scanf("%s", L + 1);
  ll = strlen(L + 1);
  scanf("%s", R + 1);
  lr = strlen(R + 1);
  scanf("%d", &n);
  AC.build();
  AC.getfail();
  AC.solve();
  return 0;
}
