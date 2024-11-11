#include <bits/stdc++.h>
using namespace std;
const int maxn = int(1e6) + 111;
int n;
struct Node {
  int id, val, belong;
  Node() {}
  Node(int a, int b, int c) : id(a), val(b), belong(c) {}
  bool operator<(const Node &rhs) const {
    if (id != rhs.id) return id < rhs.id;
    return val < rhs.val;
  }
} node[maxn];
int top = 0;
int main() {
  int k, x, y, moder;
  scanf("%d", &n);
  register int i, j;
  int ans = 0;
  for (i = 1; i <= n; ++i) {
    int tmp = 0, last = 0, cur = 0;
    scanf("%d%d%d%d%d", &k, &last, &x, &y, &moder);
    node[++top] = Node(cur, last, i);
    for (j = 2; j <= k; ++j) {
      tmp = (1ll * last * x + y) % moder;
      if (tmp < last) cur++;
      node[++top] = Node(cur, tmp, i);
      last = tmp;
    }
    ans = max(ans, cur);
  }
  printf("%d\n", ans);
  sort(node + 1, node + 1 + top);
  if (top >= int(2e5)) return 0;
  for (i = 1; i <= top; ++i) {
    printf("%d %d\n", node[i].val, node[i].belong);
  }
  return 0;
}
