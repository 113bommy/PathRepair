#include <bits/stdc++.h>
using namespace std;
const int maxn = 5200;
const int inf = 1100000000;
struct Node {
  int o, l, r, val;
} node[maxn];
int n, m, num[maxn], ans[maxn];
int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    for (int i = 1; i <= m; i++)
      scanf("%d %d %d %d", &node[i].o, &node[i].l, &node[i].r, &node[i].val);
    for (int i = 1; i <= n; i++) num[i] = inf;
    for (int i = m; i >= 1; i--) {
      for (int j = node[i].l; j <= node[i].r; j++) {
        if (node[i].o == 1)
          num[j] -= node[i].val;
        else {
          if (num[j] > node[i].val) num[j] = node[i].val;
        }
      }
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) ans[i] = num[i];
    for (int i = 1; i <= m; i++) {
      int mmin = -inf;
      for (int j = node[i].l; j <= node[i].r; j++) {
        if (node[i].o == 1)
          num[j] += node[i].val;
        else
          mmin = max(mmin, num[j]);
      }
      if (node[i].o == 2 && mmin != node[i].val) {
        flag = false;
        break;
      }
    }
    if (flag == false)
      printf("NO\n");
    else {
      printf("YES\n");
      for (int i = 1; i < n; i++) printf("%d ", ans[i]);
      printf("%d\n", ans[n]);
    }
  }
  return 0;
}
