#include <bits/stdc++.h>
using namespace std;
struct node {
  int li, ri, ki, xi;
};
struct pt {
  int x, y;
};
node pro[300011];
pt b[100011];
int f[300011], anss, ans[300011], nw, n, m, k, n1, k1, rk[100001], cnt,
    nexl[100001], nexr[100001], ff, num[100001];
bool p[100011];
bool cmp(node aa, node bb) {
  return ((aa.ki < bb.ki) || ((aa.ki == bb.ki) && (aa.ri < bb.ri)));
}
bool cmp1(pt aa, pt bb) { return (aa.x < bb.x); }
int main() {
  scanf("%d", &n);
  cnt = 0;
  k1 = 300;
  cnt = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &b[i].x);
  for (int i = 1; i <= n; i++) b[i].y = i;
  sort(b + 1, b + 1 + n, cmp1);
  for (int i = 1; i <= n; i++) rk[b[i].y] = i;
  for (int i = 1; i <= n; i++) {
    if (i % k1 == 1) cnt++;
    num[i] = cnt;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &pro[i].li, &pro[i].ri);
  for (int i = 1; i <= m; i++) pro[i].ki = num[pro[i].li];
  for (int i = 1; i <= m; i++) pro[i].xi = i;
  sort(pro + 1, pro + 1 + m, cmp);
  for (int i = 1; i <= m; i++) {
    int j = i;
    while ((j < m) && (pro[j + 1].ki == pro[i].ki)) j++;
    for (int kk = 1; kk <= n; kk++) p[kk] = false;
    for (int kk = pro[i].ki * k1 + 1; kk <= pro[j].ri; kk++) p[rk[kk]] = true;
    nw = 0;
    for (int kk = 1; kk <= n; kk++)
      if (p[kk]) {
        nexl[kk] = nw;
        nexr[nw] = kk;
        nw = kk;
      }
    nexr[nw] = 0;
    for (int kk = pro[j].ri; kk >= pro[i].ki * k1 + 1; kk--) {
      if (nexl[rk[kk]] != 0) nexr[nexl[rk[kk]]] = nexr[rk[kk]];
      if (nexr[rk[kk]] != 0) nexl[nexr[rk[kk]]] = nexl[rk[kk]];
    }
    nw = pro[i].ki * k1;
    anss = 1000000000;
    for (int i1 = i; i1 <= j; i1++) {
      f[i1] = 1000000000;
      for (int kk = nw + 1; kk <= pro[i1].ri; kk++) {
        if (nexl[rk[kk]] != 0) {
          ff = b[rk[kk]].x - b[nexl[rk[kk]]].x;
          if (ff < anss) anss = ff;
          nexr[nexl[rk[kk]]] = rk[kk];
        }
        if (nexr[rk[kk]] != 0) {
          ff = b[nexr[rk[kk]]].x - b[rk[kk]].x;
          if (ff < anss) anss = ff;
          nexl[nexr[rk[kk]]] = rk[kk];
        }
      }
      f[i1] = anss;
      if (nw < pro[i1].ri) nw = pro[i1].ri;
    }
    for (int kk = pro[i].ki * k1 - k1 + 1; kk <= pro[j].ri; kk++)
      if (kk <= n) p[rk[kk]] = true;
    nw = 0;
    for (int kk = 1; kk <= n; kk++)
      if (p[kk]) {
        nexl[kk] = nw;
        nexr[nw] = kk;
        nw = kk;
      }
    nexr[nw] = 0;
    for (int kk = pro[j].ri; kk >= (pro[i].ki - 1) * k1 + 1; kk--) {
      if (nexl[rk[kk]] != 0) nexr[nexl[rk[kk]]] = nexr[rk[kk]];
      if (nexr[rk[kk]] != 0) nexl[nexr[rk[kk]]] = nexl[rk[kk]];
    }
    nw = pro[i].ki * k1 - k1;
    for (int i1 = i; i1 <= j; i1++) {
      anss = 1000000000;
      for (int kk = nw + 1; kk <= pro[i1].ri; kk++) {
        if (nexl[rk[kk]] != 0) nexr[nexl[rk[kk]]] = rk[kk];
        if (nexr[rk[kk]] != 0) nexl[nexr[rk[kk]]] = rk[kk];
      }
      n1 = pro[i].ki * k1;
      if (pro[i1].ri < n1) n1 = pro[i1].ri;
      for (int kk = pro[i].ki * k1 - k1 + 1; kk <= n1; kk++) {
        if (nexl[rk[kk]] != 0) nexr[nexl[rk[kk]]] = nexr[rk[kk]];
        if (nexr[rk[kk]] != 0) nexl[nexr[rk[kk]]] = nexl[rk[kk]];
      }
      for (int kk = n1; kk >= pro[i1].li; kk--) {
        if (nexl[rk[kk]] != 0) {
          ff = b[rk[kk]].x - b[nexl[rk[kk]]].x;
          ;
          if (ff < anss) anss = ff;
          nexr[nexl[rk[kk]]] = rk[kk];
        }
        if (nexr[rk[kk]] != 0) {
          ff = b[nexr[rk[kk]]].x - b[rk[kk]].x;
          if (ff < anss) anss = ff;
          nexl[nexr[rk[kk]]] = rk[kk];
        }
      }
      for (int kk = pro[i1].li - 1; kk >= pro[i].ki * k1 - k1 + 1; kk--) {
        if (nexl[rk[kk]] != 0) nexr[nexl[rk[kk]]] = nexr[rk[kk]];
        if (nexr[rk[kk]] != 0) nexl[nexr[rk[kk]]] = nexl[rk[kk]];
      }
      if (anss < f[i1])
        ans[pro[i1].xi] = anss;
      else
        ans[pro[i1].xi] = f[i1];
      nw = pro[i1].ri;
    }
    i = j;
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
