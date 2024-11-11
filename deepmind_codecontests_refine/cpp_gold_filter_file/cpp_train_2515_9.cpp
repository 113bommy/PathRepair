#include <bits/stdc++.h>
using namespace std;
int n, m, aa[300005], bb[300005], v[1000005], q;
int x[4000005], y[4000005], dx;
void build(int l, int r, int i) {
  if (l + 1 == r) {
    y[i] = v[l];
    return;
  }
  int mi = (l + r) / 2;
  build(l, mi, i * 2);
  build(mi, r, i * 2 + 1);
  y[i] = max(y[i * 2], y[i * 2 + 1]);
}
void add(int a, int b, int l, int r, int i) {
  if (a == l && b == r) {
    x[i] += dx;
    y[i] += dx;
    return;
  }
  int mi = (l + r) / 2;
  if (a < mi) add(a, min(mi, b), l, mi, i * 2);
  if (mi < b) add(max(a, mi), b, mi, r, i * 2 + 1);
  y[i] = max(y[i * 2], y[i * 2 + 1]) + x[i];
}
int find(int l, int r, int i, int vv) {
  if (l + 1 == r) return l;
  vv -= x[i];
  int mi = (l + r) / 2;
  if (y[i * 2 + 1] > vv) return find(mi, r, i * 2 + 1, vv);
  return find(l, mi, i * 2, vv);
}
int main() {
  scanf("%d%d", &n, &m);
  v[0] = n + 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", aa + i);
    v[aa[i]]++;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", bb + i);
    v[bb[i]]--;
  }
  for (int i = 1000000; i >= 0; i--) v[i] += v[i + 1];
  build(0, 1000001, 1);
  scanf("%d", &q);
  while (q--) {
    int ta, tb, tc;
    scanf("%d%d%d", &ta, &tb, &tc);
    if (ta == 1) {
      if (aa[tb] < tc) {
        dx = 1;
        add(aa[tb] + 1, tc + 1, 0, 1000001, 1);
      } else if (aa[tb] > tc) {
        dx = -1;
        add(tc + 1, aa[tb] + 1, 0, 1000001, 1);
      }
      aa[tb] = tc;
    } else {
      if (bb[tb] < tc) {
        dx = -1;
        add(bb[tb] + 1, tc + 1, 0, 1000001, 1);
      } else if (bb[tb] > tc) {
        dx = 1;
        add(tc + 1, bb[tb] + 1, 0, 1000001, 1);
      }
      bb[tb] = tc;
    }
    ta = find(0, 1000001, 1, 0);
    if (ta == 0) ta = -1;
    printf("%d\n", ta);
  }
}
