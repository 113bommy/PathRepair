#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 4e18;
const long double pai = acos(-1);
long long n;
long long a[200009], val[200009], p[200009];
long long crnt[200009];
long long tree[800009], lzy[800009];
void build(long long node, long long l, long long r) {
  if (l == r) {
    tree[node] = crnt[l];
    return;
  }
  build(node * 2, l, (l + r) / 2);
  build(node * 2 + 1, (l + r) / 2 + 1, r);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
void lzyUPD(long long node, long long l, long long r) {
  tree[node] += lzy[node];
  if (l != r) {
    lzy[node * 2] += lzy[node];
    lzy[node * 2 + 1] += lzy[node];
  }
  lzy[node] = 0;
}
void upd(long long node, long long l, long long r, long long s, long long e,
         long long x) {
  if (l > r) return;
  lzyUPD(node, l, r);
  if (s > r || e < l) return;
  if (s <= l && e >= r) {
    lzy[node] += x;
    lzyUPD(node, l, r);
    return;
  }
  upd(node * 2, l, (l + r) / 2, s, e, x);
  upd(node * 2 + 1, (l + r) / 2 + 1, r, s, e, x);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
long long query(long long node, long long l, long long r, long long s,
                long long e) {
  lzyUPD(node, l, r);
  if (s > r || e < l) return inf;
  if (s <= l && e >= r) return tree[node];
  return min(query(node * 2, l, (l + r) / 2, s, e),
             query(node * 2 + 1, (l + r) / 2 + 1, r, s, e));
}
int main() {
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i], p[a[i]] = i;
  for (long long i = 0; i < n; i++) cin >> val[i];
  long long sum = 0, xxx = val[p[1]];
  for (long long i = 0; i < n; i++) {
    if (a[i] == 1)
      xxx = 0;
    else
      sum += val[i];
    crnt[i] = xxx + sum;
  }
  build(1, 0, n - 1);
  long long ans = query(1, 0, n - 1, 0, n - 2);
  ans = min(ans, min(a[0], a[n - 1]));
  for (long long i = 2; i <= n; i++) {
    long long x = p[i];
    upd(1, 0, n - 1, x, n - 1, -val[x]);
    upd(1, 0, n - 1, 0, x - 1, val[x]);
    ans = min(ans, query(1, 0, n - 1, 0, n - 2));
  }
  cout << ans << endl;
}
