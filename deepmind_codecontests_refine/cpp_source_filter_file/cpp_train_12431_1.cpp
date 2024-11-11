#include <bits/stdc++.h>
using namespace std;
int ans[300005] = {0};
int tree[1000005] = {0};
int n, q;
void build(int node, int start, int end, int l, int r, int w) {
  if (end < l || start > r) return;
  if (tree[node] != 0) return;
  if (start == end) {
    if (start != w) {
      ans[start] = w;
      tree[node] = w;
    }
    return;
  } else {
    int mid = (start + end) / 2;
    build(2 * node, start, mid, l, r, w);
    build(2 * node + 1, mid + 1, end, l, r, w);
    if (tree[2 * node] != 0 && tree[2 * node + 1] != 0 && tree[node] == 0)
      tree[node] = tree[2 * node];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  scanf("%d", &n);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int l, r, w;
    scanf("%d", &l);
    scanf("%d", &r);
    scanf("%d", &w);
    build(1, 1, n, l, r, w);
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
