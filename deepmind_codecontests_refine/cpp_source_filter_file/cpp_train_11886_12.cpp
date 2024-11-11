#include <bits/stdc++.h>
using namespace std;
int a[301000];
int b[301000];
struct node {
  int l, r, sum;
  node() { l = 0, r = 0, sum = 0; }
} tr[1001000];
void update(int k) { tr[k].sum = min(tr[k * 2].sum, tr[k * 2 + 1].sum); }
void tree(int l, int r, int k) {
  tr[k].l = l, tr[k].r = r;
  int mid = (tr[k].l + tr[k].r) / 2;
  if (l == r) {
    tr[k].sum = a[l];
    return;
  }
  tree(l, mid, 2 * k);
  tree(mid + 1, r, 2 * k + 1);
  update(k);
}
void change(int x, int y, int k) {
  if (tr[k].l == tr[k].r) {
    tr[k].sum = y;
    return;
  }
  int mid = (tr[k].l + tr[k].r) / 2;
  if (x <= mid)
    change(x, y, 2 * k);
  else
    change(x, y, 2 * k + 1);
  update(k);
}
int find(int l, int r, int k) {
  if (l == tr[k].l && r == tr[k].r) return tr[k].sum;
  int mid = (tr[k].l + tr[k].r) / 2;
  if (l > mid)
    return find(l, r, 2 * k + 1);
  else if (r <= mid)
    return find(l, r, 2 * k);
  else
    return min(find(l, mid, 2 * k), find(mid + 1, r, 2 * k + 1));
}
queue<int> q[301000];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      q[a[i]].push(i);
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &b[i]);
    }
    int vis = 0;
    tree(1, n, 1);
    for (int i = 1; i <= n; i++) {
      if (q[b[i]].size() == 0) {
        vis = 1;
        break;
      }
      int x = q[b[i]].front();
      q[b[i]].pop();
      int bb = find(1, x, 1);
      if (bb < b[i]) {
        vis = 1;
        break;
      }
      change(x, 1000000000, 1);
    }
    for (int i = 1; i <= n; i++) {
      while (q[a[i]].size()) q[a[i]].pop();
    }
    if (vis)
      printf("NO\n");
    else
      printf("YES\n");
  }
}
