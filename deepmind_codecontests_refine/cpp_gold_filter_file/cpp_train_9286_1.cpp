#include <bits/stdc++.h>
using namespace std;
int n, cnt = -1, temp, qcnt = 0;
int deg[500000], l1[500000], l2[500000];
int fir[500000], to[1000000], nxt[1000000];
int fa[500000], ans[500000], f[500000];
int id[500000], mx[2000000], o[500000];
vector<int> len[500000];
struct query {
  int x, val, o;
} qu[1000000];
inline bool comp(query q1, query q2) { return q1.val > q2.val; }
inline void Add(int a, int b, int c) {
  qu[qcnt].x = a;
  qu[qcnt].val = c;
  qu[qcnt++].o = b;
  return;
}
inline void add(int a, int b) {
  to[++cnt] = b;
  nxt[cnt] = fir[a];
  fir[a] = cnt;
  deg[b]++;
  return;
}
void dfs1(int i, int f) {
  fa[i] = f;
  for (int j = fir[i]; j != -1; j = nxt[j]) {
    if (to[j] == f) continue;
    dfs1(to[j], i);
    l1[i] = max(l1[i], l1[to[j]]);
  }
  l1[i]++;
  return;
}
void dfs2(int i, int l) {
  l2[i] = l;
  int mx1 = 0, mx2 = 0;
  for (int j = fir[i]; j != -1; j = nxt[j]) {
    temp = to[j];
    if (temp == fa[i]) continue;
    if (mx1 < l1[temp]) {
      mx2 = mx1;
      mx1 = l1[temp];
    } else if (mx2 < l1[temp])
      mx2 = l1[temp];
  }
  for (int j = fir[i]; j != -1; j = nxt[j]) {
    temp = to[j];
    if (temp == fa[i]) continue;
    if (mx1 == l1[temp])
      dfs2(temp, max(mx2, l2[i]) + 1);
    else
      dfs2(temp, max(mx1, l2[i]) + 1);
  }
  return;
}
int t1, t2;
void upd(int i, int l, int r) {
  if (l == r) {
    mx[i]++;
    return;
  }
  int mid = (l + r) >> 1;
  if (t1 <= mid)
    upd(i << 1, l, mid);
  else
    upd(i << 1 | 1, mid + 1, r);
  mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
  return;
}
inline void update(int x) {
  t1 = x;
  upd(1, 0, n - 1);
  f[x]++;
  return;
}
int qry(int i, int l, int r) {
  if (t1 <= l && r <= t2) return mx[i];
  int mid = (l + r) >> 1, res = 0;
  if (t1 <= mid) res = qry(i << 1, l, mid);
  if (mid < t2) res = max(res, qry(i << 1 | 1, mid + 1, r));
  return res;
}
inline int querymax(int x, int y) {
  t1 = x;
  t2 = y;
  return qry(1, 0, n - 1);
}
void bfs(void) {
  cnt = 0;
  id[0] = cnt++;
  queue<int> q;
  q.push(0);
  while (q.size() > 0) {
    int i = q.front();
    q.pop();
    o[i] = cnt - 1;
    for (int j = fir[i]; j != -1; j = nxt[j])
      if (to[j] != fa[i]) {
        id[to[j]] = cnt++;
        q.push(to[j]);
      }
  }
  return;
}
void solve(void) {
  for (int i = 2; i < n; i++) ans[i] = 1;
  for (int i = 0; i < n; i++) {
    int s = deg[i];
    for (int d = 1; d <= s; d++) {
      temp = len[i][s - d] * 2;
      ans[temp] = max(ans[temp], d);
      ans[temp - 1] = max(ans[temp - 1], d);
      if (d > 1 && len[i][s - d + 1] > len[i][s - d])
        ans[temp + 1] = max(ans[temp + 1], d);
    }
  }
  for (int i = 0; i < n; i++)
    for (int d = 1; d <= deg[i]; d++) Add(i, d, len[i][deg[i] - d]);
  sort(qu, qu + qcnt, comp);
  int pos = 0;
  for (int i = 0; i < qcnt; i++) {
    while (pos < qcnt && qu[pos].val >= qu[i].val) update(id[qu[pos++].x]);
    int X = qu[i].x, D = 2 * qu[i].val;
    temp = querymax(o[X] + 1, o[X] + deg[X] - 1);
    if (X != 0) temp = max(temp, f[id[fa[X]]]);
    ans[D] = max(ans[D], temp + qu[i].o - 2);
  }
  return;
}
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) fir[i] = -1;
  int a, b;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &a, &b);
    add(a - 1, b - 1);
    add(b - 1, a - 1);
  }
  dfs1(0, -1);
  dfs2(0, 0);
  bfs();
  for (int i = 1; i < n; i++) {
    len[fa[i]].push_back(l1[i]);
    len[i].push_back(l2[i]);
  }
  for (int i = 0; i < n; i++) {
    sort(len[i].begin(), len[i].end());
    ans[1] = max(ans[1], deg[i] + 1);
  }
  solve();
  for (int i = n - 3; i > 0; i--) ans[i] = max(ans[i], ans[i + 2]);
  for (int i = 1; i < n; i++) printf("%d ", ans[i]);
  printf("1\n");
  return 0;
}
