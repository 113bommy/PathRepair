#include <bits/stdc++.h>
using namespace std;
int n, m, a[210000], mi[1000], ma[1000], ans, fi, fj, ff, te, l[400], r[400],
    e[1000], et;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &l[i], &r[i]);
    e[++et] = l[i];
    e[++et] = r[i] + 1;
  }
  e[++et] = 1;
  e[++et] = n + 1;
  sort(e + 1, e + et + 1);
  et = unique(e + 1, e + et + 1) - e - 1;
  for (int i = 1; i <= et - 1; i++) {
    mi[i] = ma[i] = a[e[i]];
    for (int j = e[i] + 1; j <= e[i + 1] - 1; j++) {
      if (a[j] < mi[i]) mi[i] = a[j];
      if (a[j] > ma[i]) ma[i] = a[j];
    }
  }
  for (int i = 1; i <= et - 1; i++)
    for (int j = 1; j <= et - 1; j++) {
      te = 0;
      for (int k = 1; k <= m; k++)
        if (((l[k] <= e[i]) && (e[i + 1] - 1 <= r[k])) &&
            (!((l[k] <= e[j]) && (e[j + 1] - 1 <= r[k]))))
          te++;
      if (ma[j] - mi[i] + te > ans) {
        ans = ma[j] - mi[i] + te;
        fi = i;
        fj = j;
        ff = te;
      }
    }
  printf("%d\n%d\n", ans, ff);
  for (int k = 1; k <= m; k++)
    if (((l[k] <= e[fi]) && (e[fi + 1] - 1 <= r[k])) &&
        (!((l[k] <= e[fj]) && (e[fj + 1] - 1 <= r[k]))))
      printf("%d ", k);
  return 0;
}
