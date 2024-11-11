#include <bits/stdc++.h>
using namespace std;
int n, Next[600010][26], tot;
int dis[600010], Size[600010], cnt[600010], len;
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
void dfs(int st, int fa) {
  Size[st] = 1;
  dis[st] = dis[fa] + 1;
  for (int i = 0; i < (26); i++) {
    if (Next[st][i]) {
      dfs(Next[st][i], st);
      Size[st] += Size[Next[st][i]];
    }
  }
  cnt[dis[st]] += Size[st];
  int rt = 0;
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
  dfs(1, 0);
  for (int i = 1; i < (n + 1); i++) len = max(len, dis[i]);
  int pos = 1;
  for (int i = 2; i < (len + 1); i++)
    if (cnt[i] > cnt[pos]) pos = i;
  printf("%d\n%d\n", n - cnt[pos], pos);
}
