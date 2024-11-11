#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int root[MAXN * 3], n;
struct persistent_segmentTree {
  vector<int> L, R, tree;
  int id;
  void init(int n) {
    tree.resize(45 * n, 0);
    R.resize(45 * n, 0);
    L.resize(45 * n, 0);
    id = 0;
  }
  int update(int prv, int st, int ed, int pos, int val) {
    if (pos > ed || pos < st) return prv;
    int cur = ++id;
    if (st == ed) {
      tree[cur] = tree[prv] + val;
      return cur;
    }
    int mid = (st + ed) / 2;
    L[cur] = update(L[prv], st, mid, pos, val);
    R[cur] = update(R[prv], mid + 1, ed, pos, val);
    tree[cur] = tree[L[cur]] + tree[R[cur]];
    return cur;
  }
  int query(int node, int st, int ed, int l, int r) {
    if (st > r || ed < l) return 0;
    if (st >= l && ed <= r) return tree[node];
    return query(L[node], st, (st + ed) / 2, l, r) +
           query(R[node], (st + ed) / 2 + 1, ed, l, r);
  }
  int kth(int node, int st, int ed, int k) {
    if (tree[node] < k) return n + 1;
    if (st == ed) return st;
    if (tree[L[node]] >= k)
      return kth(L[node], st, (st + ed) / 2, k);
    else
      return kth(R[node], (st + ed) / 2 + 1, ed, k - tree[L[node]]);
  }
} pst;
int arr[MAXN], nxt[MAXN];
int main() {
  cin >> n;
  pst.init(n);
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = n; i >= 1; i--) {
    root[i] = pst.update(root[i + 1], 1, n, i, 1);
    if (nxt[arr[i]]) {
      root[i] = pst.update(root[i], 1, n, nxt[arr[i]], -1);
    }
    nxt[arr[i]] = i;
  }
  for (int k = 1; k <= n; k++) {
    int st = 1;
    int ans = 0;
    while (st <= n) {
      ans++;
      st = pst.kth(root[st], 1, n, k + 1);
    }
    cout << ans << ' ';
  }
  return 0;
}
