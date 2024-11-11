#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
map<int, int> nxt[N];
int link[N], len[N], las = 1, n, id[N], f[N][19], cnt = 1;
char s[N];
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
void dfs(int x) {
  f[x][0] = link[x];
  for (int i = 1; i <= 18; i++) f[x][i] = f[f[x][i - 1]][i - 1];
  for (auto y : a[x]) dfs(y), root[x] = merge(root[x], root[y], 1, n);
}
inline int read() {
  register int data = 0, w = 1;
  char ch = 0;
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    data = (data << 1) + (data << 3) + (ch ^ 48), ch = getchar();
  return data * w;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) s[i] = read();
  for (int i = n; i >= 1; i--) s[i] -= s[i - 1];
  for (int i = 2; i <= n; i++) insert(s[i]), id[i] = las;
  insert((int)2e9);
  for (int i = 2; i <= n; i++) insert(-s[i]), update(root[las], 1, n, i);
  for (int i = 2; i <= cnt; i++) a[link[i]].push_back(i);
  dfs(1);
  int q = read();
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
      int ans = 0;
      if (l <= x - 1) ans += query(root[p], 1, n, l, x - 1);
      if (y + l <= n) ans += query(root[p], 1, n, y + l, n);
      printf("%d\n", ans);
    }
  }
  return 0;
}
