#include <bits/stdc++.h>
using namespace std;
int n, i, j, m, a[110001], ma[800001], lm[110001], rm[110001], own[110001], q,
    l, r, b[110001];
long long ans;
int query(int x, int l, int r, int a) {
  int mid = l + r >> 1;
  if (ma[x] < a) return 0;
  if (l >= r) return l;
  if (ma[x * 2 + 1] >= a)
    return query(x * 2 + 1, mid + 1, r, a);
  else
    return query(x * 2, l, mid, a);
}
int query1(int x, int l, int r, int a) {
  int mid = l + r >> 1;
  if (l >= r) return l;
  if (ma[x * 2] > a)
    query1(x * 2, l, mid, a);
  else
    query1(x * 2 + 1, mid + 1, r, a);
}
void modify(int x, int l, int r, int a, int b) {
  int mid = l + r >> 1;
  if (l == r) {
    ma[x] = b;
    return;
  }
  if (a <= mid)
    modify(x * 2, l, mid, a, b);
  else
    modify(x * 2 + 1, mid + 1, r, a, b);
  ma[x] = max(ma[x * 2], ma[x * 2 + 1]);
}
int main() {
  scanf("%d%d", &n, &q);
  for (i = 1; i <= n; i++) scanf("%d", &b[i]);
  n--;
  for (i = 1; i <= n; i++) {
    a[i] = abs(b[i] - b[i + 1]);
  }
  for (i = 1; i <= n; i++) {
    lm[i] = query(1, 1, n, a[i]);
    if (a[lm[i]] <= a[i]) lm[i] = 0;
    modify(1, 1, n, i, a[i]);
  }
  memset(ma, 0, sizeof(ma));
  for (i = n; i >= 1; i--) {
    rm[i] = query1(1, 1, n, a[i]);
    if (a[rm[i]] <= a[i]) rm[i] = n + 1;
    modify(1, 1, n, i, a[i]);
  }
  for (i = 1; i <= q; i++) {
    ans = 0;
    scanf("%d%d", &l, &r);
    r--;
    for (j = l; j <= r; j++) {
      long long t1 = j - max(l - 1, lm[j]), t2 = min(rm[j], r + 1) - j,
                t3 = a[j];
      ans += t1 * t2 * t3;
    }
    printf("%I64d\n", ans);
  }
}
