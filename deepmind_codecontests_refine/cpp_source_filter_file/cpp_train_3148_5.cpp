#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
struct node {
  int nums = 0, bombs = 0;
};
node seg[4 * N];
node merge(node a, node b) {
  node ans;
  int tmp = min(a.nums, b.bombs);
  ans.nums = a.nums + b.nums - tmp;
  ans.bombs = b.nums + b.bombs - tmp;
  return ans;
}
void upd(int root, int a, int b, int i, int val) {
  if (a > i or b < i) return;
  if (a == b) {
    if (val == 0)
      seg[root].nums++;
    else
      seg[root].bombs++;
    int tmp = min(seg[root].nums, seg[root].bombs);
    seg[root].nums -= tmp;
    seg[root].bombs -= tmp;
    return;
  }
  upd(2 * root, a, (a + b) / 2, i, val);
  upd(2 * root + 1, (a + b) / 2 + 1, b, i, val);
  seg[root] = merge(seg[2 * root], seg[2 * root + 1]);
}
int main() {
  int n;
  scanf("%d", &n);
  int ip[n + 1], q[n + 1];
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    ip[x] = i;
  }
  for (int i = 1; i <= n; i++) scanf("%d", q + i);
  int ans = n;
  upd(1, 1, n, ip[n], 0);
  for (int i = 1; i <= n; i++) {
    while (seg[1].nums == 0) {
      --ans;
      upd(1, 1, n, ip[ans], 0);
    }
    printf("%d ", ans);
    upd(1, 1, n, q[i], 1);
  }
  printf("\n");
  return 0;
}
