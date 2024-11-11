#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e6;
long long n, K, d, a[200010];
map<long long, long long> mp;
struct trnode {
  long long lc, rc, c, u;
} tr[400010];
long long tot = 0;
void pushdown(long long x) {
  long long lc = tr[x].lc, rc = tr[x].rc, c = tr[x].u;
  tr[x].u = 0;
  tr[lc].c += c;
  tr[rc].c += c;
  tr[lc].u += c;
  tr[rc].u += c;
}
void change(long long x, long long l, long long r, long long fl, long long fr,
            long long c, long long op) {
  if (l == fl && r == fr) {
    if (op)
      tr[x].c = c;
    else
      tr[x].c += c, tr[x].u += c;
    return;
  }
  long long mid = (l + r) / 2;
  if (tr[x].u) pushdown(x);
  if (fr <= mid)
    change(tr[x].lc, l, mid, fl, fr, c, op);
  else if (fl > mid)
    change(tr[x].rc, mid + 1, r, fl, fr, c, op);
  else
    change(tr[x].lc, l, mid, fl, mid, c, op),
        change(tr[x].rc, mid + 1, r, mid + 1, fr, c, op);
  tr[x].c = min(tr[tr[x].lc].c, tr[tr[x].rc].c);
}
long long bt(long long l, long long r) {
  long long x = ++tot;
  tr[x].c = inf;
  if (l != r) {
    long long mid = (l + r) / 2;
    tr[x].lc = bt(l, mid);
    tr[x].rc = bt(mid + 1, r);
  }
  return x;
}
long long findans(long long x, long long l, long long r) {
  if (l == r) return tr[x].c <= K ? l : inf;
  if (tr[x].u) pushdown(x);
  long long mid = (l + r) / 2;
  if (tr[tr[x].lc].c <= K) return findans(tr[x].lc, l, mid);
  return findans(tr[x].rc, mid + 1, r);
}
long long L = 1, R = 1, s1[200010], s2[200010], t1 = 0, t2 = 0, la = 1;
int main() {
  scanf("%lld %lld %lld", &n, &K, &d);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  if (d == 0) {
    L = 1;
    R = 1;
    long long l = 1, r = 1;
    for (int i = 2; i <= n; i++) {
      r = i;
      if (a[i] != a[i - 1]) l = i;
      if (r - l + 1 > R - L + 1) L = l, R = r;
    }
    printf("%lld %lld", L, R);
    return 0;
  }
  bt(1, n);
  change(1, 1, n, 1, 1, 0, 1);
  s1[++t1] = 1;
  s2[++t2] = 1;
  mp[a[1]] = 1;
  for (long long i = 2; i <= n; i++) {
    long long tmp = la;
    tmp = max(tmp, mp[a[i]] + 1);
    if ((a[i] - a[i - 1]) % d != 0) tmp = i;
    mp[a[i]] = i;
    if (la < tmp) change(1, 1, n, la, tmp - 1, inf, 0), la = tmp;
    while (t1 && a[s1[t1]] <= a[i])
      change(1, 1, n, s1[t1 - 1] + 1, s1[t1], (a[i] - a[s1[t1]]) / d, 0), t1--;
    while (t2 && a[s2[t2]] >= a[i])
      change(1, 1, n, s2[t2 - 1] + 1, s2[t2], (a[s2[t2]] - a[i]) / d, 0), t2--;
    change(1, 1, n, i, i, 1, 1);
    change(1, 1, n, la, i, -1, 0);
    s1[++t1] = i;
    s2[++t2] = i;
    long long l = findans(1, 1, n), r = i;
    if (r - l + 1 > R - L + 1) L = l, R = r;
  }
  printf("%lld %lld", L, R);
}
