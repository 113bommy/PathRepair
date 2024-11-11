#include <bits/stdc++.h>
using namespace std;
struct Node {
  int b, i, r;
  bool operator<(Node a) const { return b < a.b; }
} d[500020];
int v[500020], c[500020];
int query(int x, int n) {
  int s = 0;
  while (x <= n) s = max(s, c[x]), x += (x & (-x));
  return s;
}
void modify(int x, int delta) {
  while (x) c[x] = max(c[x], delta), x -= (x & (-x));
}
int main() {
  int i, j, n;
  while (cin >> n) {
    for (i = 1; i <= n; ++i) scanf("%d", &d[i].b);
    for (i = 1; i <= n; i++) {
      scanf("%d", &d[i].i);
      v[i] = d[i].i;
    }
    for (i = 1; i <= n; ++i) scanf("%d", &d[i].r);
    sort(d + 1, d + 1 + n);
    sort(v + 1, v + 1 + n);
    int n2 = unique(v + 1, v + 1 + n) - v - 1;
    for (i = 1; i <= n; ++i)
      d[i].i = lower_bound(v + 1, v + 1 + n2, d[i].i) - v;
    memset(c, 0, sizeof(c));
    ;
    int tail = n, cnt = 0;
    for (i = n - 1; i > 0; --i) {
      if (d[i].b != d[i + 1].b) {
        for (j = i + 1; j <= tail; ++j) modify(d[j].i, d[j].r);
        tail = i;
      }
      if (d[i].i == n2) continue;
      int m = query(d[i].i + 1, n2);
      if (m > d[i].r) cnt++;
    }
    printf("%d\n", cnt);
  }
}
