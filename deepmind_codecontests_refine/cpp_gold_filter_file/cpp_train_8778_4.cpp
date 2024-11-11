#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
};
int comp(const void *x, const void *y) {
  node *p = (node *)x;
  node *q = (node *)y;
  return (q->y) - (p->y);
}
node a[25];
int main() {
  int n, m;
  int ans;
  while (cin >> n >> m) {
    for (int i = 0; i < m; i++) cin >> a[i].x >> a[i].y;
    qsort(a, m, sizeof(node), comp);
    ans = 0;
    for (int i = 0; i < m; i++) {
      if (n >= a[i].x) {
        ans += a[i].x * a[i].y;
        n -= a[i].x;
      } else {
        ans += n * a[i].y;
        n = 0;
      }
      if (n == 0) break;
    }
    cout << ans << endl;
  }
  return 0;
}
