#include <bits/stdc++.h>
using namespace std;
int head[300010], nxt[600010], point[600010], sum, weight[300010], num[300010],
    cnt;
int n, m, s, nowedge[300010];
int a, b, t;
void add(int x, int y, int t) {
  ++sum;
  nxt[sum] = head[x];
  head[x] = sum;
  point[sum] = y;
  weight[sum] = 1;
  if (t != 1) {
    ++cnt;
    num[sum] = cnt;
    ++sum;
    nxt[sum] = head[y];
    head[y] = sum;
    point[sum] = x;
    weight[sum] = -1;
    num[sum] = cnt;
  }
}
int exist[300010], ans;
void dfs1(int x) {
  if (exist[x]) return;
  ans++;
  exist[x] = 1;
  for (int tmp = head[x]; tmp; tmp = nxt[tmp]) {
    if (num[tmp] == 0) {
      dfs1(point[tmp]);
      continue;
    }
    if (!nowedge[num[tmp]]) nowedge[num[tmp]] = weight[tmp];
    if (nowedge[num[tmp]] != weight[tmp]) continue;
    dfs1(point[tmp]);
  }
}
void dfs2(int x) {
  if (exist[x]) return;
  ans++;
  exist[x] = 1;
  for (int tmp = head[x]; tmp; tmp = nxt[tmp]) {
    if (num[tmp] == 0) {
      dfs2(point[tmp]);
      continue;
    }
    if (!nowedge[num[tmp]]) nowedge[num[tmp]] = -weight[tmp];
    if (nowedge[num[tmp]] != weight[tmp]) continue;
    dfs2(point[tmp]);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &t, &a, &b);
    add(a, b, t);
  }
  dfs1(s);
  printf("%d\n", ans);
  for (int i = 1; i <= cnt; i++)
    if (nowedge[i] == -1)
      putchar('-');
    else
      putchar('+');
  memset(nowedge, 0, sizeof(nowedge));
  memset(exist, 0, sizeof(exist));
  ans = 0;
  dfs2(s);
  printf("\n%d\n", ans);
  for (int i = 1; i <= cnt; i++)
    if (nowedge[i] == -1)
      putchar('-');
    else
      putchar('+');
}
