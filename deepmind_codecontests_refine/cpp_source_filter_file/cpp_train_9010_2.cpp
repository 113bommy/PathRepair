#include <bits/stdc++.h>
using namespace std;
const int N = 250;
int n, m, B, ans;
int co[N], sx[N], sy[N];
int mp[N][N], id[N], fl[N];
bool cmp(int x, int y) { return sy[x] < sy[y]; }
const int ND = 500;
struct edge {
  int to, next, f, v;
} e[N * N];
int head[ND], cur[ND], tot;
int S, T, dis[ND];
int q[ND * ND], tp[ND], fr[ND];
bool vis[ND];
void add(int x, int y, int v) {
  e[++tot] = (edge){y, head[x], 1, v};
  head[x] = tot;
  e[++tot] = (edge){x, head[y], 0, v};
  head[y] = tot;
}
int times = 0;
bool bfs() {
  for (int i = (int)(1); i <= (int)(T); i++) dis[i] = 2333, vis[i] = 0;
  int h = 0, t = 1;
  q[1] = S;
  dis[S] = 1;
  while (h != t) {
    int x = q[++h];
    vis[x] = 0;
    for (int i = head[x]; i; i = e[i].next)
      if (dis[e[i].to] > dis[x] + e[i].v && e[i].f) {
        dis[e[i].to] = dis[x] + e[i].v;
        fr[e[i].to] = i;
        if (!vis[e[i].to]) {
          vis[e[i].to] = 1;
          q[++t] = e[i].to;
        }
      }
  }
  if (dis[T] == 2333) return 0;
  return 1;
}
int dfs(int x, int flow) {
  if (x == T) return flow;
  int k, rest = flow;
  vis[x] = 1;
  for (int &i = cur[x]; i; i = e[i].next)
    if (e[i].f && !vis[e[i].to] && dis[e[i].to] == dis[x] + e[i].v) {
      k = dfs(e[i].to, min(rest, e[i].f));
      e[i].f -= k;
      e[i ^ 1].f += k;
      rest -= k;
      if (!rest) break;
    }
  if (rest) dis[x] = -1;
  vis[x] = 0;
  return flow - rest;
}
struct fuckmdndandwzp {
  int i, j, beg, cnt;
} Ans[5000005];
int ans_top;
const int OUT_SIZE = 100000000;
char out[OUT_SIZE];
int out_top;
void write(int x) {
  if (!x) {
    out[out_top++] = '0';
    return;
  }
  static int a[15], top;
  for (top = 0; x; a[++top] = x % 10, x /= 10)
    ;
  for (; top; out[out_top++] = a[top--] + '0')
    ;
}
void writespace(int x) {
  write(x);
  out[out_top++] = ' ';
}
void writeln(int x) {
  write(x);
  out[out_top++] = '\n';
}
int edge[N][N];
bool visx[N], visy[N];
int main() {
  scanf("%d%d%d", &n, &m, &B);
  for (int i = (int)(1); i <= (int)(m); i++) scanf("%d", &co[i]);
  for (int i = (int)(1); i <= (int)(n); i++) {
    int cnt;
    scanf("%d", &cnt);
    while (cnt--) {
      int x, y;
      scanf("%d%d", &x, &y);
      mp[i][x] = y;
      sx[i] += y;
      sy[x] += y;
    }
  }
  for (int i = (int)(1); i <= (int)(n); i++) ans = max(ans, sx[i]);
  for (int i = (int)(1); i <= (int)(m); i++) id[i] = i;
  sort(id + 1, id + m + 1, cmp);
  int p = m;
  for (; p && B >= co[id[p]]; B -= co[id[p--]])
    ;
  for (int i = (int)(1); i <= (int)(p); i++) ans = max(ans, sy[id[i]]);
  for (int i = (int)(p + 1); i <= (int)(m); i++) {
    ans = max(ans, (sy[id[i]] + 1) / 2);
    fl[id[i]] = 1;
    int cnt = 0;
    for (int j = (int)(1); j <= (int)(n); j++) cnt += (mp[j][id[i]] & 1);
    cnt = (cnt + 1) / 2;
    for (int j = (int)(1); j <= (int)(n); j++) {
      int v = mp[j][id[i]];
      mp[j][id[i]] = mp[j][id[i] + m] = v / 2;
      if (v & 1) {
        if ((--cnt) >= 0)
          mp[j][id[i]]++;
        else
          mp[j][id[i] + m]++;
      }
    }
  }
  writeln(ans);
  for (int i = (int)(1); i <= (int)(m); i++) write(fl[i]);
  out[out_top++] = '\n';
  m *= 2;
  for (int i = (int)(1); i <= (int)(n); i++) sx[i] = 0;
  for (int i = (int)(1); i <= (int)(m); i++) sy[i] = 0;
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(m); j++)
      sx[i] += mp[i][j], sy[j] += mp[i][j];
  int times = 0;
  for (int TT = 0;;) {
    bool flag = 0;
    memset(head, 0, sizeof(head));
    tot = 1;
    S = n + m + 1;
    T = S + 1;
    for (int i = (int)(1); i <= (int)(n); i++)
      for (int j = (int)(1); j <= (int)(m); j++)
        if (mp[i][j]) {
          edge[i][j] = tot + 1;
          flag = 1;
          add(i, j + n, 0);
        }
    if (!flag) break;
    for (int i = (int)(1); i <= (int)(n); i++) add(S, i, sx[i] != ans);
    for (int i = (int)(1); i <= (int)(m); i++) add(i + n, T, sy[i] != ans);
    for (; bfs(); times++) {
      for (int i = (int)(1); i <= (int)(T); i++) cur[i] = head[i], vis[i] = 0;
      dfs(S, 1e9);
    }
    int mn = 1e9;
    for (int i = (int)(1); i <= (int)(n); i++) visx[i] = 0;
    for (int i = (int)(1); i <= (int)(m); i++) visy[i] = 0;
    for (int i = (int)(1); i <= (int)(n); i++)
      for (int j = (int)(1); j <= (int)(m); j++)
        if (!e[edge[i][j]].f && mp[i][j])
          mn = min(mn, mp[i][j]), visx[i] = visy[j] = 1;
    for (int i = (int)(1); i <= (int)(n); i++)
      if (!visx[i] && sx[i]) mn = min(mn, ans - sx[i]);
    for (int i = (int)(1); i <= (int)(m); i++)
      if (!visy[i] && sy[i]) mn = min(mn, ans - sy[i]);
    for (int i = (int)(1); i <= (int)(n); i++)
      for (int j = (int)(1); j <= (int)(m); j++)
        if (!e[edge[i][j]].f && mp[i][j]) {
          Ans[++ans_top] = (fuckmdndandwzp){i, j, TT, mn};
          mp[i][j] -= mn;
          sx[i] -= mn;
          sy[j] -= mn;
        }
    TT += mn;
    ans -= mn;
  }
  writeln(ans_top);
  for (int i = (int)(1); i <= (int)(ans_top); i++) {
    writespace(Ans[i].i);
    writespace(Ans[i].j - (Ans[i].j >= m ? 0 : m));
    writespace(Ans[i].beg);
    writeln(Ans[i].cnt);
  }
  fwrite(out, 1, out_top, stdout);
}
