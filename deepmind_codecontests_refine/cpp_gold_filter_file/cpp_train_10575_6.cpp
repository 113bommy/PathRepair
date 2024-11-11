#include <bits/stdc++.h>
using namespace std;
int n, Next[600010][26], tot;
int vis[600010], dis[600010], Size[600010], cnt[600010], len;
int dfs1(int st) {
  vis[st] = 1;
  Size[st] = 1;
  for (int i = 0; i < (26); i++) {
    int v = Next[st][i];
    if (vis[v] || v == 0) continue;
    dis[v] = dis[st] + 1;
    Size[st] += dfs1(v);
  }
  cnt[dis[st]] += Size[st];
  return Size[st];
}
int Merge(int x, int y) {
  if (!x || !y) return x + y;
  int rt = ++tot;
  Size[rt] = 1;
  for (int i = 0; i < (26); i++) {
    Next[rt][i] = Merge(Next[x][i], Next[y][i]);
    Size[rt] += Size[Next[rt][i]];
  }
  return rt;
}
void dfs2(int st) {
  int rt = 0;
  for (int i = 0; i < (26); i++) {
    if (Next[st][i]) dfs2(Next[st][i]);
  }
  for (int i = 0; i < (26); i++) rt = Merge(rt, Next[st][i]);
  cnt[dis[st]] -= max(1, Size[rt]);
}
int main() {
  scanf("%d", &n);
  tot = n;
  for (int i = 1; i < (n); i++) {
    int u, v;
    char ch;
    scanf("%d %d %c", &u, &v, &ch);
    Next[u][ch - 'a'] = v;
  }
  dfs1(1);
  for (int i = 1; i < (n + 1); i++) len = max(len, dis[i]);
  dfs2(1);
  int pos = 0;
  for (int i = 1; i < (len + 1); i++)
    if (cnt[i] > cnt[pos]) pos = i;
  printf("%d\n%d\n", n - cnt[pos], pos + 1);
}
