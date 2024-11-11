#include <bits/stdc++.h>
using namespace std;
long long ans = 2000000000000000010, a, b, A, B, q, w, e1, e2, fa[201], yy;
struct p {
  long long q, w, e1, e2;
} l[100001], m[100001], y[100001];
bool cmp1(p qq, p ww) { return qq.e2 < ww.e2; }
bool cmp2(p qq, p ww) { return qq.e1 < ww.e1; }
long long find(long long qq) {
  if (fa[qq] == qq) return qq;
  return fa[qq] = find(fa[qq]);
}
int main() {
  scanf("%lld%lld%lld%lld", &a, &b, &A, &B);
  for (int i = 1; i <= b; i++) {
    scanf("%lld%lld%lld%lld", &q, &w, &e1, &e2);
    l[i].q = q;
    l[i].w = w;
    l[i].e1 = e1;
    l[i].e2 = e2;
  }
  for (int i = 1; i <= a; i++) {
    fa[i] = i;
  }
  sort(l + 1, l + b + 1, cmp1);
  long long hh = 0;
  for (int i = 1; i <= b; i++) {
    for (int j = 1; j <= a; j++) {
      fa[j] = j;
    }
    long long tt = l[i].e2;
    while (l[i].e2 == tt) {
      hh++;
      m[hh] = l[i];
      i++;
    }
    i--;
    long long ff1 = 0, ff2 = 0;
    tt = 0;
    yy = 0;
    sort(m + 1, m + hh + 1, cmp2);
    for (int j = 1; j <= hh; j++) {
      long long fq = find(m[j].q), fw = find(m[j].w);
      if (fq != fw) {
        fa[fw] = fq;
        tt++;
        ff1 = max(m[j].e1 * A, ff1);
        ff2 = max(m[j].e2 * B, ff2);
        yy++;
        y[yy] = m[j];
      }
    }
    if (tt == a - 1) {
      ans = min(ans, ff1 + ff2);
    }
    hh = yy;
    for (int j = 1; j <= yy; j++) {
      m[j] = y[j];
    }
  }
  if (ans > 2000000000000000005) {
    printf("-1");
  } else
    printf("%lld", ans);
  return 0;
}
