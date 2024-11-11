#include <bits/stdc++.h>
const int maxn = 1001000;
const int maxtreetop = 2100000;
struct Ttree {
  int start, stop, len;
  int *a;
} tree[maxtreetop + 1];
int n;
int l1, r1, l2, r2, result;
int wz[maxn + 1];
int x = 0;
void init_tree(int p, int l, int r) {
  tree[p].start = l;
  tree[p].stop = r;
  tree[p].len = r - l + 1;
  tree[p].a = new int[tree[p].len];
  if (l < r) {
    int mid = (l + r) / 2;
    init_tree(p * 2, l, mid);
    init_tree(p * 2 + 1, mid + 1, r);
  }
}
void sort_tree(int p) {
  if (tree[p].len == 1) return;
  sort_tree(p * 2);
  sort_tree(p * 2 + 1);
  int q, q1, q2, len1, len2;
  int *a1, *a2;
  q1 = q2 = 0;
  len1 = tree[p * 2].len;
  len2 = tree[p * 2 + 1].len;
  a1 = tree[p * 2].a;
  a2 = tree[p * 2 + 1].a;
  q = 0;
  while ((q1 < len1) || (q2 < len2)) {
    if ((q1 < len1) && ((q2 >= len2) || (a1[q1] < a2[q2]))) {
      tree[p].a[q++] = a1[q1];
      ++q1;
    } else {
      tree[p].a[q++] = a2[q2];
      ++q2;
    }
  }
}
void ins_tree(int x, int val) {
  int p = 1, mid;
  while (tree[p].len > 1) {
    mid = (tree[p].start + tree[p].stop) / 2;
    if (x <= mid)
      p = p * 2;
    else
      p = p * 2 + 1;
  }
  tree[p].a[0] = val;
}
void init() {
  int i, j, q;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &q);
    wz[q] = i;
  }
  init_tree(1, 1, n);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &q);
    ins_tree(i, wz[q]);
  }
  sort_tree(1);
}
int f(int z) { return ((z - 1 + x) % n) + 1; }
int xiao(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
int da(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
void ask_tree(int p, int l, int r) {
  int i, j;
  if (tree[p].a[tree[p].len - 1] < l1) return;
  if (tree[p].a[0] > r1) return;
  if ((l <= tree[p].start) && (r >= tree[p].stop)) {
    int *a = tree[p].a;
    int start, stop, mid;
    if (false) {
      int i, j;
      i = 0;
      j = tree[p].len - 1;
      while (a[i] < l1) ++i;
      while (a[j] > r1) --j;
      result += (j - i + 1);
    } else {
      start = 0;
      stop = tree[p].len - 1;
      while (start <= stop) {
        mid = (start + stop) / 2;
        if (a[mid] >= l1) {
          i = mid;
          stop = mid - 1;
        } else
          start = mid + 1;
      }
      start = 0;
      stop = tree[p].len - 1;
      while (start <= stop) {
        mid = (start + stop) / 2;
        if (a[mid] <= r1) {
          j = mid;
          start = mid + 1;
        } else
          stop = mid - 1;
      }
      result += (j - i + 1);
    }
    return;
  }
  int mid = (tree[p].start + tree[p].stop) / 2;
  if (l <= mid) ask_tree(p * 2, l, r);
  if (r > mid) ask_tree(p * 2 + 1, l, r);
}
void work() {
  int i, m, a, b, c, d;
  scanf("%d", &m);
  x = 0;
  for (i = 1; i <= m; ++i) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    l1 = xiao(f(a), f(b));
    r1 = da(f(a), f(b));
    l2 = xiao(f(c), f(d));
    r2 = da(f(c), f(d));
    result = 0;
    ask_tree(1, l2, r2);
    printf("%d\n", result);
    x = result + 1;
  }
}
int main() {
  init();
  work();
  return 0;
}
