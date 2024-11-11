#include <bits/stdc++.h>
using namespace std;
struct moja {
  long long d, x, y, c;
} r[100005];
int cmp(struct moja qq, struct moja ww) {
  if (qq.d != ww.d) {
    return qq.d < ww.d;
  }
}
long long q, i, dosao[100005], otisao[100005], usao, izasao, m, n, k,
    md[100005], mi[100005], sol, dsol[100005], isol[100005], gusao, gizasao, j;
int main() {
  usao = 10000001;
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  gusao = n + 1;
  for (i = 1; i <= m; i++) {
    scanf("%I64d%I64d%I64d%I64d", &r[i].d, &r[i].x, &r[i].y, &r[i].c);
  }
  sort(r + 1, r + m + 1, cmp);
  q = 0;
  for (i = 1; i <= m; i++) {
    if (r[i].x != 0) {
      dosao[r[i].x]++;
      if (dosao[r[i].x] == 1) {
        q++;
        if (q == n) {
          usao = r[i].d;
          gusao = i;
        }
      }
    }
  }
  q = 0;
  for (i = m; i >= 1; i--) {
    if (r[i].x == 0) {
      otisao[r[i].y]++;
      if (otisao[r[i].y] == 1) {
        q++;
        if (q == n) {
          izasao = r[i].d;
          gizasao = i;
        }
      }
    }
  }
  for (i = 1; i <= n; i++) {
    md[i] = 1000001;
    mi[i] = 1000001;
  }
  dsol[0] = md[1] * n;
  for (i = 1; i <= m; i++) {
    dsol[i] = dsol[i - 1];
    if (r[i].x != 0) {
      if (r[i].c < md[r[i].x]) {
        dsol[i] = dsol[i] - (md[r[i].x] - r[i].c);
        md[r[i].x] = r[i].c;
      }
    }
  }
  isol[m + 1] = mi[1] * n;
  for (i = m; i >= 1; i--) {
    isol[i] = isol[i + 1];
    if (r[i].x == 0) {
      if (r[i].c < mi[r[i].y]) {
        isol[i] = isol[i] - (mi[r[i].y] - r[i].c);
        mi[r[i].y] = r[i].c;
      }
    }
  }
  sol = dsol[0] + isol[m + 1];
  j = gusao;
  for (i = gusao; i <= gizasao; i++) {
    while (1) {
      if (r[j].d - r[i].d > k) break;
      j++;
      if (j > gizasao) break;
    }
    if (j > gizasao) break;
    if (dsol[i] + isol[j] < sol) sol = dsol[i] + isol[j];
  }
  if (sol < dsol[0] + isol[m + 1])
    printf("%I64d", sol);
  else
    printf("-1");
}
