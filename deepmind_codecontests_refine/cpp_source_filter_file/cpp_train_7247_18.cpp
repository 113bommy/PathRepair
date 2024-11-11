#include <bits/stdc++.h>
struct node {
  int link[4], go[4], suff, par, ch, maxlen;
  node() {
    memset(link, -1, sizeof link);
    memset(go, -1, sizeof go);
    suff = -1;
    maxlen = 0;
  }
} tr[120];
int m, dp[120][1010][11], u[120];
void add(int& x, int y) {
  long long sum = (x * 1LL + y * 1LL) % 1000000009;
  x = sum;
}
int alp(char c) { return c == 'A' ? 0 : c == 'C' ? 1 : c == 'G' ? 2 : 3; }
void add_string(char* s, int l) {
  int v = 0;
  for (int i = 0; i < l; i++) {
    int& to = tr[v].link[alp(s[i])];
    if (to == -1) to = ++m, tr[m].par = v, tr[m].ch = alp(s[i]);
    v = to;
  }
  if (tr[v].maxlen < l) tr[v].maxlen = l;
}
int go(int v, int c);
int suffix_link(int v) {
  if (tr[v].suff + 1) return tr[v].suff;
  if (!v || !tr[v].par) return tr[v].suff = 0;
  return tr[v].suff = go(suffix_link(tr[v].par), tr[v].ch);
}
int go(int v, int c) {
  int& x = tr[v].go[c];
  if (x + 1) return x;
  if (tr[v].link[c] != -1) return x = tr[v].link[c];
  return x = v ? go(suffix_link(v), c) : 0;
}
int getlen(int v) {
  if (!v) return 0;
  return tr[v].maxlen > 0 ? tr[v].maxlen : getlen(suffix_link(v));
}
int main() {
  tr[0].suff = 0;
  dp[0][0][0] = 1;
  int n, m;
  char s[20];
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%s", s);
    add_string(s, strlen(s));
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= ::m; j++)
      for (int last = 0; last <= (i < 10 ? i : 10); last++)
        if (dp[j][i][last])
          for (int c = 0; c < 4; c++) {
            int to = go(j, c);
            int s = last + 1;
            if (getlen(to) >= s) s = 0;
            add(dp[to][i + 1][s], dp[j][i][last]);
          }
  int ans = 0;
  for (int i = 0; i <= ::m; i++) add(ans, dp[i][n][0]);
  printf("%d\n", ans);
  return 0;
}
