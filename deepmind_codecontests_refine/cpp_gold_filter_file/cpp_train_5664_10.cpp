#include <bits/stdc++.h>
using namespace std;
struct segtree {
  int l, r, data;
  segtree *left, *right;
} * root;
int n, m, a[300005], p[300005];
segtree *buildtree(int l, int r) {
  int mid = (l + r) / 2;
  segtree *tem = new segtree;
  tem->l = l;
  tem->r = r;
  tem->data = 0;
  if (l == r)
    tem->left = tem->right = NULL;
  else
    tem->left = buildtree(l, mid), tem->right = buildtree(mid + 1, r);
  return tem;
}
void addval(segtree *nowv, int pos, int val) {
  int mid = (nowv->l + nowv->r) / 2;
  nowv->data += val;
  if (nowv->l != nowv->r) {
    if (pos <= mid)
      addval(nowv->left, pos, val);
    else
      addval(nowv->right, pos, val);
  }
  return;
}
void speproc(int val, int l, int r) {
  if (a[l] < n && p[a[l] + 1] < p[a[l]]) addval(root, a[l], val);
  if (a[l] > 1 && p[a[l]] < p[a[l] - 1]) addval(root, a[l] - 1, val);
  if (a[r] < n && p[a[r] + 1] < p[a[r]]) addval(root, a[r], val);
  if (a[r] > 1 && p[a[r]] < p[a[r] - 1]) addval(root, a[r] - 1, val);
  return;
}
int getval(segtree *nowv, int l, int r) {
  int mid = (nowv->l + nowv->r) / 2;
  if (nowv->l == l && nowv->r == r) return nowv->data;
  if (r <= mid)
    return getval(nowv->left, l, r);
  else if (l >= mid + 1)
    return getval(nowv->right, l, r);
  else
    return getval(nowv->left, l, mid) + getval(nowv->right, mid + 1, r);
}
int main() {
  int i, e, l, r;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    p[a[i]] = i;
  }
  root = buildtree(1, n - 1);
  for (i = 1; i <= n - 1; i++)
    if (p[i] > p[i + 1]) addval(root, i, 1);
  scanf("%d", &m);
  while (m--) {
    scanf("%d%d%d", &e, &l, &r);
    if (e == 1)
      printf("%d\n", getval(root, l, r - 1) + 1);
    else {
      speproc(-1, l, r);
      swap(p[a[l]], p[a[r]]);
      swap(a[l], a[r]);
      speproc(1, l, r);
      if (abs(a[l] - a[r]) == 1) {
        if (a[l] + 1 == a[r])
          addval(root, a[l], 1);
        else
          addval(root, a[r], -1);
      }
    }
  }
  return 0;
}
