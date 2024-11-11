#include <bits/stdc++.h>
using namespace std;
struct node {
  int d, s;
} a[100010];
int n, x, y, s;
bool t = false;
bool cmp(node l, node r) { return l.d < r.d; }
int main() {
  cin >> n >> s;
  s = 1000000 - s;
  for (int i = 0; i < n; i++) cin >> x >> y >> a[i].s, a[i].d = x * x + y * y;
  sort(a, a + n, cmp);
  for (int i = 0; i < n; i++) {
    s = s - a[i].s;
    if (s <= 0) {
      double x = sqrt(a[i].d);
      printf("%.7lf\n", x);
      t = true;
      break;
    }
  }
  if (!t) cout << -1 << endl;
  return 0;
}
