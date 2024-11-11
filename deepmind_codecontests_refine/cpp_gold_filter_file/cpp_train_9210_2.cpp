#include <bits/stdc++.h>
using namespace std;
long long int a[200005];
long long int tree[800020];
long long int lazy[800020];
long long int residue = LLONG_MAX;
long long int f(long long int x, long long int y) { return min(x, y); }
void build(long long int node, long long int s, long long int e) {
  if (s == e)
    tree[node] = a[s];
  else {
    long long int mid = (s + e) / 2;
    build(2 * node + 1, s, mid);
    build(2 * node + 2, mid + 1, e);
    tree[node] = f(tree[2 * node + 1], tree[2 * node + 2]);
  }
}
void update(long long int node, long long int l, long long int r,
            long long int s, long long int e, long long int val) {
  if (lazy[node]) {
    tree[node] += lazy[node];
    if (s != e) {
      lazy[2 * node + 1] += lazy[node];
      lazy[2 * node + 2] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (s > r || e < l || r < l) return;
  if (s >= l && e <= r) {
    tree[node] += val;
    if (s != e) {
      lazy[2 * node + 1] += val;
      lazy[2 * node + 2] += val;
    }
    return;
  }
  long long int mid = (s + e) / 2;
  update(2 * node + 1, l, r, s, mid, val);
  update(2 * node + 2, l, r, mid + 1, e, val);
  tree[node] = f(tree[2 * node + 1], tree[2 * node + 2]);
}
long long int query(long long int node, long long int s, long long int e,
                    long long int l, long long int r) {
  if (lazy[node]) {
    tree[node] += lazy[node];
    if (s != e) {
      lazy[2 * node + 1] += lazy[node];
      lazy[2 * node + 2] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (s > r || e < l || r < l) return LLONG_MAX;
  if (s >= l && e <= r) return tree[node];
  long long int mid = (s + e) / 2;
  return f(query(2 * node + 1, s, mid, l, r),
           query(2 * node + 2, mid + 1, e, l, r));
}
int main() {
  long long int n, i;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  build(0, 0, n - 1);
  long long int m;
  cin >> m;
  while (m--) {
    int x, y;
    char ch;
    scanf("%d%d%c", &x, &y, &ch);
    long long int l = x, r = y, val;
    if (ch != '\n') {
      cin >> val;
      if (r < l) {
        update(0, l, n - 1, 0, n - 1, val);
        update(0, 0, r, 0, n - 1, val);
      } else {
        update(0, l, r, 0, n - 1, val);
      }
    } else {
      if (r < l) {
        cout << min(query(0, 0, n - 1, l, n - 1), query(0, 0, n - 1, 0, r))
             << endl;
      } else {
        cout << query(0, 0, n - 1, l, r) << endl;
      }
    }
  }
  return 0;
}
