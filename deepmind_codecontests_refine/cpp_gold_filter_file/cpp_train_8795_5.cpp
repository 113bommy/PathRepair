#include <bits/stdc++.h>
using namespace std;
struct node {
  int val, ord;
  bool operator<(const node& rhs) const {
    if (val != rhs.val)
      return val < rhs.val;
    else
      return ord < rhs.ord;
  }
};
int main() {
  int n, a[105];
  scanf("%d", &n);
  priority_queue<node> q;
  while (!q.empty()) q.pop();
  node e;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    e.val = a[i], e.ord = i;
    q.push(e);
  }
  int ret = 0, cnt = a[1];
  while (true) {
    node f = q.top();
    if (f.ord == 1) break;
    q.pop();
    ret++;
    f.val--;
    node g;
    g.ord = 1, g.val = cnt + ret;
    q.push(f);
    q.push(g);
  }
  printf("%d\n", ret);
  return 0;
}
