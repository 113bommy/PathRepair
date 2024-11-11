#include <bits/stdc++.h>
const int MAX_MN = 100000;
const int MAX_K = 100000;
int v[MAX_MN];
int d[MAX_MN], lastL[MAX_MN];
int rez[MAX_K];
struct Query {
  int l, r, *rez;
} qry[MAX_K];
bool cmp(Query a, Query b) { return a.r < b.r; }
int main() {
  int n, m, k, max;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n * m; ++i) scanf("%d", &v[i]);
  scanf("%d", &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d%d", &qry[i].l, &qry[i].r);
    qry[i].l--;
    qry[i].r--;
    qry[i].rez = &rez[i];
  }
  std::sort(qry, qry + k, cmp);
  int lastUp = -1;
  for (int i = 0; i < k; ++i) {
    while (lastUp < qry[i].r) {
      ++lastUp;
      max = 0;
      for (int j = 0; j < m; ++j) {
        if (v[lastUp * m + j] >= lastL[j])
          d[j]++;
        else
          d[j] = 1;
        if (d[j] > max) max = d[j];
        lastL[j] = v[lastUp * m + j];
      }
    }
    if (max >= qry[i].r - qry[i].l + 1) *qry[i].rez = 1;
  }
  for (int i = 0; i < k; ++i)
    if (rez[i] == 0)
      printf("No\n");
    else
      printf("Yes\n");
  return 0;
}
