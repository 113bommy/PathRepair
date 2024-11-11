#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11;
int n, tot = 1;
long long s, X[N], Y[N];
struct fac {
  long long v, c;
} a[N];
struct dic {
  int l, r, id;
} dl[N];
bool cmp(fac x, fac y) { return x.c == y.c ? x.v > y.v : x.c < y.c; }
long long calx(int id, long long y) {
  return (y - Y[id] - 1) / a[id].v + 1 + X[id];
}
long long calb(int id, int p) {
  return (((calx(id, a[p].c) - X[id]) * a[id].v + Y[id]) - a[p].c) -
         calx(id, a[p].c) * a[p].v;
}
int main() {
  cin >> n >> s;
  int x, y;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    a[i] = (fac){x, y};
  }
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 2; i <= n; i++) {
    if (a[i].c == a[i - 1].c) continue;
    if (a[i].v <= a[tot].v) continue;
    a[++tot] = a[i];
  }
  int hd = 0, tl = 1;
  dl[tl] = (dic){2, tot, 1};
  long long ans = calx(1, s);
  for (int i = 2; i <= tot; i++) {
    while (hd <= tl && dl[hd].r < i) hd++;
    int id = dl[hd].id;
    X[i] = calx(id, a[i].c);
    Y[i] = (X[i] - X[id]) * a[id].v + Y[id] - a[i].c;
    ans = min(ans, calx(i, s));
    int l = n + 1, r = n;
    while (hd <= tl && dl[tl].l > i &&
           calb(i, dl[tl].l) > calb(dl[tl].id, dl[tl].l)) {
      l = dl[tl--].l;
    }
    int L = max(i + 1, dl[tl].l + 1), R = dl[tl].r;
    while (L <= R) {
      int mid = L + R >> 1;
      if (calb(i, mid) > calb(dl[tl].id, mid)) {
        R = mid - 1;
        l = min(l, mid);
      } else
        L = mid + 1;
    }
    if (l <= r) {
      dl[tl].r = l - 1;
      dl[++tl] = (dic){l, r, i};
    }
  }
  printf("%lld\n", ans);
  return 0;
}
