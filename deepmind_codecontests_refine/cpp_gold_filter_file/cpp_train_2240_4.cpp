#include <bits/stdc++.h>
using namespace std;
void MOD(long long &x) {
  if (x >= 1000000007) x -= 1000000007;
  if (x < 0) x += 1000000007;
}
long long arr[1000005 + 5], tree[4 * 1000005 + 5];
int n, q;
void build(int node, int start, int end) {
  if (start > end) return;
  if (start == end)
    tree[node] = 0;
  else {
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}
void update(int node, int start, int end, int ind, int val) {
  if (start > end) return;
  if (start == end) {
    tree[node] = val;
  } else {
    int mid = (start + end) / 2;
    if (ind <= mid)
      update(2 * node, start, mid, ind, val);
    else
      update(2 * node + 1, mid + 1, end, ind, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}
long long query(int node, int start, int end, int l, int r) {
  if (r < start || end < l) return 0;
  if (l <= start && end <= r) return tree[node];
  int mid = (start + end) / 2;
  long long p1 = query(2 * node, start, mid, l, r);
  long long p2 = query(2 * node + 1, mid + 1, end, l, r);
  return (p1 + p2);
}
void solve() {
  cin >> n;
  map<long long, int> m;
  for (int i = 1; i < n + 1; i++) {
    long long x;
    cin >> x;
    m[x] = i;
  }
  int currval = 1;
  for (map<long long, int>::iterator it = m.begin(); it != m.end(); it++) {
    arr[it->second] = currval;
    currval++;
  }
  int pos[n + 1];
  for (int i = 1; i < n + 1; i++) pos[arr[i]] = i;
  build(1, 1, n);
  long long ans = 0;
  update(1, 1, n, pos[1], 1);
  for (int i = 2; i < n; i++) {
    long long less = query(1, 1, n, pos[i], n);
    long long more = (long long)(pos[i] - 1 - query(1, 1, n, 1, pos[i]));
    ans += less * more;
    update(1, 1, n, pos[i], 1);
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
