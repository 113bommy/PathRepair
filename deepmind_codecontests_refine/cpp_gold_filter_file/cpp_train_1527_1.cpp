#include <bits/stdc++.h>
using namespace std;
const int N = 20005;
int n, mat[N];
struct P {
  int x, y, id;
  bool operator<(const P &a) const { return x == a.x ? y < a.y : x < a.x; }
} a[N], bas;
bool cmp(P x, P y) {
  x.x -= bas.x;
  x.y -= bas.y;
  y.x -= bas.x;
  y.y -= bas.y;
  return 1ll * x.x * y.y - 1ll * y.x * x.y > 0;
}
void solve(int l, int r) {
  if (l > r) return;
  int p = min_element(a + l, a + r + 1) - a;
  swap(a[l], a[p]);
  bas = a[l];
  sort(a + l + 1, a + r + 1, cmp);
  int c0 = 0, c1 = 0, k = 0;
  for (int i = (int)(l); i <= (int)(r); i++) {
    (a[i].id <= n ? ++c0 : ++c1);
    if (c1 == c0) {
      k = i;
      break;
    }
  }
  if (a[k].id < a[l].id) swap(a[k], a[l]);
  mat[a[l].id] = a[k].id - n;
  solve(l + 1, k - 1);
  solve(k + 1, r);
}
int main() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n * 2); i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    a[i].id = i;
  }
  solve(1, n * 2);
  for (int i = (int)(1); i <= (int)(n); i++) printf("%d\n", mat[i]);
}
