#include <bits/stdc++.h>
using namespace std;
int tree[400005], A[400005], i, l[100005], r[100005], v[100005], ans[100005], n,
    m, dpl[100005], dpr[100005], j;
void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = A[start];
  } else {
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
  }
}
void update(int node, int start, int end, int idx, int val) {
  if (start == end) {
    A[idx] = val;
    tree[node] = val;
  } else {
    int mid = (start + end) / 2;
    if (start <= idx and idx <= mid) {
      update(2 * node, start, mid, idx, val);
    } else {
      update(2 * node + 1, mid + 1, end, idx, val);
    }
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
  }
}
int query(int node, int start, int end, int l, int r) {
  if (r < start or end < l) {
    return 0;
  }
  if (l <= start and end <= r) {
    return tree[node];
  }
  int mid = (start + end) / 2;
  int p1 = query(2 * node, start, mid, l, r);
  int p2 = query(2 * node + 1, mid + 1, end, l, r);
  return max(p1, p2);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    v[l[i]]++;
    v[r[i] + 1]--;
  }
  for (i = 1; i <= m; i++) {
    ans[i] = ans[i - 1] + v[i];
  }
  build(1, 0, n);
  for (i = 1; i <= m; i++) {
    dpl[i] = max(1, 1 + query(1, 0, n, 0, ans[i]));
    update(1, 0, n, ans[i], dpl[i]);
  }
  for (i = 0; i <= n; i++) {
    A[i] = 0;
  }
  build(1, 0, n);
  for (i = m; i >= 1; i--) {
    dpr[i] = max(1, 1 + query(1, 0, n, 0, ans[i]));
    update(1, 0, n, ans[i], dpr[i]);
  }
  int res = 0;
  for (i = 1; i <= m; i++) {
    res = max(res, dpl[i] + dpr[i] - 1);
  }
  cout << res;
}
