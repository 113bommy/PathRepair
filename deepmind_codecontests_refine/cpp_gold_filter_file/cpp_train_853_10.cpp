#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
struct Node {
  int b, i, r;
  bool operator<(const Node n) const {
    return b != n.b ? b > n.b : (i != n.i ? i < n.i : r < n.r);
  }
} a[N];
int n, m;
int b[N << 1];
int h[N << 1];
void update(int x, int val) {
  for (int i = x; i > 0; i -= ((i) & (-(i)))) h[i] = max(h[i], val);
}
int ask(int x) {
  int ret = -1;
  for (int i = x; i <= m; i += ((i) & (-(i)))) ret = max(ret, h[i]);
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i].b);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].i);
    b[i] = a[i].i;
  }
  for (int i = 0; i < n; i++) scanf("%d", &a[i].r);
  sort(a, a + n);
  sort(b, b + n);
  m = unique(b, b + n) - b;
  int ans = 0;
  memset(h, -1, sizeof(h));
  for (int i = 0; i < n; i++) {
    int now = lower_bound(b, b + m, a[i].i) - b + 1;
    int mx = ask(now + 1);
    if (mx > a[i].r) ans++;
    update(now, a[i].r);
  }
  printf("%d\n", ans);
  return 0;
}
