#include <bits/stdc++.h>
int CH, NEG;
template <typename TP>
inline void read(TP& ret) {
  ret = NEG = 0;
  while (CH = getchar(), CH < '!')
    ;
  if (CH == '-') NEG = true, CH = getchar();
  while (ret = ret * 10 + CH - '0', CH = getchar(), CH > '!')
    ;
  if (NEG) ret = -ret;
}
int n, ans;
long long cnt;
int dis[100010LL][8], d[8][8], mask[100010LL], c[8][256];
char s[100010LL];
std::queue<int> q;
inline void bfs(int x) {
  int i, u, v;
  dis[(x + n + 1)][x] = 0;
  for (i = (1); i <= (n); i++)
    if (s[i] == x) dis[i][x] = 0, q.push(i);
  while (!q.empty())
    if (u = q.front(), q.pop(), u <= n) {
      if (v = u + 1, 1 <= v && v <= n && dis[v][x] == 0x3f3f3f3fLL) {
        dis[v][x] = dis[u][x] + 1, q.push(v);
        if (dis[(s[v] + n + 1)][x] == 0x3f3f3f3fLL)
          dis[(s[v] + n + 1)][x] = dis[u][x] + 1, q.push((s[v] + n + 1));
      }
      if (v = u - 1, 1 <= v && v <= n && dis[v][x] == 0x3f3f3f3fLL) {
        dis[v][x] = dis[u][x] + 1, q.push(v);
        if (dis[(s[v] + n + 1)][x] == 0x3f3f3f3fLL)
          dis[(s[v] + n + 1)][x] = dis[u][x] + 1, q.push((s[v] + n + 1));
      }
    } else
      for (i = (1); i <= (n); i++)
        if ((s[i] + n + 1) == u && dis[i][x] == 0x3f3f3f3fLL)
          dis[i][x] = dis[u][x] + 1, q.push(i);
}
int main() {
  int i, j, k, l, now, x;
  read(n), scanf("%s", s + 1);
  for (i = (1); i <= (n); i++) s[i] -= 'a';
  memset(dis, 0x3f, sizeof dis);
  while (!q.empty()) q.pop();
  for (i = (0); i < (8); i++) {
    bfs(i);
    for (x = (0); x < (8); x++) d[x][i] = dis[(x + n + 1)][i];
  }
  for (i = (1); i <= (n); i++)
    for (x = (0); x < (8); x++)
      if (dis[i][x] > d[s[i]][x]) mask[i] |= 1 << x;
  for (i = (1); i <= (n); i++) {
    for (j = (std::max(i - 15, 1)); j < (i); j++) {
      now = i - j;
      for (k = (0); k < (8); k++)
        now = std::min(now, dis[j][k] + dis[i][k] + 1);
      if (now == ans) cnt++;
      if (now > ans) ans = now, cnt = 1;
    }
    int t = i - 16;
    if (t >= 1) c[s[t]][mask[t]]++;
    for (x = (0); x < (8); x++)
      for (k = (0); k < (256); k++)
        if (c[x][k]) {
          now = 0x3f3f3f3fLL;
          for (l = (0); l < (8); l++)
            now = std::min(now, d[x][l] + 1 + dis[i][l] + (k & (1 << l)) >> l);
          if (now == ans) cnt += c[x][k];
          if (now > ans) ans = now, cnt = c[x][k];
        }
  }
  printf("%d %lld\n", ans, cnt);
END:
  getchar(), getchar();
  return 0;
}
