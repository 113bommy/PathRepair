#include <bits/stdc++.h>
using namespace std;
long long int total[200005], tree[2][4 * 200005];
void update(long long int id, long long int node, long long int a,
            long long int b, long long int ind, long long int val) {
  if (a > b || a > ind || b < ind) return;
  if (a == b) {
    tree[id][node] = val;
    return;
  }
  long long int mid = (a + b) / 2;
  if (ind <= mid)
    update(id, 2 * node, a, mid, ind, val);
  else
    update(id, 2 * node + 1, mid + 1, b, ind, val);
  tree[id][node] = tree[id][2 * node] + tree[id][2 * node + 1];
}
long long int query(long long int id, long long int node, long long int a,
                    long long int b, long long int l, long long int r) {
  if (a > b || a > r || b < l) return 0;
  if (a >= l && b <= r) return tree[id][node];
  long long int mid = (a + b) / 2;
  return query(id, 2 * node, a, mid, l, r) +
         query(id, 2 * node + 1, mid + 1, b, l, r);
}
int main() {
  ios::sync_with_stdio(false);
  ;
  cin.tie(0);
  ;
  long long int i, j, n, q, A, B, ind, val, type, ans, k;
  cin >> n >> k >> A >> B >> q;
  while (q--) {
    cin >> type;
    if (type == 1) {
      cin >> ind >> val;
      total[ind] += val;
      update(1, 1, 1, n, ind, min(total[ind], B));
      update(2, 1, 1, n, ind, min(total[ind], A));
    } else {
      cin >> ind;
      ans = query(1, 1, 1, n, 1, ind - 1);
      ans += query(2, 1, 1, n, ind + k, n);
      cout << ans << "\n";
    }
  }
  return 0;
}
