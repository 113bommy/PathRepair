#include <bits/stdc++.h>
using namespace std;
const int N = 200004;
struct arr {
  int l, r, c, id;
} Q[N];
bool cmp(const arr &a, const arr &b) {
  return (a.c != b.c) ? (a.c < b.c) : (a.r < b.r);
}
int f[1000004], a[N];
long long qry[N];
int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  int block = sqrt(n);
  int i;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= t; i++) {
    scanf("%d %d", &Q[i].l, &Q[i].r);
    Q[i].c = Q[i].l / block;
    Q[i].id = i;
  }
  sort(Q + 1, Q + t + 1, cmp);
  int ans = 0;
  int curl = 0, curr = 0;
  for (i = 1; i <= t; i++) {
    while (curr < Q[i].r)
      curr++, ans += a[curr] * 1LL * (f[a[curr]] << 1 | 1), f[a[curr]]++;
    while (curl > Q[i].l)
      curl--, ans += a[curl] * 1LL * (f[a[curl]] << 1 | 1), f[a[curl]]++;
    while (curl < Q[i].l)
      f[a[curl]]--, ans -= a[curl] * 1LL * (f[a[curl]] << 1 | 1), curl++;
    while (curr > Q[i].r)
      f[a[curr]]--, ans -= a[curr] * 1LL * (f[a[curr]] << 1 | 1), curr--;
    qry[Q[i].id] = ans;
  }
  for (i = 1; i <= t; i++) printf("%I64d\n", qry[i]);
  return 0;
}
