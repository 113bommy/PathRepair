#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
map<int, int> nxt[N];
int link[N], len[N], cnt = 1, las = 1, n, id[N], f[N][19];
int s[N];
void insert(int c) {
  int cur = ++cnt, p = las;
  len[cur] = len[las] + 1;
  las = cur;
  for (; p && !nxt[p][c]; p = link[p]) nxt[p][c] = cur;
  if (!p)
    link[cur] = 1;
  else {
    int q = nxt[p][c];
    if (len[q] == len[p] + 1)
      link[cur] = q;
    else {
      int clone = ++cnt;
      len[clone] = len[p] + 1;
      link[clone] = link[q];
      link[q] = link[cur] = clone;
      nxt[clone] = nxt[q];
      for (; nxt[p][c] == q; p = link[p]) nxt[p][c] = clone;
    }
  }
}
struct segNode {
  int l, r, v = 0;
} t[N * 30];
int root[N], sc;
vector<int> a[N];
void make_st() {
  for (int i = 2; i <= cnt; i++) f[i][0] = link[i], a[link[i]].push_back(i);
  for (int i = 1; i <= 18; i++)
    for (int j = 2; j <= cnt; j++) f[j][i] = f[f[j][i - 1]][i - 1];
}
void update(int &now, int l, int r, int pos) {
  if (!now) now = ++sc;
  t[now].v++;
  if (l == r) return;
  if (pos <= (l + r) / 2)
    update(t[now].l, l, (l + r) / 2, pos);
  else
    update(t[now].r, (l + r) / 2 + 1, r, pos);
}
int merge(int x, int y, int l, int r) {
  if (x == 0 || y == 0) {
    return x + y;
  }
  int now = ++sc;
  t[now].v = t[x].v + t[y].v;
  if (l == r) return now;
  t[now].l = merge(t[x].l, t[y].l, l, (l + r) / 2);
  t[now].r = merge(t[x].r, t[y].r, (l + r) / 2 + 1, r);
  return now;
}
int query(int now, int l, int r, int x, int y) {
  if (x <= l && r <= y) return t[now].v;
  int ans = 0;
  if (x <= (l + r) / 2) ans += query(t[now].l, l, (l + r) / 2, x, y);
  if (y > (l + r) / 2) ans += query(t[now].r, (l + r) / 2 + 1, r, x, y);
  return ans;
}
void dfs_for_merge(int now) {
  for (auto to : a[now]) {
    dfs_for_merge(to);
    root[now] = merge(root[now], root[to], 1, n);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", s + i);
  for (int i = 1; i < n; i++) {
    int c = s[i + 1] - s[i];
    insert(c);
    id[i + 1] = las;
  }
  insert(2e9);
  for (int i = 1; i < n; i++) {
    int c = s[i] - s[i + 1];
    insert(c);
    update(root[las], 1, n, i + 1);
  }
  make_st();
  dfs_for_merge(1);
  t[root[1]].v = 0;
  int q;
  scanf("%d", &q);
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    int l = y - x + 1;
    if (l == 1)
      printf("%d\n", n - 1);
    else {
      int p = id[y];
      for (int i = 18; i >= 0; i--) {
        if (len[f[p][i]] >= l - 1) p = f[p][i];
      }
      int ans = t[root[p]].v - query(root[p], 1, n, x, min(n, y + l));
      printf("%d\n", ans);
    }
  }
  return 0;
}
