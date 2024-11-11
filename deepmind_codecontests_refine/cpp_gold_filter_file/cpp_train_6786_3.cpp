#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 7;
long long tag[N << 2], ans[N], res;
pair<long long, pair<long long, long long>> s[N];
vector<pair<long long, pair<long long, long long>>> vu, vd;
long long d[N], tot, n, i, j, k, x, y;
pair<long long, long long> mx[N << 2], tmp;
bool cmpx(pair<long long, pair<long long, long long>> a,
          pair<long long, pair<long long, long long>> b) {
  return a.first < b.first;
}
bool cmpy(pair<long long, pair<long long, long long>> a,
          pair<long long, pair<long long, long long>> b) {
  return a.second.first < b.second.first;
}
long long find(long long x) { return lower_bound(d + 1, d + tot + 1, x) - d; }
void add(long long rt, long long val) {
  mx[rt].first += val;
  tag[rt] += val;
}
void pushdown(long long rt) {
  if (tag[rt])
    add((rt << 1), tag[rt]), add((rt << 1 | 1), tag[rt]), tag[rt] = 0;
}
void update(long long rt) { mx[rt] = max(mx[(rt << 1)], mx[(rt << 1 | 1)]); }
void build(long long rt, long long l, long long r) {
  if (l == r) {
    mx[rt] = make_pair(ans[l], l);
    return;
  }
  long long mid = l + r >> 1;
  build((rt << 1), l, mid);
  build((rt << 1 | 1), mid + 1, r);
  update(rt);
}
void modify(long long rt, long long l, long long r, long long a, long long b,
            long long val) {
  if (a <= l && r <= b) return add(rt, val);
  pushdown(rt);
  long long mid = l + r >> 1;
  if (a <= mid) modify((rt << 1), l, mid, a, b, val);
  if (b > mid) modify((rt << 1 | 1), mid + 1, r, a, b, val);
  update(rt);
}
pair<long long, long long> query(long long rt, long long l, long long r,
                                 long long a, long long b) {
  if (a <= l && r <= b) return mx[rt];
  long long mid = l + r >> 1;
  pushdown(rt);
  pair<long long, long long> res = make_pair(0LL, 0);
  if (a <= mid) res = max(res, query((rt << 1), l, mid, a, b));
  if (b > mid) res = max(res, query((rt << 1 | 1), mid + 1, r, a, b));
  return res;
}
void dfs(long long rt, long long l, long long r) {
  if (l == r) return printf("%lld ", mx[rt].first), void();
  long long mid = l + r >> 1;
  pushdown(rt);
  dfs((rt << 1), l, mid);
  dfs((rt << 1 | 1), mid + 1, r);
}
int32_t main() {
  x = y = (long long)2e9 - 7;
  res = 0;
  for (scanf("%lld", &n), i = 1; i <= n; ++i) {
    scanf("%lld%lld%lld", &s[i].first, &s[i].second.first, &s[i].second.second);
    d[++tot] = s[i].first;
    d[++tot] = s[i].second.first;
    if (s[i].second.first >= s[i].first)
      vu.push_back(s[i]);
    else
      vd.push_back(s[i]);
  }
  sort(d + 1, d + tot + 1);
  tot = unique(d + 1, d + tot + 1) - d - 1;
  sort(vu.begin(), vu.end(), cmpy);
  sort(vd.begin(), vd.end(), cmpx);
  for (auto& x : vu) ans[find(x.second.first)] += x.second.second;
  for (auto& x : vd) ans[find(x.first)] += x.second.second;
  for (i = 1; i <= tot; ++i) ans[i] += ans[i - 1];
  for (i = 1; i <= tot; ++i) ans[i] -= (d[i] - d[1]);
  build(1, 1, tot);
  sort(vu.begin(), vu.end(), cmpx);
  sort(vd.begin(), vd.end(), cmpy);
  for (i = 1, j = k = 0; i <= tot; ++i) {
    tmp = query(1, 1, tot, i, tot);
    if (tmp.first > res) {
      res = tmp.first;
      x = d[i];
      y = d[tmp.second];
    }
    while (j < vu.size() && vu[j].first <= d[i])
      modify(1, 1, tot, find(vu[j].second.first), tot, -vu[j].second.second),
          ++j;
    while (k < vd.size() && vd[k].second.first <= d[i])
      modify(1, 1, tot, find(vd[k].first), tot, -vd[k].second.second), ++k;
    modify(1, 1, tot, 1, tot, d[i + 1] - d[i]);
  }
  printf("%lld\n%lld %lld %lld %lld\n", res, x, x, y, y);
}
