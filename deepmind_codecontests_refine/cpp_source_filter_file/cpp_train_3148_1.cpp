#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
int seg[4 * MAXN];
int lazy[4 * MAXN];
int p[MAXN];
int ind[MAXN];
int q[MAXN];
void pushdown(int curr) {
  seg[curr] += lazy[curr];
  if (lazy[curr]) {
    lazy[2 * curr] += lazy[curr];
    lazy[2 * curr + 1] += lazy[curr];
  }
  lazy[curr] = 0;
}
void updateval(int curr, int l, int r, int tl, int tr) {
  pushdown(curr);
  if (l > tr || r < tl) {
    return;
  }
  if (l >= tl && r <= tr) {
    seg[curr]++;
    if (l != r) {
      lazy[2 * curr]++;
      lazy[2 * curr + 1]++;
    }
    return;
  }
  int mid = (l + r) / 2;
  updateval(2 * curr, l, mid, tl, tr);
  updateval(2 * curr + 1, mid + 1, r, tl, tr);
  seg[curr] = max(seg[2 * curr], seg[2 * curr + 1]);
}
void updatebomb(int curr, int l, int r, int tl, int tr) {
  pushdown(curr);
  if (l > tr || r < tl) {
    return;
  }
  if (l >= tl && r <= tr) {
    seg[curr]--;
    if (l != r) {
      lazy[2 * curr]--;
      lazy[2 * curr + 1]--;
    }
    return;
  }
  int mid = (l + r) / 2;
  updatebomb(2 * curr, l, mid, tl, tr);
  updatebomb(2 * curr + 1, mid + 1, r, tl, tr);
  seg[curr] = max(seg[2 * curr], seg[2 * curr + 1]);
}
int query(int curr, int l, int r, int tl, int tr) {
  pushdown(curr);
  if (l > tr || r < tl) {
    return -1e9;
  }
  if (l >= tl && r <= tr) {
    return seg[curr];
  }
  int mid = (l + r) / 2;
  return max(query(2 * curr, l, mid, tl, tr),
             query(2 * curr + 1, mid + 1, r, tl, tr));
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    ind[p[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> q[i];
  }
  cout << n << " ";
  int curr = n;
  updateval(1, 1, n, 1, ind[n]);
  for (int i = 1; i < n; i++) {
    updatebomb(1, 1, n, 1, q[i]);
    while (query(1, 1, n, 1, n) <= 0) {
      curr--;
      updateval(1, 1, n, 1, ind[curr]);
    }
    cout << curr << " ";
  }
}
