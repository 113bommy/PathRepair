#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 100000;
const int INF = 0x3f3f3f3f;
inline void readInt(int& a) {
  a = 0;
  int c;
  do c = getchar();
  while (c < '0' || c > '9');
  do {
    a = a * 10 - '0' + c;
    c = getchar();
  } while (c >= '0' && c <= '9');
}
int n, lim, wlim, nodes[MAX_SIZE + 10], nxt[MAX_SIZE * 2 + 10],
    to[MAX_SIZE * 2 + 10], w[MAX_SIZE * 2 + 10], size[MAX_SIZE + 10], tot;
int en;
int minn, root;
bool vis[MAX_SIZE + 10];
int dep[MAX_SIZE + 10], wdep[MAX_SIZE + 10];
int seq[MAX_SIZE + 10];
int le[MAX_SIZE + 10], ri[MAX_SIZE + 10], sn, bn;
int arr[MAX_SIZE + 10], tmp[MAX_SIZE + 10], tn;
long long ans;
inline int lowbit(int a) { return a & -a; }
void change(int p, int inc) {
  while (p <= n) {
    arr[p] += inc;
    p += lowbit(p);
  }
}
int query(int p) {
  int ans = 0;
  while (p > 0) {
    ans += arr[p];
    p -= lowbit(p);
  }
  return ans;
}
inline void addEdge(int f, int t, int _w) {
  ++en;
  to[en] = t;
  w[en] = _w;
  nxt[en] = nodes[f];
  nodes[f] = en;
}
void dfsSize(int cur, int fa) {
  size[cur] = 1;
  for (int e = nodes[cur]; e; e = nxt[e]) {
    if (to[e] == fa || vis[to[e]]) continue;
    dfsSize(to[e], cur);
    size[cur] += size[to[e]];
  }
}
void dfsRoot(int cur, int fa) {
  int maxn = tot - size[cur];
  for (int e = nodes[cur]; e; e = nxt[e]) {
    if (to[e] == fa || vis[to[e]]) continue;
    dfsRoot(to[e], cur);
    if (size[to[e]] > maxn) maxn = size[to[e]];
  }
  if (maxn < minn) {
    root = cur;
    minn = maxn;
  }
}
void dfs(int cur, int fa) {
  seq[++sn] = cur;
  if (dep[cur] <= lim && wdep[cur] <= wlim) ++ans;
  for (int e = nodes[cur]; e; e = nxt[e]) {
    if (vis[to[e]] || to[e] == fa) continue;
    dep[to[e]] = dep[cur] + 1;
    wdep[to[e]] = wdep[to[e]] + w[e];
    dfs(to[e], cur);
  }
}
inline bool cmp(const int& a, const int& b) { return wdep[a] < wdep[b]; }
inline int min(int a, int b) { return a < b ? a : b; }
void work(int l, int r) {
  if (l == r) {
    sort(seq + le[l], seq + ri[l] + 1, cmp);
    return;
  }
  int mid = (l + r) >> 1;
  work(l, mid);
  work(mid + 1, r);
  int p1, p2;
  p1 = le[l];
  for (p2 = ri[r]; p2 >= le[mid + 1]; p2--) {
    while (p1 <= ri[mid] && wdep[seq[p1]] + wdep[seq[p2]] <= wlim) {
      change(dep[seq[p1]], 1);
      ++p1;
    }
    ans += query(min(n, lim - dep[seq[p2]]));
  }
  for (int i = le[l]; i < p1; i++) change(dep[seq[i]], -1);
  tn = 0;
  p1 = le[l];
  p2 = le[mid + 1];
  while (p1 <= ri[mid] || p2 <= ri[r]) {
    if (p1 > ri[mid])
      tmp[++tn] = seq[p2++];
    else if (p2 > ri[r])
      tmp[++tn] = seq[p1++];
    else if (wdep[seq[p1]] < wdep[seq[p2]])
      tmp[++tn] = seq[p1++];
    else
      tmp[++tn] = seq[p2++];
  }
  for (int i = 1; i <= tn; i++) seq[le[l] + i - 1] = tmp[i];
}
void work(int cur) {
  dfsSize(cur, 0);
  tot = size[cur];
  minn = INF;
  dfsRoot(cur, 0);
  cur = root;
  vis[cur] = true;
  bn = sn = 0;
  for (int e = nodes[cur]; e; e = nxt[e]) {
    if (!vis[to[e]]) {
      ++bn;
      le[bn] = sn + 1;
      dep[to[e]] = 1;
      wdep[to[e]] = w[e];
      dfs(to[e], 0);
      ri[bn] = sn;
    }
  }
  if (bn > 0) work(1, bn);
  for (int e = nodes[cur]; e; e = nxt[e])
    if (!vis[to[e]]) work(to[e]);
}
int main() {
  readInt(n);
  readInt(lim);
  readInt(wlim);
  for (int i = 2; i <= n; i++) {
    int a, _w;
    readInt(a);
    readInt(_w);
    addEdge(a, i, _w);
    addEdge(i, a, _w);
  }
  work(1);
  printf(
      "%I64d"
      "\n",
      ans);
  return 0;
}
