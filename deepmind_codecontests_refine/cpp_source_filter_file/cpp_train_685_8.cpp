#include <bits/stdc++.h>
using namespace std;
const long long N = 100010;
long long n, m, w[N], cnt = 0;
set<long long> s[N];
set<long long>::iterator it;
struct qst {
  long long opt, x, y, w, t;
} q[N * 8], tmp[N * 8];
long long ans[N];
inline bool cmpt(qst x, qst y) { return x.t < y.t; }
long long tree[N];
inline long long lowbit(long long x) { return x & (-x); }
inline void add(long long p, long long x) {
  while (p <= n) tree[p] += x, p += lowbit(p);
}
inline long long query(long long p) {
  long long ans = 0;
  while (p) ans += tree[p], p -= lowbit(p);
  return ans;
}
inline void solve(long long l, long long r) {
  if (l == r) return;
  long long mid = (l + r) >> 1;
  solve(l, mid);
  solve(mid + 1, r);
  for (long long i = l, j = l, k = mid + 1; i <= r; ++i) {
    if (j == mid + 1) {
      if (q[k].opt == 2) {
        ans[q[k].t] += query(n) - query(q[k].y - 1);
      }
      tmp[i] = q[k++];
      continue;
    }
    if (k == r + 1) {
      if (q[j].opt == 1) add(q[j].y, q[j].w);
      tmp[i] = q[j++];
      continue;
    }
    if (q[j].x <= q[k].x) {
      if (q[j].opt == 1) add(q[j].y, q[j].w);
      tmp[i] = q[j++];
    } else {
      if (q[k].opt == 2) {
        ans[q[k].t] += query(n) - query(q[k].y - 1);
      }
      tmp[i] = q[k++];
    }
  }
  for (long long i = l; i <= mid; ++i)
    if (q[i].opt == 1) add(q[i].y, -q[i].w);
  for (long long i = l; i <= r; ++i) q[i] = tmp[i];
}
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= n; ++i) scanf("%lld", &w[i]);
  for (long long i = 1; i <= n; ++i) s[w[i]].insert(i);
  for (long long i = 1; i <= n; ++i) {
    it = s[w[i]].lower_bound(i);
    if (it == s[w[i]].begin()) continue;
    it--;
    long long pre = (*it);
    q[++cnt] = qst{1, i, pre, i - pre, 0};
  }
  for (long long i = 1; i <= m; ++i) {
    long long a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a == 1) {
      it = s[w[b]].lower_bound(b);
      long long pre = 0, nxt = 0;
      if (it != s[w[b]].begin()) {
        --it;
        pre = (*it);
        q[++cnt] = {1, b, pre, pre - b, i};
      }
      it = s[w[b]].lower_bound(b);
      ++it;
      if (it != s[w[b]].end()) {
        nxt = (*it);
        q[++cnt] = {1, nxt, b, b - nxt, i};
      }
      if (pre && nxt) q[++cnt] = {1, nxt, pre, nxt - pre, i};
      pre = nxt = 0;
      s[w[b]].erase(b);
      w[b] = c;
      s[c].insert(b);
      it = s[c].lower_bound(b);
      if (it != s[w[b]].begin()) {
        --it;
        pre = (*it);
        q[++cnt] = {1, b, pre, b - pre, i};
      }
      it = s[c].lower_bound(b);
      ++it;
      if (it != s[c].end()) {
        nxt = (*it);
        q[++cnt] = {1, nxt, b, nxt - b, i};
      }
      if (pre && nxt) q[++cnt] = {1, nxt, pre, pre - nxt, i};
    } else
      q[++cnt] = {2, c, b, 0, i};
  }
  solve(1, cnt);
  sort(q + 1, q + cnt + 1, cmpt);
  for (long long i = 1; i <= cnt; ++i)
    if (q[i].opt == 2) printf("%lld\n", ans[q[i].t]);
  return 0;
}
