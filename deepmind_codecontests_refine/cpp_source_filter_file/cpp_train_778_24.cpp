#include <bits/stdc++.h>
using namespace std;
const int N = 404040;
int cnt, cnt2, cnt3, h, n, m;
struct Node {
  int x, y, w, d, i;
} a[N];
bool cmp(Node x, Node y) { return x.d < y.d; }
vector<int> s[N];
vector<pair<int, int> > ss[N];
int dfn[N], low[N], viss[N], q[N], color[N], as[N];
map<int, int> sum, vis;
void jiantu(int x, int y) { s[x].push_back(y); }
void tarjan(int x) {
  int c, i, y;
  q[h++] = x, viss[x] = 1;
  dfn[x] = low[x] = ++cnt2;
  c = s[x].size();
  for (i = 0; i < c; i++) {
    y = s[x][i];
    if (!dfn[y])
      tarjan(y), low[x] = min(low[x], low[y]);
    else if (viss[y])
      low[x] = min(low[x], dfn[y]);
  }
  if (low[x] == dfn[x]) {
    cnt3++;
    while (1) {
      h--;
      color[q[h]] = cnt3;
      viss[q[h]] = 0;
      if (q[h] == x) {
        q[h] = 0;
        break;
      }
      q[h] = 0;
    }
  }
}
int check(int x) {
  int i, ans = 1;
  for (i = x + 1; i <= m; i++) jiantu(i + i, i + i - 1);
  cnt2 = 0, cnt3 = 0;
  memset(dfn, 0, sizeof(dfn));
  memset(low, 0, sizeof(low));
  memset(viss, 0, sizeof(viss));
  memset(color, 0, sizeof(color));
  for (i = 1; i <= cnt; i++)
    if (!dfn[i]) h = 0, tarjan(i);
  for (i = 1; i <= m; i++)
    if (color[i + i - 1] == color[i + i]) ans = 0;
  for (i = x + 1; i <= m; i++) s[i + i].pop_back();
  return ans;
}
int erf(int l, int r) {
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  return l;
}
void init() {
  int c, i, y, j, pl;
  cnt = n + n;
  for (i = 1; i <= n; i++) {
    c = ss[i].size();
    for (j = 0; j < c; j++) {
      y = ss[i][j].first;
      pl = ss[i][j].second;
      sum[a[pl].w]++;
      if (sum[a[pl].w] == 3) {
        puts("No");
        exit(0);
      } else if (sum[a[pl].w] == 2) {
        jiantu(vis[a[pl].w] * 2 - 1, pl + pl);
        jiantu(pl + pl - 1, vis[a[pl].w] * 2);
      }
      vis[a[pl].w] = pl;
    }
    for (j = 0; j < c; j++) sum[a[ss[i][j].second].w]--;
    for (j = 0; j < c; j++) {
      y = ss[i][j].second;
      if (j != c - 1) {
        cnt++;
        if (j != 0) jiantu(cnt, cnt - 1);
        jiantu(cnt, y + y - 1);
      }
      if (j != 0) {
        if (j != c - 1)
          jiantu(y + y, cnt - 1);
        else
          jiantu(y + y, cnt);
      }
    }
    for (j = c - 1; j >= 0; j--) {
      y = ss[i][j].second;
      if (j != 0) {
        cnt++;
        jiantu(cnt, y + y - 1);
        if (j != c - 1) jiantu(cnt, cnt - 1);
      }
      if (j != c - 1) {
        if (j != 0)
          jiantu(y + y, cnt - 1);
        else
          jiantu(y + y, cnt);
      }
    }
  }
}
int main() {
  int i, ans, cnt;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++)
    scanf("%d%d%d%d", &a[i].x, &a[i].y, &a[i].w, &a[i].d), a[i].i = i;
  sort(a + 1, a + m + 1, cmp);
  for (i = 1; i <= m; i++)
    ss[a[i].x].push_back(make_pair(a[i].y, i)),
        ss[a[i].y].push_back(make_pair(a[i].x, i));
  init();
  ans = erf(1, m);
  if (!check(ans)) {
    puts("No");
    return 0;
  }
  puts("Yes");
  cnt = 0;
  for (i = 1; i <= m; i++)
    if (color[i + i - 1] > color[i + i]) as[++cnt] = a[i].i;
  printf("%d %d\n", a[ans].d, cnt);
  for (i = 1; i <= cnt; i++) printf("%d ", as[i]);
  return 0;
}
