#include <bits/stdc++.h>
using namespace std;
const double ep = 1e-8;
struct dat {
  double x;
  int st, en, sign;
  bool operator<(const dat &b) const { return x < b.x; }
} L[100100 << 1];
int add[100100 << 3];
double z[100100 << 1], len[100100 << 3];
void modify(int L, int R, int val, int l, int r, int id) {
  if (L <= l && r <= R)
    add[id] += val;
  else {
    int m = l + r >> 1;
    if (L < m) modify(L, R, val, l, m, id << 1);
    if (m < R) modify(L, R, val, m, r, id << 1 ^ 1);
  }
  if (add[id])
    len[id] = z[r] - z[l];
  else
    len[id] = len[id << 1] + len[id << 1 ^ 1];
}
int n, num;
double stx[100100], sty[100100], enx[100100], eny[100100];
int main() {
  while (scanf("%d", &n) == 1 && n) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%lf %lf %lf %lf", &stx[i], &sty[i], &enx[i], &eny[i]);
      if (stx[i] > enx[i]) swap(stx[i], enx[i]), swap(sty[i], eny[i]);
      if (sty[i] > eny[i]) swap(stx[i], enx[i]), swap(sty[i], eny[i]);
      stx[i] -= 0.5, sty[i] -= 0.5;
      enx[i] += 0.5, eny[i] += 0.5;
      z[++cnt] = sty[i], z[++cnt] = eny[i];
    }
    sort(z + 1, z + cnt + 1);
    cnt = unique(z + 1, z + cnt + 1) - z - 1;
    int runs = 0;
    for (int i = 1; i <= n; i++) {
      int st = lower_bound(z + 1, z + cnt + 1, sty[i] - ep) - z;
      int en = lower_bound(z + 1, z + cnt + 1, eny[i] - ep) - z;
      L[++runs] = {stx[i], st, en, 1};
      L[++runs] = {enx[i], st, en, -1};
    }
    sort(L + 1, L + runs + 1);
    double ans = 0;
    fill(len, len + (cnt << 2), 0);
    for (int i = 1; i <= runs; i++) {
      if (i > 1) ans += len[1] * (L[i].x - L[i - 1].x);
      modify(L[i].st, L[i].en, L[i].sign, 1, cnt, 1);
    }
    printf("%.0lf\n", ans + 0.3);
  }
  return 0;
}
