#include <bits/stdc++.h>
using namespace std;
static constexpr int64_t inf = 0x3f3f3f3f3f3f3f3f;
static constexpr int Maxn = 3e5 + 5, LOG = 20;
int n, q, k, N, Lg2[Maxn];
int64_t a[Maxn], ans[Maxn], St[LOG][Maxn];
inline int64_t ask(int l, int r) {
  int K = Lg2[r - l + 1];
  return min(St[K][l], St[K][r - (1 << K) + 1]);
}
struct Query {
  int l, r, id;
  Query() = default;
  Query(int l, int r, int id) : l(l), r(r), id(id) {}
  friend bool operator<(const Query &lhs, const Query &rhs) {
    return lhs.l != rhs.l ? lhs.l > rhs.l : lhs.r < rhs.r;
  }
};
vector<Query> Q[Maxn];
struct node {
  int len;
  int64_t val, sum;
  node() = default;
  node(int l, int64_t v, int64_t s) : len(l), val(v), sum(s) {}
} stk[Maxn];
int lstk[Maxn];
int top;
void modify(int64_t v) {
  int len, slen;
  int64_t sum;
  for (len = 1; top && stk[top].val >= v;) len += stk[top--].len;
  sum = (top ? stk[top].sum : 0) + len * v;
  slen = (top ? lstk[top] : 0) + len;
  stk[++top] = node(len, v, sum);
  lstk[top] = slen;
}
int64_t query(int l) {
  int length = lstk[top];
  l = length - l;
  int p = upper_bound(lstk + 1, lstk + top + 1, l) - lstk - 1;
  int64_t ans = (p ? stk[p].sum : 0) + stk[p + 1].val * (l - lstk[p]);
  return stk[top].sum - ans;
}
int main(void) {
  scanf("%d%d%d", &n, &q, &k);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  Lg2[0] = -1;
  for (int i = 1; i <= n; ++i) Lg2[i] = Lg2[i >> 1] + 1;
  for (int i = 1; i <= n; ++i) St[0][i] = a[i];
  for (int j = 1; j < LOG; ++j)
    for (int i = 1; i + (1 << j) - 1 <= n; ++i)
      St[j][i] = min(St[j - 1][i], St[j - 1][i + (1 << j - 1)]);
  for (int i = 1, l, r; i <= q; ++i) {
    scanf("%d%d", &l, &r);
    r = l + (r - l) / k * k;
    ans[i] += a[l], l += k;
    if (l <= r) Q[l % k].push_back(Query(l / k, r / k, i));
  }
  for (int mod = 0; mod < k; ++mod) {
    sort(Q[mod].begin(), Q[mod].end());
    for (top = N = 0; N * k + mod <= n; ++N)
      ;
    for (int j = N - 1, i = 0; j >= 0 && i < (int)Q[mod].size(); --j) {
      modify(ask(max(j * k + mod, 1), min((j + 1) * k + mod, n)));
      for (; i < (int)Q[mod].size() && Q[mod][i].l > j; ++i) {
        const auto &[l, r, id] = Q[mod][i];
        ans[id] += query(r - l + 1);
      }
    }
  }
  for (int i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
  exit(EXIT_SUCCESS);
}
