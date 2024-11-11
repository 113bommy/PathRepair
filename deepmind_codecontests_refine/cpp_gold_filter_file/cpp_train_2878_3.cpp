#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, cntx, cnty;
long long ans;
double eps = 1e-10;
struct bit {
  int v[100010];
  void add(int k, int vv) {
    for (k; k <= cnty; k += k & -k) v[k] += vv;
  }
  int qy(int l, int r) {
    l = min(l - 1, cnty);
    r = min(r, cnty);
    int s = 0;
    for (; l; l -= l & -l) s -= v[l];
    for (; r; r -= r & -r) s += v[r];
    return s;
  }
} bt;
struct node {
  double a, b;
  int l, r;
} q[100010];
bool cmpa(node a, node b) { return a.a < b.a; }
bool cmpb(node a, node b) { return a.b < b.b; }
bool cmpl(node a, node b) {
  if (a.l == b.l) return a.r > b.r;
  return a.l < b.l;
}
int main() {
  int i, s, a, b, j, k;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &a, &b);
    q[i].a = ((double)a) / ((double)-b - m);
    q[i].b = ((double)a) / ((double)-b + m);
  }
  sort(q + 1, q + 1 + n, cmpa);
  q[1].l = cntx = 1;
  for (i = 2; i <= n; i++) {
    if (fabs(q[i].a - q[i - 1].a) <= 0) {
      q[i].l = q[i - 1].l;
      continue;
    }
    q[i].l = ++cntx;
  }
  sort(q + 1, q + 1 + n, cmpb);
  q[1].r = cnty = 1;
  for (i = 2; i <= n; i++) {
    if (fabs(q[i].b - q[i - 1].b) <= 0) {
      q[i].r = q[i - 1].r;
      continue;
    }
    q[i].r = ++cnty;
  }
  sort(q + 1, q + 1 + n, cmpl);
  for (i = 1; i <= n; i++) ans += bt.qy(q[i].r, cnty), bt.add(q[i].r, 1);
  cout << ans;
  return 0;
}
