#include <bits/stdc++.h>
using namespace std;
const int maxnn = 4e3 + 7;
const int inf = 1e7 + 7;
int n;
int nxt[maxnn];
int to[maxnn];
int from[maxnn];
int head[maxnn];
int cnt = 1;
void add(int l, int r) {
  to[cnt] = r;
  nxt[cnt] = head[l];
  head[l] = cnt++;
}
struct dy {
  int fu;
  int c;
  int xh;
  int r;
  int q;
} a[maxnn];
int ans[maxnn];
int cx[maxnn];
void bfs(int p, int sd) {
  a[p].r = sd;
  sd++;
  cx[p] = 1;
  for (int i = head[p]; i; i = nxt[i]) {
    bfs(to[i], sd);
    cx[p] += cx[to[i]];
  }
  return;
}
int vis[maxnn];
void bbfs(int p) {
  int cs = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) cs++;
    if (cs == a[p].c + 1) {
      ans[p] = i;
      break;
    }
  }
  vis[ans[p]] = 1;
  for (int i = head[p]; i; i = nxt[i]) {
    bbfs(to[i]);
  }
  return;
}
bool cmp(dy x, dy y) { return x.r > y.r; }
bool cmp2(dy x, dy y) { return x.xh < y.xh; }
int main() {
  scanf("%d", &n);
  int s;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i].fu, &a[i].c);
    a[i].xh = i;
    if (a[i].fu != 0)
      add(a[i].fu, i);
    else
      s = i;
  }
  bfs(s, 1);
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    if (cx[i] < a[i].c) {
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  bbfs(s);
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}
