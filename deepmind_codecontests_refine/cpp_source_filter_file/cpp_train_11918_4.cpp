#include <bits/stdc++.h>
using namespace std;
const int maxn = 201000;
long long arr[maxn], n, q;
long long d[maxn];
long long l[maxn], r[maxn];
struct node {
 public:
  pair<long long, long long> l, r;
};
node tree[4 * maxn];
node mergef(node a, node b) {
  node c;
  if (a.l.first >= b.l.first) {
    c.l = a.l;
  } else {
    c.l = b.l;
  }
  if (a.r.first >= b.r.first) {
    c.r = a.r;
  } else {
    c.r = b.r;
  }
  return c;
}
void build(int li = 1, int ri = 2 * n, int index = 1) {
  if (li == ri) {
    tree[index].l = make_pair(l[li], li);
    tree[index].r = make_pair(r[li], li);
  } else {
    int mid = (li + ri) / 2;
    build(li, mid, 2 * index);
    build(mid + 1, ri, 2 * index + 1);
    tree[index] = mergef(tree[2 * index], tree[2 * index + 1]);
  }
}
pair<long long, long long> EP;
node query(int ql, int qr, int li = 1, int ri = 2 * n, int index = 1) {
  if (ql > qr) return {EP, EP};
  if (li > qr || ri < ql)
    return {EP, EP};
  else if (li >= ql && ri <= qr)
    return tree[index];
  else {
    int mid = (li + ri) / 2;
    return mergef(query(ql, qr, li, mid, 2 * index),
                  query(ql, qr, mid + 1, ri, 2 * index + 1));
  }
}
long long solve(int li, int ri) {
  node x = query(li, ri);
  if (x.l.second == x.r.second) {
    node y1 = query(li, x.l.second - 1);
    node y2 = query(x.l.second + 1, ri);
    long long yl_val = max(y1.l.first, y2.l.first);
    long long yr_val = max(y1.r.first, y2.r.first);
    return max(x.l.first + yr_val, x.r.first + yl_val);
  } else {
    return x.l.first + x.r.first;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = n + 1; i <= 2 * n; i++) {
    arr[i] = arr[i - n];
    d[i] = d[i - n];
  }
  long long sum = 0LL;
  for (int i = 1; i <= 2 * n; i++) {
    l[i] = 2 * arr[i] - sum;
    r[i] = 2 * arr[i] + sum;
    sum += d[i];
  }
  EP = {INT_MIN, -1};
  build();
  int li, ri;
  while (q--) {
    cin >> li >> ri;
    if (li > ri) {
      swap(li, ri);
      cout << solve(li + 1, ri - 1) << "\n";
    } else {
      int ql = ri + 1;
      int qr = li + n - 1;
      cout << solve(ql, qr) << "\n";
    }
  }
  return 0;
}
