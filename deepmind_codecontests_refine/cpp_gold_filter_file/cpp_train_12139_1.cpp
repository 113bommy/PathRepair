#include <bits/stdc++.h>
using namespace std;
int sum[100010 * 30], ls[100010 * 30], rs[100010 * 30];
int a[100010], b[100010], root[100010], h[100010];
int n, m, tot, cnt, k;
vector<int> v[100010];
void insert(int last, int &x, int y, int l, int r) {
  sum[x = ++tot] = sum[last] + 1;
  ls[x] = ls[last];
  rs[x] = rs[last];
  if (l == r) return;
  int mid = l + r >> 1;
  if (y <= mid)
    insert(ls[last], ls[x], y, l, mid);
  else
    insert(rs[last], rs[x], y, mid + 1, r);
}
int ask(int ss, int tt, int l, int r, int y) {
  if (l == r) return sum[tt] - sum[ss];
  int mid = l + r >> 1;
  if (y <= mid)
    return ask(ls[ss], ls[tt], l, mid, y);
  else
    return sum[ls[tt]] - sum[ls[ss]] + ask(rs[ss], rs[tt], mid + 1, r, y);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    v[a[i]].push_back(i);
  }
  h[++cnt] = 0;
  for (int i = 1; i <= 100000; i++) {
    int sz = v[i].size();
    if (sz == 0) continue;
    for (int j = 0; j < sz; j++) {
      if (j - k < 0)
        b[v[i][j]] = 0;
      else
        h[++cnt] = b[v[i][j]] = v[i][j - k];
    }
  }
  sort(h + 1, h + cnt + 1);
  cnt = unique(h + 1, h + cnt + 1) - h - 1;
  for (int i = 1; i <= n; i++) {
    b[i] = lower_bound(h + 1, h + cnt + 1, b[i]) - h;
    insert(root[i - 1], root[i], b[i], 1, cnt);
  }
  int q;
  scanf("%d", &q);
  int last = 0;
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l = (l + last) % n + 1;
    r = (r + last) % n + 1;
    if (l > r) swap(l, r);
    int y = lower_bound(h + 1, h + cnt + 1, l) - h - 1;
    if (y == 0)
      printf("%d\n", last = 0);
    else
      printf("%d\n", last = ask(root[l - 1], root[r], 1, cnt, y));
  }
}
