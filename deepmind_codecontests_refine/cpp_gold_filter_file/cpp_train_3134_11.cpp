#include <bits/stdc++.h>
using namespace std;
int isp[3030], tot, p[3030];
int a[200002], dp[5032108][8], L[16];
int num, v[200], d[200];
struct node {
  int l, r, id;
  bool operator<(const node& a) const {
    return r < a.r || (r == a.r && l < a.l);
  }
} Q[1050000];
int ret[1050000];
int main(void) {
  for (int i = 2; i <= 3000; i++) {
    if (isp[i] == 0) p[tot++] = i;
    for (int j = 0; j < tot && p[j] * i <= 3000; j++) {
      isp[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < q; i++) scanf("%d%d", &Q[i].l, &Q[i].r), Q[i].id = i;
  sort(Q, Q + q);
  for (int i = 1, ii = 0; i <= n && ii < q; i++) {
    num = 0, v[num] = 1, d[num++] = 0;
    int cnt = 0;
    for (int j = 0; p[j] * p[j] <= a[i]; j++) {
      while (a[i] % (p[j] * p[j]) == 0) a[i] /= (p[j] * p[j]);
      if (a[i] % p[j] == 0) {
        cnt++;
        int onum = num;
        for (int k = 0; k < onum; k++) {
          v[num] = v[k] * p[j], d[num++] = d[k] + 1;
        }
        a[i] /= p[j];
      }
    }
    if (a[i] > 1) {
      cnt++;
      int onum = num;
      for (int k = 0; k < onum; k++) {
        v[num] = v[k] * a[i], d[num++] = d[k] + 1;
      }
    }
    for (int j = 0; j < num; j++) {
      for (int k = 0; k <= 7; k++) {
        int D = cnt - d[j] + k;
        L[D] = max(L[D], dp[v[j]][k]);
      }
    }
    for (int D = 0; ii < q && Q[ii].r == i; ii++) {
      while (L[D] < Q[ii].l) D++;
      if (L[D] >= Q[ii].l) ret[Q[ii].id] = D;
    }
    for (int j = 0; j < num; j++) dp[v[j]][cnt - d[j]] = i;
  }
  for (int i = 0; i < q; i++) printf("%d\n", ret[i]);
  return 0;
}
