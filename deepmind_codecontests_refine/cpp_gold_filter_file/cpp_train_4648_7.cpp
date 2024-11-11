#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 5;
const int MAXM = 105;
int st[MAXN], top, tree_cnt;
int ls[MAXN], rs[MAXN], rt[MAXM], val[200005];
inline int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
inline int get() { return top ? st[top--] : ++tree_cnt; }
void modify(int l, int r, int p, int &cur) {
  if (!cur) cur = ++tree_cnt;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (p <= mid)
    modify(l, mid, p, ls[cur]);
  else
    modify(mid + 1, r, p, rs[cur]);
}
void merge(int &x, int &y) {
  if (!x || !y) return x |= y, y = 0, void();
  merge(ls[x], ls[y]), merge(rs[x], rs[y]), y = 0;
}
void change(int l, int r, int ql, int qr, int &pre, int &cur) {
  if (!pre) return;
  if (ql <= l && qr >= r) return merge(cur, pre);
  if (!cur) cur = get();
  int mid = (l + r) >> 1;
  if (ql <= mid) change(l, mid, ql, qr, ls[pre], ls[cur]);
  if (qr > mid) change(mid + 1, r, ql, qr, rs[pre], rs[cur]);
  if (!ls[pre] && !rs[pre]) st[++top] = pre, pre = 0;
}
void dfs(int l, int r, int cur, int c) {
  if (!cur) return;
  if (l == r) return val[l] = c, void();
  int mid = (l + r) >> 1;
  dfs(l, mid, ls[cur], c);
  dfs(mid + 1, r, rs[cur], c);
}
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) modify(1, n, i, rt[read()]);
  int m = read();
  for (int i = 1; i <= m; i++) {
    int l = read(), r = read();
    int x = read(), y = read();
    if (x == y) continue;
    change(1, n, l, r, rt[x], rt[y]);
  }
  for (int i = 1; i <= 100; i++) dfs(1, n, rt[i], i);
  for (int i = 1; i <= n; i++) printf("%d%c", val[i], " \n"[i == n]);
  return 0;
}
