#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int mm = 2e5 + 10;
ll seg_tree[mm << 2];
ll in[mm];
map<pair<int, int>, int> pre;
ll build(ll node, ll l, ll r) {
  if (l == r) return seg_tree[node] = in[l];
  ll mid = l + r;
  mid >>= 1;
  ll left = build(node << 1, l, mid);
  ll right = build((node << 1) + 1, mid + 1, r);
  return seg_tree[node] = left + right;
}
ll update(ll node, ll l, ll r, ll pos, ll val) {
  if (l == r) {
    if (l == pos) seg_tree[node] += val;
    return max(0LL, seg_tree[node]);
  }
  ll mid = l + r;
  mid >>= 1;
  ll left = seg_tree[node << 1];
  if (l <= pos and mid >= pos) left = update(node << 1, l, mid, pos, val);
  ll right = seg_tree[(node << 1) + 1];
  if (pos >= mid + 1 and pos <= r)
    right = update((node << 1) + 1, mid + 1, r, pos, val);
  return seg_tree[node] = max(0LL, left) + max(0LL, right);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> in[i];
  build(1, 0, n - 1);
  int q;
  cin >> q;
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, c--;
    if (pre.count({a, b}) == 0) {
      update(1, 0, n - 1, c, -1);
      pre[{a, b}] = c;
    } else if (c < 0) {
      update(1, 0, n - 1, pre[{a, b}], 1);
      pre.erase({a, b});
    } else {
      update(1, 0, n - 1, pre[{a, b}], 1);
      update(1, 0, n - 1, c, -1);
      pre[{a, b}] = c;
    }
    cout << seg_tree[1] << endl;
  }
}
