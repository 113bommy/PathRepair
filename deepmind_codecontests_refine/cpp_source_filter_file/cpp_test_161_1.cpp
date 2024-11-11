#include <bits/stdc++.h>
using namespace std;
int t, n, v[1010];
struct node {
  int l, r, d;
} a[1010];
bool cmp(node x, node y) { return x.r - x.l < y.r - y.l; }
int main() {
  cin >> t;
  while (t--) {
    memset(v, 0, sizeof(v));
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r;
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
      for (int j = a[i].l; j <= a[i].r; i++) {
        if (v[j] == 0) {
          a[i].d = j;
          v[j] = 1;
          break;
        }
      }
    }
    for (int i = 1; i <= n; i++)
      cout << a[i].l << " " << a[i].r << " " << a[i].d << endl;
  }
}
