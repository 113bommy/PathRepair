#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
struct pi {
  int le, ri, m;
} pp[maxn << 2];
void build(int tot, int l, int r) {
  pp[tot].le = l;
  pp[tot].ri = r;
  pp[tot].m = 1000000001;
  if (l == r) return;
  build(2 * tot, l, (l + r) / 2);
  build(2 * tot + 1, (l + r) / 2 + 1, r);
}
void merg(int tot, int x, int p) {
  if (pp[tot].le == pp[tot].ri) {
    pp[tot].m = min(pp[tot].m, p);
    return;
  }
  int mid = (pp[tot].le + pp[tot].ri) / 2;
  if (x <= mid)
    merg(2 * tot, x, p);
  else
    merg(2 * tot + 1, x, p);
  pp[tot].m = min(pp[2 * tot].m, pp[2 * tot + 1].m);
}
int query(int tot, int l, int r) {
  if (pp[tot].le >= l && pp[tot].ri <= r) {
    return pp[tot].m;
  }
  int s = 1000000001;
  int mid = (pp[tot].le + pp[tot].ri) / 2;
  if (l <= mid) s = min(s, query(2 * tot, l, r));
  if (r > mid) s = min(s, query(2 * tot + 1, l, r));
  return s;
}
struct ppi {
  int x;
  int p;
} p1[maxn];
int cmp(ppi a, ppi b) {
  if (a.x != b.x) return a.x < b.x;
  return a.p < b.p;
}
int main() {
  int i, n, m, d;
  cin >> d >> m >> n;
  p1[1].x = 0;
  p1[1].p = 1000000001;
  n += 2;
  p1[n].x = d;
  p1[n].p = 1000000001;
  for (i = 2; i <= n - 1; i++) {
    scanf("%d%d", &p1[i].x, &p1[i].p);
  }
  sort(p1 + 1, p1 + n + 1, cmp);
  build(1, 1, n);
  for (i = 1; i <= n; i++) merg(1, i, p1[i].p);
  int f = 0;
  for (i = 2; i <= n; i++) {
    if (p1[i].x - p1[i - 1].x > m) {
      f = 1;
    }
  }
  if (f) {
    printf("-1\n");
    return 0;
  }
  int re = 1, te = 1;
  long long s = 0;
  int q = n;
  while (te < n) {
    while (p1[te + 1].x <= q) {
      te++;
      continue;
    }
    while (q < p1[te + 1].x) {
      int p = query(1, re, te);
      if (p == p1[re].p) {
        if (p1[re].x + m >= p1[te + 1].x) {
          s += (long long)(p1[te + 1].x - q) * p1[re].p;
          break;
        } else {
          s += (long long)(m - q + p1[re].x) * p1[re].p;
          q = p1[re].x + m;
          re++;
          continue;
        }
      } else {
        re++;
        continue;
      }
    }
    q = p1[te + 1].x;
    te++;
  }
  cout << s << endl;
}
