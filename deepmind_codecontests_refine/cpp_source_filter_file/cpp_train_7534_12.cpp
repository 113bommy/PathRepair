#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, k;
};
int n, m, n2;
int a[200005];
int b[200005];
node lazy[2000005];
node udp;
void check_lazy(int s, int e, int pos) {
  if (s == e || lazy[pos].y == -1) {
    return;
  } else {
    lazy[2 * pos + 1].x = lazy[pos].x;
    lazy[2 * pos + 1].y = lazy[pos].y;
    lazy[2 * pos + 1].k = lazy[pos].k;
    lazy[2 * pos + 2].x = lazy[pos].x;
    lazy[2 * pos + 2].y = lazy[pos].y;
    lazy[2 * pos + 2].k = lazy[pos].k;
    lazy[pos].y = -1;
  }
}
void update(int x, int y, int s, int e, int pos) {
  check_lazy(s, e, pos);
  if (e < x || s > y) {
    return;
  }
  if (s >= x && e <= y) {
    lazy[pos].x = udp.x;
    lazy[pos].y = udp.y;
    lazy[pos].k = udp.k;
    return;
  }
  int mid = (s + e) / 2;
  update(x, y, s, mid, 2 * pos + 1);
  update(x, y, mid + 1, e, 2 * pos + 2);
}
int fl = 0;
int val = -1;
int query(int x, int s, int e, int pos) {
  check_lazy(s, e, pos);
  if (s == e && s == x) {
    fl = lazy[pos].y;
    val = x - lazy[pos].y + lazy[pos].x;
    return 0;
  }
  if (s > x || e < x) {
    return 0;
  }
  int mid = (s + e) / 2;
  query(x, s, mid, 2 * pos + 1);
  query(x, mid + 1, e, 2 * pos + 2);
}
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  n2 = pow(2, ceil(log2(n)));
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < 2000005; i++) {
    lazy[i].y = -1;
  }
  while (m--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x, y, k;
      scanf("%d", &x);
      scanf("%d", &y);
      scanf("%d", &k);
      int l = y - 1;
      int r = l + k;
      udp.x = x - 1;
      udp.y = y - 1;
      udp.k = k;
      update(l, r, 0, n2 - 1, 0);
    } else {
      int x;
      scanf("%d", &x);
      x--;
      query(x, 0, n2 - 1, 0);
      if (fl == -1) {
        cout << b[x] << endl;
      } else {
        cout << a[val] << endl;
      }
    }
  }
  return 0;
}
