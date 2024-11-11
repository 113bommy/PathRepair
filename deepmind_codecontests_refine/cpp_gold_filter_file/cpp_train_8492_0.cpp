#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int root[N], a[N], cnt, pre[N], n;
struct node {
  int l, r, sum;
} T[N * 40];
void update(int l, int r, int &x, int y, int pos, int val) {
  T[++cnt] = T[y], T[x = cnt].sum += val;
  if (l == r) return;
  int mid = l + r >> 1;
  if (mid >= pos)
    update(l, mid, T[x].l, T[y].l, pos, val);
  else
    update(mid + 1, r, T[x].r, T[y].r, pos, val);
}
int query(int l, int r, int x, int k) {
  if (l == r) return l;
  int mid = l + r >> 1;
  if (k <= T[T[x].l].sum)
    return query(l, mid, T[x].l, k);
  else
    return query(mid + 1, r, T[x].r, k - T[T[x].l].sum);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = n; i > 0; i--) {
    update(1, n, root[i], root[i + 1], i, 1);
    if (pre[a[i]]) update(1, n, root[i], root[i], pre[a[i]], -1);
    pre[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    int now = 1, ans = 0;
    while (now <= n) {
      if (T[root[now]].sum > i)
        now = query(1, n, root[now], i + 1);
      else
        now = n + 1;
      ans++;
    }
    printf("%d%c", ans, " \n"[i == n]);
  }
  return 0;
}
