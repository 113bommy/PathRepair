#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 10;
const long long maxm = 1000005;
struct node {
  long long sum;
  bool flag;
} tree[maxn << 2];
int yy[maxm];
int a[maxn];
void build(int l, int r, int pos) {
  if (l == r) {
    tree[pos].sum = a[l];
    if (tree[pos].sum == 1 || tree[pos].sum == 2) tree[pos].flag = true;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, pos << 1);
  build(mid + 1, r, pos << 1 | 1);
  tree[pos].sum = tree[pos << 1].sum + tree[pos << 1 | 1].sum;
  tree[pos].flag = (tree[pos << 1].flag & tree[pos << 1 | 1].flag);
}
void update(int l, int r, int posl, int posr, int pos) {
  if (tree[pos].flag) return;
  if (l == r) {
    tree[pos].sum = yy[tree[pos].sum];
    if (tree[pos].sum == 1 || tree[pos].sum == 2) tree[pos].flag = true;
    return;
  }
  int mid = (l + r) >> 1;
  if (posl <= mid) update(l, mid, posl, posr, pos << 1);
  if (posr > mid) update(mid + 1, r, posl, posr, pos << 1 | 1);
  tree[pos].sum = tree[pos << 1].sum + tree[pos << 1 | 1].sum;
  tree[pos].flag = (tree[pos << 1].flag & tree[pos << 1 | 1].flag);
}
long long query(int l, int r, int posl, int posr, int pos) {
  if (l >= posl && r <= posr) return tree[pos].sum;
  if (l == r) return tree[pos].sum;
  int mid = (l + r) >> 1;
  long long ans = 0;
  if (posl <= mid) ans += query(l, mid, posl, posr, pos << 1);
  if (posr > mid) ans += query(mid + 1, r, posl, posr, pos << 1 | 1);
  return ans;
}
int main() {
  for (int i = 1; i < maxm; i++) {
    for (int j = i; j < maxm; j += i) {
      yy[j]++;
    }
  }
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  build(1, n, 1);
  int op, l, r;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1) {
      update(1, n, l, r, 1);
    } else
      printf("%lld\n", query(1, n, l, r, 1));
  }
  return 0;
}
