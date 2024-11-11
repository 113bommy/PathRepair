#include <bits/stdc++.h>
using namespace std;
int n, a[100005], m;
long long tree[4 * 100005], lazy[4 * 100005];
void propagate(int node, int lo, int hi) {
  tree[node] = max(tree[node], lazy[node]);
  if (lo != hi) {
    lazy[(node << 1)] = max(lazy[(node << 1)], lazy[node]);
    lazy[((node << 1) + 1)] = max(lazy[((node << 1) + 1)], lazy[node]);
  }
  lazy[node] = 0;
}
void update(int node, int lo, int hi, int i, int j, long long val) {
  if (j < lo || i > hi) return;
  if (i <= lo && hi <= j) {
    lazy[node] = max(lazy[node], val);
    return;
  }
  int mid = (lo + hi) >> 1;
  update((node << 1), lo, mid, i, j, val);
  update(((node << 1) + 1), mid + 1, hi, i, j, val);
  propagate((node << 1), lo, mid);
  propagate(((node << 1) + 1), mid + 1, hi);
  tree[node] = max(tree[(node << 1)], tree[((node << 1) + 1)]);
}
long long query(int node, int lo, int hi, int i, int j) {
  if (j < lo || i > hi) return 0;
  propagate(node, lo, hi);
  if (i <= lo && hi <= j) return tree[node];
  int mid = (lo + hi) >> 1;
  return max(query((node << 1), lo, mid, i, j),
             query(((node << 1) + 1), mid + 1, hi, i, j));
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    update(1, 1, n, i, i, a[i]);
  }
  scanf("%d", &m);
  while (m--) {
    int w, h;
    scanf("%d %d", &w, &h);
    long long ans = query(1, 1, n, 1, w);
    update(1, 1, n, 1, w, ans + h);
    cout << ans << endl;
  }
}
