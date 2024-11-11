#include <bits/stdc++.h>
using namespace std;
using namespace std;
int a[200010];
struct Node {
  int a, b, c;
} node[200010];
bool st[200010];
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1; (i) <= (n); i++) scanf("%d", &a[i]);
  int m;
  scanf("%d", &m);
  for (int i = 1; (i) <= (m); i++) {
    scanf("%d", &node[i].a);
    if (node[i].a == 1)
      scanf("%d%d", &node[i].b, &node[i].c);
    else
      scanf("%d", &node[i].b);
  }
  int maxx = 0;
  for (int i = m; i; i--) {
    if (node[i].a == 1 && !st[node[i].b]) {
      a[node[i].b] = max(node[i].c, maxx);
      st[node[i].b] = true;
    } else if (node[i].a == 2)
      maxx = max(maxx, node[i].b);
  }
  for (int i = 1; i <= n; i++) {
    if (!st[i])
      printf("%d ", max(a[i], maxx));
    else
      printf("%d ", a[i]);
  }
}
int main() {
  int t = 1;
  while (t--) solve();
}
