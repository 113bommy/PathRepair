#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 15005, inf = 0x3f3f3f3f;
char s[N];
int n, x, cnt;
int ch[M][10], fail[M], ed[M], tot;
int f[N][M];
inline void chkmin(int &x, int y) {
  if (y < x) x = y;
}
inline void ins(string s) {
  int nw = 0;
  for (int i = 0; i < s.size(); i++) {
    int t = s[i] - '0';
    if (!ch[nw][t]) ch[nw][t] = ++tot;
    nw = ch[nw][t];
  }
  ed[nw] = 1;
}
inline void build() {
  queue<int> q;
  for (int i = 1; i <= 9; i++)
    if (ch[0][i]) q.push(ch[0][i]), fail[ch[0][i]] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    ed[u] |= ed[fail[u]];
    for (int i = 1; i <= 9; i++) {
      if (ch[u][i])
        fail[ch[u][i]] = ch[fail[u]][i], q.push(ch[u][i]);
      else
        ch[u][i] = ch[fail[u]][i];
    }
  }
}
inline bool check(string t) {
  for (int l = 0; l < t.size(); l++) {
    int s = 0;
    for (int r = l; r < t.size(); r++) {
      s += t[r] - '0';
      if (s != x && x % s == 0) return 0;
    }
  }
  return 1;
}
void dfs(string s, int sum) {
  if (sum > x) return;
  if (sum == x) {
    if (check(s)) ins(s);
    return;
  }
  for (int i = 1; i <= 9; i++) {
    dfs(s + (char)(i + '0'), sum + i);
  }
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  scanf("%d", &x);
  dfs("", 0);
  build();
  memset(f, 0x3f, sizeof(f));
  f[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= tot; j++) {
      if (f[i][j] == inf) continue;
      chkmin(f[i + 1][j], f[i][j] + 1);
      if (!ed[ch[j][s[i + 1] - '0']])
        chkmin(f[i + 1][ch[j][s[i + 1] - '0']], f[i][j]);
    }
  }
  int ans = inf;
  for (int i = 0; i <= tot; i++) ans = min(ans, f[n][i]);
  printf("%d\n", ans);
  return 0;
}
