#include <bits/stdc++.h>
using namespace std;
const int MAXN = 510000;
struct data {
  long long w;
  int c, a;
} v[MAXN];
long long ii;
double dd;
void gao(int l, int r, long long w) {
  if (r < l) return;
  if (l == r) {
    ii += w * v[l].c / v[l].w;
    dd += (w * v[l].c % v[l].w) / ((double)v[l].w);
    ii += (int)dd;
    dd -= (int)dd;
    return;
  }
  int i = l, j = r, midc = v[(l + r) / 2].c;
  long long cur = 0LL, cost = 0LL, midw = v[(l + r) / 2].w;
  while (i <= j) {
    while (midw * v[i].c < v[i].w * midc) {
      cur += v[i].w;
      cost += v[i].c;
      i++;
    }
    while (midw * v[j].c > v[j].w * midc) {
      j--;
    }
    if (i <= j) {
      cur += v[j].w;
      cost += v[j].c;
      swap(v[i++], v[j--]);
    }
  }
  if (cur <= w) {
    ii += cost;
    gao(i, r, w - cur);
  } else {
    gao(l, j, w);
  }
}
int main() {
  int n, m;
  long long w;
  scanf("%d%d%lld", &n, &m, &w);
  for (int i = 0; i < m; i++) scanf("%lld", &v[i].w);
  for (int i = 0; i < m; i++) scanf("%d", &v[i].c);
  for (int i = 0; i < m; i++) scanf("%d", &v[i].a);
  ii = 0LL;
  dd = 0.0;
  for (int i = 0; i < n; i++) {
    gao(0, m - 1, w);
    for (int j = 0; j < m; j++) {
      v[j].c -= v[j].a;
    }
  }
  ii += (int)dd;
  dd -= (int)dd;
  printf("%lld%.15lf\n", ii / 10, ii % 10 + dd);
  return 0;
}
