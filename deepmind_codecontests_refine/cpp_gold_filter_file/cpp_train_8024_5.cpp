#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long sum[N << 2];
int a[N], x;
vector<pair<int, int> > pr[N << 2], sb[N << 2];
struct node {
  vector<pair<int, int> > pr, sb;
  long long num;
};
void push_up(int rt, int l, int r) {
  pr[rt] = pr[(rt << 1)];
  sb[rt] = sb[(rt << 1 | 1)];
  for (auto it : pr[(rt << 1 | 1)])
    if (pr[rt].back().second != (pr[rt].back().second | it.second))
      pr[rt].push_back(make_pair(it.first, pr[rt].back().second | it.second));
  for (auto it : sb[(rt << 1)])
    if (sb[rt].back().second != (sb[rt].back().second | it.second))
      sb[rt].push_back(make_pair(it.first, sb[rt].back().second | it.second));
  sum[rt] = sum[(rt << 1)] + sum[(rt << 1 | 1)];
  int mid = l + r >> 1;
  int si = sb[(rt << 1)].size();
  int sz = pr[(rt << 1 | 1)].size();
  int p = 0;
  for (int i = si - 1; i >= 0; i--) {
    while (p < sz &&
           (sb[(rt << 1)][i].second | pr[(rt << 1 | 1)][p].second) < x)
      p++;
    if (p == sz) break;
    int len1, len2;
    if (p == 0)
      len1 = r - mid;
    else
      len1 = r - pr[(rt << 1 | 1)][p].first + 1;
    if (i != si - 1)
      len2 = sb[(rt << 1)][i].first - sb[(rt << 1)][i + 1].first;
    else
      len2 = sb[(rt << 1)][i].first - l + 1;
    sum[rt] += len1 * 1ll * len2;
  }
}
void build(int l, int r, int rt) {
  if (l == r) {
    pr[rt].push_back(make_pair(l, a[l]));
    sb[rt].push_back(make_pair(l, a[l]));
    sum[rt] = a[l] >= x;
    return;
  }
  int mid = l + r >> 1;
  build(l, mid, (rt << 1));
  build(mid + 1, r, (rt << 1 | 1));
  push_up(rt, l, r);
}
void update(int l, int r, int pos, int val, int rt) {
  if (l == r) {
    a[l] = val;
    pr[rt].clear();
    sb[rt].clear();
    pr[rt].push_back(make_pair(l, a[l]));
    sb[rt].push_back(make_pair(l, a[l]));
    sum[rt] = a[l] >= x;
    return;
  }
  int mid = l + r >> 1;
  if (pos <= mid)
    update(l, mid, pos, val, (rt << 1));
  else
    update(mid + 1, r, pos, val, (rt << 1 | 1));
  push_up(rt, l, r);
}
node query(int l, int r, int L, int R, int rt) {
  if (L <= l && r <= R) {
    node p;
    p.pr = pr[rt];
    p.sb = sb[rt];
    p.num = sum[rt];
    return p;
  }
  int mid = l + r >> 1;
  node ans;
  ans.num = -1;
  if (L <= mid) ans = query(l, mid, L, R, (rt << 1));
  if (mid < R) {
    if (ans.num == -1)
      ans = query(mid + 1, r, L, R, (rt << 1 | 1));
    else {
      node res = query(mid + 1, r, L, R, (rt << 1 | 1));
      for (auto it : res.pr)
        if (ans.pr.back().second != (ans.pr.back().second | it.second))
          ans.pr.push_back(
              make_pair(it.first, ans.pr.back().second | it.second));
      for (auto it : ans.sb)
        if (res.sb.back().second != (res.sb.back().second | it.second))
          res.sb.push_back(
              make_pair(it.first, res.sb.back().second | it.second));
      ans.num += res.num;
      int si = ans.sb.size();
      int sz = res.pr.size();
      int p = 0;
      for (int i = si - 1; i >= 0; i--) {
        while (p < sz && (ans.sb[i].second | res.pr[p].second) < x) p++;
        if (p == sz) break;
        int len1, len2;
        if (p == 0)
          len1 = min(R, r) - mid;
        else
          len1 = min(R, r) - res.pr[p].first + 1;
        if (i != si - 1)
          len2 = ans.sb[i].first - ans.sb[i + 1].first;
        else
          len2 = ans.sb[i].first - max(l, L) + 1;
        ans.num += len1 * 1ll * len2;
      }
      ans.sb = res.sb;
    }
  }
  return ans;
}
int main() {
  int n, m;
  scanf("%d %d %d", &n, &m, &x);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  build(1, n, 1);
  while (m--) {
    int op, l, r;
    scanf("%d %d %d", &op, &l, &r);
    if (op == 1)
      update(1, n, l, r, 1);
    else
      printf("%lld\n", query(1, n, l, r, 1).num);
  }
  return 0;
}
