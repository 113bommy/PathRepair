#include <bits/stdc++.h>
const int MAXN = 1e6 + 10;
struct Node {
  int l, r, id;
} e[MAXN];
std::vector<int> v1[MAXN], v2[MAXN];
long long ans[MAXN];
int n, q, top, val[MAXN], lc[MAXN], rc[MAXN], stk[MAXN];
inline int read() {
  int X = 0, flag = 0;
  char ch = 0;
  while (!isdigit(ch)) flag |= ch == '-', ch = getchar();
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return flag ? -X : X;
}
inline void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
namespace Seg {
long long sum1[MAXN << 2], sum2[MAXN << 2];
inline void pushup(int cur) {
  sum1[cur] = sum1[cur << 1] + sum1[cur << 1 | 1];
  sum2[cur] = sum2[cur << 1] + sum2[cur << 1 | 1];
}
inline void build(int Now, int L, int r, int cur) {
  if (L == r) {
    if (Now == 1) {
      sum1[cur] = lc[r] + 1;
    } else {
      sum1[cur] = rc[r] - 1;
    }
    sum2[cur] = 0;
    return;
  }
  int mid = (L + r) >> 1;
  build(Now, L, mid, cur << 1);
  build(Now, mid + 1, r, cur << 1 | 1);
  pushup(cur);
}
inline void modify(int add, int L, int r, int cur) {
  if (L == r) {
    sum1[cur] = 0, sum2[cur] = 1;
    return;
  }
  int mid = (L + r) >> 1;
  if (add <= mid)
    modify(add, L, mid, cur << 1);
  else
    modify(add, mid + 1, r, cur << 1 | 1);
  pushup(cur);
}
inline long long query(int L, int R, int x, int l, int r, int cur) {
  if (L <= l && r <= R) return sum1[cur] + x * sum2[cur];
  long long res = 0;
  int mid = (l + r) >> 1;
  if (L <= mid) res += query(L, R, x, L, mid, cur << 1);
  if (mid < R) res += query(L, R, x, mid + 1, r, cur << 1 | 1);
  return res;
}
}  // namespace Seg
signed main() {
  n = read(), q = read();
  for (int i = 1; i <= n; i++) val[i] = read();
  for (int i = 1; i <= q; i++) e[i].l = read(), e[i].id = i;
  for (int i = 1; i <= q; i++) e[i].r = read();
  for (int i = 1; i <= n; i++) {
    while (top && val[stk[top]] <= val[i]) {
      rc[stk[top]] = i;
      top--;
    }
    lc[i] = stk[top], stk[++top] = i;
  }
  while (top) rc[stk[top--]] = n + 1;
  for (int i = 1; i <= n; i++) v1[lc[i]].push_back(i);
  for (int i = 1; i <= q; i++) v2[e[i].l].push_back(i);
  Seg::build(1, 1, n, 1);
  for (int i = 1; i <= n; i++) {
    for (unsigned int j = 0; j < v1[i - 1].size(); j++)
      Seg::modify(v1[i - 1][j], 1, n, 1);
    for (unsigned int j = 0; j < v2[i].size(); j++) {
      int x = v2[i][j];
      ans[x] = -Seg::query(e[x].l, e[x].r, i, 1, n, 1);
    }
  }
  for (int i = 0; i <= n; i++) v1[i].clear(), v2[i].clear();
  for (int i = 1; i <= n; i++) v1[rc[i]].push_back(i);
  for (int i = 1; i <= q; i++) v2[e[i].r].push_back(i);
  Seg::build(2, 1, n, 1);
  for (int i = n; i >= 1; i--) {
    for (unsigned int j = 0; j < v1[i + 1].size(); j++)
      Seg::modify(v1[i + 1][j], 1, n, 1);
    for (unsigned int j = 0; j < v2[i].size(); j++) {
      int x = v2[i][j];
      ans[x] += Seg::query(e[x].l, e[x].r, i, 1, n, 1);
    }
  }
  for (int i = 1; i <= q; i++)
    write(ans[i] + e[i].r - e[i].l + 1), putchar(' ');
  return 0;
}
