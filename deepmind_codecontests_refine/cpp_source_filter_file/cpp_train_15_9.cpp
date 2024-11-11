#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const long long inf = 1e11;
struct Node {
  int l, r, num;
  long long tag;
  long long val;
} node[4 * maxn];
long long a[maxn];
int ans[maxn];
void up(int no) {
  if (node[no << 1].val < node[no << 1 | 1].val) {
    node[no].val = node[no << 1].val;
    node[no].num = node[no << 1].num;
  } else {
    node[no].val = node[no << 1 | 1].val;
    node[no].num = node[no << 1 | 1].num;
  }
}
void build(int l, int r, int no) {
  node[no].l = l;
  node[no].r = r;
  node[no].tag = 0;
  if (l == r) {
    node[no].val = a[l];
    node[no].num = l;
    return;
  }
  int mid = l + r >> 1;
  build(l, mid, no << 1);
  build(mid + 1, r, no << 1 | 1);
  up(no);
}
void pushdown(int no) {
  node[no << 1].tag += node[no].tag;
  node[no << 1].val += node[no].tag;
  node[no << 1 | 1].tag += node[no].tag;
  node[no << 1 | 1].val += node[no << 1 | 1].tag;
  node[no].tag = 0;
}
void change(int l, int r, int no, long long num) {
  if (node[no].r < l || node[no].l > r) return;
  if (node[no].l >= l && node[no].r <= r) {
    node[no].tag += num;
    node[no].val += num;
    return;
  }
  if (node[no].tag != 0) {
    pushdown(no);
  }
  change(l, r, no << 1, num);
  change(l, r, no << 1 | 1, num);
  up(no);
}
int main() {
  int n, i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%lld", &a[i]);
  build(1, n, 1);
  for (i = 1; i <= n; i++) {
    int x = node[1].num;
    ans[x] = i;
    change(x, x, 1, inf);
    change(x + 1, n, 1, -i);
  }
  for (i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}
