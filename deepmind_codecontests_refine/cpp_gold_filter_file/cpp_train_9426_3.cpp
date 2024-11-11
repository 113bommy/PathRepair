#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int sumv[MAXN * 4];
void update(int x, int l, int r, int pos, int val) {
  if (l == r) {
    sumv[x] += val;
  } else {
    int lc = x * 2, rc = x * 2 + 1, mid = l + r >> 1;
    if (pos <= mid)
      update(lc, l, mid, pos, val);
    else
      update(rc, mid + 1, r, pos, val);
    sumv[x] = sumv[lc] + sumv[rc];
  }
}
int query(int x, int l, int r) {
  if (l == r)
    return l;
  else {
    int lc = x * 2, rc = x * 2 + 1, mid = l + r >> 1;
    if (sumv[rc])
      return query(rc, mid + 1, r);
    else
      return query(lc, l, mid);
  }
}
int num[MAXN], n, m;
int a[MAXN], b[MAXN];
void add(int x) {
  if (num[x] == 1) update(1, 1, m, x, -1);
  num[x]++;
  if (num[x] == 1) update(1, 1, m, x, 1);
}
void del(int x) {
  if (num[x] == 1) update(1, 1, m, x, -1);
  num[x]--;
  if (num[x] == 1) update(1, 1, m, x, 1);
}
int main() {
  int k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
  sort(b + 1, b + n + 1);
  m = unique(b + 1, b + n + 1) - (b + 1);
  for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
  for (int i = 1; i <= k; i++) add(a[i]);
  int l = 1, r = k;
  if (sumv[1] == 0)
    printf("Nothing\n");
  else
    printf("%d\n", b[query(1, 1, m)]);
  for (; l + 1 <= n - k + 1;) {
    add(a[++r]);
    del(a[l++]);
    if (sumv[1] == 0)
      printf("Nothing\n");
    else
      printf("%d\n", b[query(1, 1, m)]);
  }
  return 0;
}
