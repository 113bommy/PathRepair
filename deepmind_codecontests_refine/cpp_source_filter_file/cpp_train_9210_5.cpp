#include <bits/stdc++.h>
using namespace std;
long long a[200001], tree[500001], lazy[500001];
void build(long long node, long long start, long long end) {
  if (start == end) {
    tree[node] = a[start];
    return;
  }
  long long mid = (start + end) / 2;
  build(2 * node, start, mid);
  build(2 * node + 1, mid + 1, end);
  tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
void update(long long node, long long start, long long end, long long l,
            long long r, long long value) {
  if (lazy[node] != 0) {
    tree[node] += lazy[node];
    if (start != end) {
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (start > end || start > r || end < l) return;
  if (start >= l && end <= r) {
    tree[node] += value;
    if (start != end) {
      lazy[2 * node] += value;
      lazy[2 * node + 1] += value;
    }
    return;
  }
  long long mid = (start + end) / 2;
  update(2 * node, start, mid, l, r, value);
  update(2 * node + 1, mid + 1, end, l, r, value);
  tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
long long query(long long node, long long start, long long end, long long l,
                long long r) {
  if (lazy[node] != 0) {
    tree[node] += lazy[node];
    if (start != end) {
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (start > end || start > r || end < l) return 1e18;
  if (start >= l && end <= r) return tree[node];
  long long mid = (start + end) / 2;
  long long p1 = query(2 * node, start, mid, l, r);
  long long p2 = query(2 * node + 1, mid + 1, end, l, r);
  return min(p1, p2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, i, c, k = 0, j;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < 500001; i++) lazy[i] = 0;
  build(1, 1, n);
  cin >> m;
  while (m--) {
    k = 0;
    cin >> ws;
    string s;
    long long b[3];
    getline(cin, s);
    stringstream ss(s);
    ss >> b[0];
    ss >> b[1];
    if (ss >> b[2]) {
      if (b[0] <= b[1])
        update(1, 1, n, b[0] + 1, b[1] + 1, b[2]);
      else {
        update(1, 1, n, b[0] + 1, n, b[2]);
        update(1, 1, n, 1, b[1] + 1, b[2]);
      }
    } else {
      long long p1, p2, ans;
      if (b[0] <= b[1])
        ans = query(1, 1, n, b[0] + 1, b[1] + 1);
      else {
        long long p1 = query(1, 1, n, b[0] + 1, n);
        long long p2 = query(1, 1, n, 1, b[1] + 1);
        ans = min(p1, p2);
      }
      cout << ans << endl;
    }
  }
  return 0;
}
