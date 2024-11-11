#include <bits/stdc++.h>
using namespace std;
int n, m;
struct E {
  int x, o, i;
} e[100010 << 1];
int cnt;
struct _E {
  int ed, o, i, ne;
} _e[100010 << 3];
int in[100010 << 1], he[100010 << 1], en = 1;
bool vis[100010 << 3];
int path[100010 << 2], tot;
int ans[100010];
bool cmp1(E a, E b) { return a.x < b.x; }
bool cmp2(E a, E b) { return a.i == b.i ? a.o < b.o : a.i < b.i; }
void ins(int a, int b, int i) {
  ++in[a];
  ++in[b];
  _e[++en].ed = b;
  _e[en].o = 0;
  _e[en].i = i;
  _e[en].ne = he[a];
  he[a] = en;
  _e[++en].ed = a;
  _e[en].o = 1;
  _e[en].i = i;
  _e[en].ne = he[b];
  he[b] = en;
}
void dfs(int u) {
  for (int &i = he[u]; i; i = _e[i].ne)
    if (!vis[i]) {
      vis[i] = vis[i ^ 1] = 1;
      int j = i;
      dfs(_e[i].ed);
      path[++tot] = j;
    }
}
int main() {
  int i, x, la;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &x);
    e[++cnt] = (E){x, 0, i};
    scanf("%d", &x);
    e[++cnt] = (E){x + 1, 1, i};
  }
  sort(e + 1, e + cnt + 1, cmp1);
  for (i = 1; i <= cnt; ++i) {
    if (i == 1 || e[i].x != la) {
      ++m;
      la = e[i].x;
    }
    e[i].x = m;
  }
  sort(e + 1, e + cnt + 1, cmp2);
  for (i = 1; i <= n; ++i) ins(e[(i << 1) - 1].x, e[i << 1].x, e[i << 1].i);
  la = 0;
  for (i = 1; i <= m; ++i)
    if (in[i] & 1) {
      if (!la)
        la = i;
      else {
        ins(la, i, 0);
        la = 0;
      }
    }
  for (i = 1; i <= m; ++i) dfs(i);
  for (i = 1; i <= tot; ++i) {
    x = path[i];
    ans[_e[x].i] = _e[x].o;
  }
  for (i = 1; i <= n; ++i) printf("%d ", ans[i]);
  puts("");
  return 0;
}
