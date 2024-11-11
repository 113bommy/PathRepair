#include <bits/stdc++.h>
using namespace std;
struct node {
  int mn, mx, lz;
  int l, r;
};
const int MAXN = 3e5 + 5;
const int MAIOR = 1e6 + 3;
vector<node> seg;
int dishes[MAXN], pupils[MAXN];
int n, m, q;
int novo() {
  node cara;
  cara.mn = cara.mx = 0;
  cara.l = cara.r = cara.lz = 0;
  seg.push_back(cara);
  return seg.size() - 1;
}
void refresh(int sind, int ini, int fim) {
  seg[sind].mn += seg[sind].lz;
  seg[sind].mx += seg[sind].lz;
  if (ini == fim) {
    seg[sind].lz = 0;
    return;
  }
  if (!seg[sind].l) {
    int aux = novo();
    seg[sind].l = aux;
  }
  if (!seg[sind].r) {
    int aux = novo();
    seg[sind].r = aux;
  }
  seg[seg[sind].l].lz += seg[sind].lz;
  seg[seg[sind].r].lz += seg[sind].lz;
  seg[sind].lz = 0;
}
void junta(int sind, int e, int d) {
  seg[sind].mn = min(seg[e].mn, seg[d].mn);
  seg[sind].mx = max(seg[e].mx, seg[d].mx);
  seg[sind].l = e;
  seg[sind].r = d;
  seg[sind].lz = 0;
}
void update(int sind, int ini, int fim, int qini, int qfim, int val) {
  refresh(sind, ini, fim);
  if (qfim < ini || qini > fim) return;
  if (qini <= ini && qfim >= fim) {
    seg[sind].lz = val;
    refresh(sind, ini, fim);
    return;
  }
  int m = (ini + fim) / 2;
  int e = seg[sind].l;
  int d = seg[sind].r;
  update(e, ini, m, qini, qfim, val);
  update(d, m + 1, fim, qini, qfim, val);
  junta(sind, seg[sind].l, seg[sind].r);
}
int query(int sind, int ini, int fim) {
  refresh(sind, ini, fim);
  if (ini == fim) return seg[sind].mx > 0 ? ini : -1;
  int m = (ini + fim) / 2;
  int e = seg[sind].l;
  int d = seg[sind].r;
  refresh(e, ini, m);
  refresh(d, m + 1, fim);
  if (seg[d].mx > 0)
    return query(d, m + 1, fim);
  else
    return query(e, ini, m);
}
int main() {
  novo();
  novo();
  novo();
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", &dishes[i]), update(1, 1, MAIOR, 1, dishes[i], 1);
  for (int i = 1; i <= m; i++)
    scanf("%d", &pupils[i]), update(1, 1, MAIOR, 1, pupils[i], -1);
  scanf("%d", &q);
  while (q--) {
    int a, ind, val;
    scanf("%d %d %d", &a, &ind, &val);
    if (a == 1) {
      update(1, 1, MAIOR, 1, dishes[ind], -1);
      dishes[ind] = val;
      update(1, 1, MAIOR, 1, dishes[ind], 1);
    } else {
      update(1, 1, MAIOR, 1, pupils[ind], 1);
      pupils[ind] = val;
      update(1, 1, MAIOR, 1, pupils[ind], -1);
    }
    printf("%d\n", query(1, 1, MAIOR));
  }
}
