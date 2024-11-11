#include <bits/stdc++.h>
using namespace std;
struct inp {
  int a, in, r;
  inp() {}
  inp(int _a, int _in) {
    a = _a;
    in = _in;
  }
} ar[3009];
bool qcmp(inp x, inp y) { return x.a > y.a; }
bool indcmp(inp x, inp y) { return x.in < y.in; }
struct node {
  int mx, ind;
  node() {}
  node(int _mx, int _ind) {
    mx = _mx;
    ind = _ind;
  }
} tree[4 * 3009];
node mergenode(node x, node y) {
  if (x.mx >= y.mx)
    return x;
  else
    return y;
}
void build(int ind, int st, int ed) {
  if (st == ed) {
    tree[ind] = node(ar[st].a - ar[st + 1].a, st);
    return;
  }
  build(ind + ind, st, (st + ed) / 2);
  build(ind + ind + 1, (st + ed) / 2 + 1, ed);
  tree[ind] = mergenode(tree[ind + ind], tree[ind + ind + 1]);
}
node query(int ind, int st, int ed, int i, int j) {
  if (st > j || ed < i)
    return node(-100000000, -1);
  else if (st >= i && ed <= j)
    return tree[ind];
  else
    return mergenode(query(ind + ind, st, (st + ed) / 2, i, j),
                     query(ind + ind + 1, (st + ed) / 2 + 1, ed, i, j));
}
int main() {
  int n, k, i, a, b, c, l, r, res, ma = -1, mb = -1, mc = -1, ca, cb, cc,
                                   ra = 0, rb = 0, rc = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &ar[i].a);
    ar[i].in = i;
  }
  sort(ar + 1, ar + n + 1, qcmp);
  ar[n + 1].a = 0;
  build(1, 1, n);
  node nd;
  for (a = 1; a < n; a++) {
    for (b = 1; b < n; b++) {
      if (a > 2 * b || b > 2 * a || a + b >= n) continue;
      ca = ar[a].a - ar[a + 1].a;
      cb = ar[a + b].a - ar[a + b + 1].a;
      l = max((a + 1) / 2, (b + 1) / 2);
      if (a + b + l > n) continue;
      r = min(2 * a, 2 * b);
      r = min(r, n - a - b);
      if (r < l) continue;
      nd = query(1, 1, n, a + b + l, a + b + r);
      cc = nd.mx;
      if (ca > ma || (ca == ma && cb > mb) ||
          (ca == ma && cb == mb && cc > mc)) {
        ma = ca;
        mb = cb;
        mc = cc;
        ra = a;
        rb = b;
        rc = nd.ind - a - b;
      }
    }
  }
  assert(ma >= 0 && mb >= 0 && mc >= 0);
  assert(ra <= 2 * rb && ra <= 2 * rc && rb <= 2 * ra && rb <= 2 * rc &&
         rc <= 2 * ra && rc <= 2 * rb);
  i = 1;
  while (ra) {
    ar[i++].r = 1;
    ra--;
  }
  while (rb) {
    ar[i++].r = 2;
    rb--;
  }
  while (rc) {
    ar[i++].r = 3;
    rc--;
  }
  while (i <= n) {
    ar[i++].r = -1;
  }
  sort(ar + 1, ar + n + 1, indcmp);
  for (i = 1; i <= n; i++) {
    if (i > 1) printf(" ");
    printf("%d", ar[i].r);
  }
  printf("\n");
  return 0;
}
