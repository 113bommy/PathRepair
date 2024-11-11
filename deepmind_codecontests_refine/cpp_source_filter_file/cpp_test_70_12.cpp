#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long qpow(long long x, long long a) {
  long long res = x, ret = 1;
  while (a > 0) {
    if ((a & 1) == 1) ret = ret * res % MOD;
    a >>= 1;
    res = res * res % MOD;
  }
  return ret;
}
long long n, q, a[200010], sz_q[200010], sum_q[200010], hsh_q[200010];
vector<pair<pair<long long, long long>, long long> > que;
vector<long long> v;
map<long long, long long> lst;
bool cmp(long long x, long long y) {
  return que[x].first.second < que[y].first.second;
}
pair<pair<long long, long long>, long long> operator+(
    pair<pair<long long, long long>, long long> a,
    pair<pair<long long, long long>, long long> b) {
  return make_pair(
      make_pair(a.first.first + b.first.first, a.first.second + b.first.second),
      (a.second + b.second) % MOD);
}
namespace st {
long long n2 = 1, sz[800010], sum[800010], sqr[800010];
void upd(long long k, long long val) {
  if (val >= 0)
    ++sz[k], sum[k] += val, sqr[k] += val * val;
  else
    --sz[k], sum[k] = sqr[k] = 0;
  while (k > 0) {
    k = (k - 1) / 2;
    sz[k] = sz[k + k + 1] + sz[k + k + 2];
    sum[k] = sum[k + k + 1] + sum[k + k + 2];
    sqr[k] = (sqr[k + k + 1] + sqr[k + k + 2]) % MOD;
  }
}
pair<pair<long long, long long>, long long> qry(long long k, long long lb,
                                                long long ub, long long tlb,
                                                long long tub) {
  if (ub < tlb || tub < lb) return make_pair(make_pair(0, 0), 0);
  if (tlb <= lb && ub <= tub)
    return make_pair(make_pair(sz[k], sum[k]), sqr[k]);
  return qry(k + k + 1, lb, (lb + ub) / 2, tlb, tub) +
         qry(k + k + 2, (lb + ub) / 2 + 1, ub, tlb, tub);
}
}  // namespace st
int main() {
  cin >> n >> q;
  for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
  long long x, y, z;
  for (int qn = 0; qn < q; ++qn) {
    scanf("%lld%lld%lld", &x, &y, &z);
    --x;
    --y;
    que.push_back(make_pair(make_pair(x, y), z));
    v.push_back(qn);
  }
  sort(v.begin(), v.end(), cmp);
  while (st::n2 < n) st::n2 *= 2;
  long long cur = -1;
  for (int i = 0; i < q; ++i) {
    for (int j = cur + 1; j <= que[v[i]].first.second; ++j) {
      if (lst.find(a[j]) != lst.end()) st::upd(lst[a[j]] + st::n2 - 1, -1);
      st::upd(j + st::n2 - 1, a[j]);
      lst[a[j]] = j;
    }
    cur = que[v[i]].first.second;
    pair<pair<long long, long long>, long long> res = st::qry(
        0, 0, st::n2 - 1, que[v[i]].first.first, que[v[i]].first.second);
    sz_q[v[i]] = res.first.first;
    sum_q[v[i]] = res.first.second;
    hsh_q[v[i]] = res.second;
  }
  for (int i = 0; i < q; ++i) {
    long long nn = sz_q[i], d = que[i].second,
              bas = (sum_q[i] * 2LL * qpow(nn, MOD - 2) % MOD -
                     (nn - 1) * d % MOD + MOD) %
                    MOD * qpow(2, MOD - 2) % MOD,
              val = (bas * bas % MOD * nn % MOD +
                     (nn + nn - 1) * nn % MOD * (nn - 1) % MOD *
                         qpow(6, MOD - 2) % MOD * d % MOD * d % MOD +
                     (nn - 1) * nn / 2 % MOD * 2LL * bas % MOD * d % MOD) %
                    MOD;
    puts(val == hsh_q[i] ? "Yes" : "No");
  }
  return 0;
}
