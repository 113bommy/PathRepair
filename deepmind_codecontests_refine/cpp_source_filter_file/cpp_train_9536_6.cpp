#include <bits/stdc++.h>
using namespace std;
const int MX = 1 << 19;
const int MM = 1000000007;
tuple<int, int, int> D[MX];
pair<int, int> U[MX];
struct node {
  int v, mx;
  long long tot;
};
struct Tree {
  node t[MX * 2];
  void pushdown(int n, long long d) {
    if (n >= MX) return;
    if (t[n].v) {
      t[n * 2].v = t[n * 2 + 1].v = t[n * 2].mx = t[n * 2 + 1].mx = t[n].v;
      t[n * 2].tot = t[n * 2 + 1].tot = (long long)d / 2 * t[n].v;
      t[n].v = 0;
    }
  }
  void update(int l, int r, int v, int n = 1, int s = 0, int e = MX - 1) {
    pushdown(n, e - s + 1);
    if (l <= s && e <= r) {
      t[n].v = t[n].mx = v;
      t[n].tot = (long long)(e - s + 1) * v;
    } else if (r < s || e < l)
      ;
    else {
      int m = (s + e) / 2;
      update(l, r, v, n * 2, s, m);
      update(l, r, v, n * 2 + 1, m + 1, e);
      t[n].v = 0;
      t[n].tot = t[n * 2].tot + t[n * 2 + 1].tot;
      t[n].mx = max(t[n * 2].mx, t[n * 2 + 1].mx);
    }
  }
  int lower_bound(int v, int n = 1, int s = 0, int e = MX - 1) {
    if (s == e) return s;
    pushdown(n, e - s + 1);
    int m = (s + e) / 2;
    if (t[n * 2 + 1].mx >= v)
      return lower_bound(v, n * 2 + 1, m + 1, e);
    else
      return lower_bound(v, n * 2, s, m);
  }
  long long total(int l, int r, int n = 1, int s = 0, int e = MX - 1) {
    pushdown(n, e - s + 1);
    if (l <= s && e <= r)
      return t[n].tot;
    else if (r < s || e < l)
      return 0;
    else {
      int m = (s + e) / 2;
      return total(l, r, n * 2, s, m) + total(l, r, n * 2 + 1, m + 1, e);
    }
  }
} tree;
int main() {
  int N, a, b, c, p, q, r;
  scanf("%d%d%d%d", &N, &p, &q, &r);
  for (int i = 1; i <= N; i++) {
    scanf("%d%d%d", &a, &b, &c);
    D[i] = tie(a, b, c);
  }
  sort(D + 1, D + N + 1);
  U[N + 1] = pair<int, int>(1, 1);
  for (int i = N; i >= 1; i--) {
    tie(a, b, c) = D[i];
    U[i].first = max(U[i + 1].first, b + 1);
    U[i].second = max(U[i + 1].second, c + 1);
  }
  long long ans = 0, prv = 0;
  for (int i = 1; i <= N + 1; i++) {
    int x, y, z;
    tie(x, y, z) = D[i];
    if (i == N + 1) x = p;
    int b = U[i].first, c = U[i].second;
    int t = tree.lower_bound(c);
    long long cur = (long long)(q - b + 1) * (r - c + 1);
    if (b <= t) cur += -tree.total(b, t) + (long long)(t - b + 1) * (c - 1);
    ans += cur * (x - prv);
    prv = x;
    t = tree.lower_bound(z);
    if (t > y) continue;
    tree.update(t, y, z);
  }
  printf("%lld\n", ans);
}
