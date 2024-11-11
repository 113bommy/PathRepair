#include <bits/stdc++.h>
using namespace std;
const long dad = 1e6;
int n, m, l = 1, r;
long long k;
long long d[dad], a[dad], b[dad], res, ans[dad], dem[dad];
struct yasu {
  int id, l, r;
} p[dad], c[dad];
bool cmp(yasu u, yasu v) {
  return (u.l / 300 < v.l / 300 || (u.l / 300 == v.l / 300 && u.r < v.r));
}
void update(int u, long long gt1, long long gt2, long long gt3) {
  res += dem[c[u].l] * gt2;
  res += dem[c[u].r] * gt3;
  dem[c[u].id] += gt1;
}
void input() {
  scanf("%d%lld", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &d[i]);
    d[i] = d[i] == 1 ? 1 : -1;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    a[i] = a[i - 1] + a[i] * d[i];
  }
  for (int i = 0; i <= n; ++i) {
    b[++*b] = a[i];
    b[++*b] = a[i] + k;
    b[++*b] = a[i] - k;
  }
  sort(b + 1, b + *b + 1);
  *b = unique(b + 1, b + *b + 1) - b - 1;
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &p[i].l, &p[i].r);
    --p[i].l;
    p[i].id = i;
  }
  for (int i = 1; i <= n; ++i) {
    c[i].id = lower_bound(b + 1, b + *b + 1, a[i]) - b;
    c[i].l = lower_bound(b + 1, b + *b + 1, a[i] - k) - b;
    c[i].r = lower_bound(b + 1, b + *b + 1, a[i] + k) - b;
  }
  sort(p + 1, p + m + 1, cmp);
  for (int i = 1; i <= m; ++i) {
    int l1 = p[i].l;
    int r1 = p[i].r;
    while (l < l1) {
      --dem[c[l].id];
      res -= dem[c[l].r];
      ++l;
    }
    while (l > l1) {
      --l;
      res += dem[c[l].r];
      ++dem[c[l].id];
    }
    while (r < r1) {
      ++r;
      res += dem[c[r].l];
      ++dem[c[r].id];
    }
    while (r > r1) {
      --dem[c[r].id];
      res -= dem[c[r].l];
      --r;
    }
    ans[p[i].id] = res;
  }
  for (int i = 1; i <= m; ++i) printf("%lld\n", ans[i]);
}
void output() {}
int main() {
  input();
  output();
  return 0;
}
