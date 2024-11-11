#include <bits/stdc++.h>
using namespace std;
const int N = int(1e5) + 5;
int a[N], t[N * 6], ch[N * 6];
void push(int v) {
  ch[v + v] += ch[v];
  ch[v + v + 1] += ch[v];
  t[v] += ch[v];
  ch[v] = 0;
}
void upd(int v, int l, int r, int L, int R, int x) {
  push(v);
  if (l > R || r < L) return;
  if (L <= l && r <= R) {
    ch[v] += x;
    push(v);
    return;
  }
  int mid = (l + r) / 2;
  upd(v + v, l, mid, L, R, x);
  upd(v + v + 1, mid + 1, r, L, R, x);
  t[v] = max(t[v + v], t[v + v + 1]);
}
int get(int v, int l, int r, int L, int R) {
  push(v);
  if (l > R || r < L) return -1;
  if (L <= l && r <= R) {
    return t[v];
  }
  int mid = (l + r) / 2;
  return max(get(v + v, l, mid, L, R), get(v + v + 1, mid + 1, r, L, R));
}
int main() {
  int m;
  cin >> m;
  a[0] = -1;
  for (int tt = 1; tt <= m; tt++) {
    int p, t;
    scanf("%d %d", &p, &t);
    if (t == 1) {
      scanf("%d", a + p);
      upd(1, 1, m, 1, p, 1);
    } else {
      upd(1, 1, m, 1, p, -1);
    }
    int ans = 0;
    int l = 1, r = m;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (get(1, 1, m, mid, m) > 0) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    printf("%d\n", a[ans]);
  }
  return 0;
}
