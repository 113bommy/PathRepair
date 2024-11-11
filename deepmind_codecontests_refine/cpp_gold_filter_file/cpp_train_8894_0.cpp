#include <bits/stdc++.h>
using namespace std;
int n, q, a[100010], m[100010], r[100010];
struct par {
  int l, r, t, v;
  bool operator<(const par &B) const { return l < B.l; }
};
set<par> s;
long long sm[100010 * 20], sr[100010 * 20];
int ls[100010 * 20], rs[100010 * 20], id = 0, rt[100010];
void add_node(int from, int &to, int l, int r, int x, int pos) {
  to = ++id;
  sm[to] = sm[from] + ::m[pos];
  sr[to] = sr[from] + ::r[pos];
  if (l == r) return;
  int mid = l + r >> 1;
  if (x <= mid)
    add_node(ls[from], ls[to], l, mid, x, pos), rs[to] = rs[from];
  else
    add_node(rs[from], rs[to], mid + 1, r, x, pos), ls[to] = ls[from];
}
long long askr(int now, int l, int r, int x) {
  if (!now) return 0;
  if (x == l) return sr[now];
  int mid = l + r >> 1;
  if (x <= mid)
    return askr(ls[now], l, mid, x) + sr[rs[now]];
  else
    return askr(rs[now], mid + 1, r, x);
}
long long askm(int now, int l, int r, int x) {
  if (!now) return 0;
  if (x == r) return sm[now];
  int mid = l + r >> 1;
  if (x >= mid + 1)
    return askm(rs[now], mid + 1, r, x) + sm[ls[now]];
  else
    return askm(ls[now], l, mid, x);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &a[i], &m[i], &r[i]);
    s.insert((par){i, i, 0, 1});
    if (r[i] && m[i])
      add_node(rt[i - 1], rt[i], 0, 100010 - 10, m[i] / r[i], i);
    else
      rt[i] = rt[i - 1];
  }
  scanf("%d", &q);
  for (int i = 1, t, l, r; i <= q; i++) {
    scanf("%d %d %d", &t, &l, &r);
    par p = *(--s.upper_bound((par){l, 0, 0, 0}));
    if (p.l != l) {
      s.erase(p);
      s.insert((par){p.l, l - 1, p.t, p.v});
      s.insert((par){l, p.r, p.t, p.v});
    }
    p = *(--s.upper_bound((par){r, 0, 0, 0}));
    if (p.r != r) {
      s.erase(p);
      s.insert((par){p.l, r, p.t, p.v});
      s.insert((par){r + 1, p.r, p.t, p.v});
    }
    long long ans = 0;
    while (s.lower_bound((par){l, 0, 0, 0}) != s.end() &&
           (p = *s.lower_bound((par){l, 0, 0, 0})).l <= r) {
      if (p.v) {
        ans += min(a[p.l] + 1ll * (t - p.t) * ::r[p.l], (long long)::m[p.l]);
      } else {
        if (t - p.t >= 100010 - 10) {
          ans += sm[rt[p.r]] - sm[rt[p.l - 1]];
        } else {
          long long R = askr(rt[p.r], 0, 100010 - 10, t - p.t) -
                        askr(rt[p.l - 1], 0, 100010 - 10, t - p.t);
          long long M = askm(rt[p.r], 0, 100010 - 10, t - p.t - 1) -
                        askm(rt[p.l - 1], 0, 100010 - 10, t - p.t - 1);
          ans += R * (t - p.t) + M;
        }
      }
      s.erase(p);
    }
    s.insert((par){l, r, t, 0});
    printf("%lld\n", ans);
  }
}
