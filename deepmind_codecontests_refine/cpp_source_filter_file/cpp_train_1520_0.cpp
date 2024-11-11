#include <bits/stdc++.h>
using namespace std;
struct Line {
  int nxt, t, cap;
} l[850000];
int tl, fir[60500];
void adl(int f, int t, int cap) {
  l[++tl] = (Line){fir[f], t, cap};
  fir[f] = tl;
  l[++tl] = (Line){fir[t], f, 0};
  fir[t] = tl;
}
int tn, S, T, dis[60500], cur[60500];
queue<int> q;
bool bfs() {
  for (int i = 1; i <= tn; i++) {
    cur[i] = fir[i];
    dis[i] = 0;
  }
  q.push(S);
  dis[S] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = fir[u]; i; i = l[i].nxt)
      if (l[i].cap && !dis[l[i].t]) {
        dis[l[i].t] = dis[u] + 1;
        q.push(l[i].t);
      }
  }
  return dis[T];
}
int dfs(int u, int flow) {
  if (u == T) return flow;
  int sum = 0;
  for (int &i = cur[u]; i; i = l[i].nxt)
    if (dis[l[i].t] == dis[u] + 1 && l[i].cap) {
      int sav = dfs(l[i].t, min(flow, l[i].cap));
      if (sav) {
        l[i].cap -= sav;
        l[i ^ 1].cap += sav;
        sum += sav;
        flow -= sav;
        if (!flow) return sum;
      } else
        dis[l[i].t] = -1;
    }
  return sum;
}
struct Node {
  int l, r;
} a[60500];
int rt1, rt2;
void build1(int l, int r, int &u) {
  u = ++tn;
  if (l == r) {
    adl(S, u, 1);
    return;
  }
  int mid = (l + r) >> 1;
  build1(l, mid, a[u].l);
  build1(mid + 1, r, a[u].r);
  adl(a[u].l, u, r - l + 1);
  adl(a[u].r, u, r - l + 1);
}
void build2(int l, int r, int &u) {
  u = ++tn;
  if (l == r) {
    adl(u, T, 1);
    return;
  }
  int mid = (l + r) >> 1;
  build2(l, mid, a[u].l);
  build2(mid + 1, r, a[u].r);
  adl(u, a[u].l, r - l + 1);
  adl(u, a[u].r, r - l + 1);
}
int n, wfl, wfr, to;
void add1(int l = 1, int r = n, int u = rt1) {
  if (wfl <= l && r <= wfr) {
    adl(u, to, r - l + 1);
    return;
  }
  int mid = (l + r) >> 1;
  if (wfl <= mid) add1(l, mid, a[u].l);
  if (mid < wfr) add1(mid + 1, r, a[u].r);
}
void add2(int l = 1, int r = n, int u = rt2) {
  if (wfl <= l && r <= wfr) {
    adl(to, u, r - l + 1);
    return;
  }
  int mid = (l + r) >> 1;
  if (wfl <= mid) add2(l, mid, a[u].l);
  if (mid < wfr) add2(mid + 1, r, a[u].r);
}
struct Seg {
  int x, l, r;
  bool op;
} sl[20500];
bool cmp(const Seg &A, const Seg &B) {
  return A.x == B.x ? A.op < B.op : A.x < B.x;
}
int m, tp[10500];
int main() {
  S = 1;
  tn = T = 2;
  scanf("%d%d", &n, &m);
  build1(1, n, rt1);
  build2(1, n, rt2);
  for (int i = 1, x1, y1, x2, y2; i <= m; i++) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    sl[(i << 1) - 1] = (Seg){x1, y1, y2, 1};
    sl[i << 1] = (Seg){x2 + 1, y1, y2, 0};
  }
  sl[m = (m + m + 1)] = (Seg){n + 1, 1, n, 1};
  sort(sl + 1, sl + m + 1, cmp);
  for (int i = 1; i <= n; i++) tp[i] = 1;
  for (int i = 1; i <= m; i++)
    if (sl[i].op) {
      int p = sl[i].l;
      swap(tp[0], tp[sl[i].r + 1]);
      for (int j = sl[i].l; j <= sl[i].r; j++) {
        if (tp[j] != tp[j + 1] && tp[j] > 0 && tp[j] < sl[i].x) {
          to = ++tn;
          wfl = tp[j];
          wfr = sl[i].x - 1;
          add1();
          wfl = p;
          wfr = j;
          add2();
        }
        if (tp[j] != tp[j + 1]) p = j + 1;
        if (tp[j] > 0)
          tp[j] = -1;
        else
          tp[j]--;
      }
      swap(tp[0], tp[sl[i].r + 1]);
    } else {
      for (int j = sl[i].l; j <= sl[i].r; j++)
        if (tp[j] == -1)
          tp[j] = sl[i].x;
        else
          tp[j]++;
    }
  int ans = 0;
  while (bfs()) ans += dfs(S, 1000000000);
  printf("%d\n", ans);
  return 0;
}
