#include <bits/stdc++.h>
using namespace std;
pair<int, int> tree[4200000 + 7];
int total[4200000 + 7], id;
int add(int nd, int l, int r, int tid) {
  int new_id = ++id;
  if (l == r) {
    tree[new_id] = make_pair(-1, -1);
    total[new_id] = 1;
    return new_id;
  }
  int mid = (l + r) / 2, lc = tree[nd].first, rc = tree[nd].second;
  tree[new_id] = tree[nd];
  total[new_id] = total[nd];
  if (tid <= mid)
    tree[new_id].first = add(lc, l, mid, tid);
  else
    tree[new_id].second = add(rc, mid + 1, r, tid);
  total[new_id] = total[tree[new_id].first] + total[tree[new_id].second];
  return new_id;
}
int build(int l, int r) {
  int nid = ++id;
  if (l == r) {
    tree[nid] = make_pair(-1, -1);
    total[nid] = 0;
    return nid;
  }
  int mid = (l + r) / 2;
  tree[nid].first = build(l, mid);
  tree[nid].second = build(mid + 1, r);
  total[nid] = 0;
  return nid;
}
int query(int n1, int n2, int l, int r, int ql, int qr) {
  if (r < ql || l > qr || qr < ql) return 0;
  if (l >= ql && r <= qr) return total[n1] - total[n2];
  int mid = (l + r) / 2;
  return query(tree[n1].first, tree[n2].first, l, mid, ql, qr) +
         query(tree[n1].second, tree[n2].second, mid + 1, r, ql, qr);
}
int root[200000 + 7];
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  int a, r1, c1, r2, c2;
  root[0] = build(1, n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    root[i] = add(root[i - 1], 1, n, a);
  }
  long long total = (1LL * n * (n - 1)) / 2LL, ans, tp;
  while (q--) {
    scanf("%d %d %d %d", &c1, &r1, &c2, &r2);
    ans = total;
    tp = r1 - 1;
    ans -= (tp * (tp - 1)) / 2LL;
    tp = n - r2;
    ans -= (tp * (tp - 1)) / 2LL;
    tp = c1 - 1;
    ans -= (tp * (tp - 1)) / 2LL;
    tp = n - c2;
    ans -= (tp * (tp - 1)) / 2LL;
    tp = query(root[n], root[c2], 1, n, r2 + 1, n);
    ans += (tp * (tp - 1)) / 2LL;
    tp = query(root[n], root[c2], 1, n, 1, r1 - 1);
    ans += (tp * (tp - 1)) / 2LL;
    tp = query(root[c1 - 1], root[0], 1, n, r2 + 1, n);
    ans += (tp * (tp - 1)) / 2LL;
    tp = query(root[c1 - 1], root[0], 1, n, 1, r1 - 1);
    ans += (tp * (tp - 1)) / 2LL;
    printf("%lld\n", ans);
  }
  return 0;
}
