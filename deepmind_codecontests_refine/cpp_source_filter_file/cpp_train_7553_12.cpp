#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535;
const double eps = 1e-6;
struct TE {
  int x, b;
} E[100100], p[100100];
int n, m, id, a[100100], tot;
char na[100010][23], who[23];
bool cmp2(int va, int ba, int vb, int bb) {
  if (va == vb) return strcmp(na[ba], na[bb]) < 0;
  return va > vb;
}
bool cmp(TE a, TE b) {
  if (a.x == b.x) return strcmp(na[a.b], na[b.b]) < 0;
  return a.x < b.x;
}
int workhigh() {
  int best = E[id].x + a[n - 1];
  tot = 0;
  for (int i = 0; i < n; i++)
    if (E[i].b != id) p[tot++] = E[i];
  sort(p, p + tot, cmp);
  int l = -1, r = tot;
  while (r - l > 1) {
    int mi = (l + r) / 2;
    bool flag = 1;
    for (int i = 0; i <= mi; i++)
      if (cmp2(p[i].x + a[mi - i], p[i].b, best, id)) {
        flag = 0;
        break;
      }
    if (flag)
      l = mi;
    else
      r = mi;
  }
  return n - (l + 1);
}
int worklow() {
  int best = E[id].x + a[0];
  tot = 0;
  for (int i = 0; i < n; i++)
    if (E[i].b != id) p[tot++] = E[i];
  sort(p, p + tot, cmp);
  int l = 0, r = tot + 1;
  while (r - l > 1) {
    int mi = (l + r) / 2;
    bool flag = 1;
    int nn = n - 2;
    for (int i = n - mi; i < n; i++) {
      if (cmp2(best, id, p[nn].x + a[i], p[nn].b)) {
        flag = 0;
        break;
      }
      nn--;
    }
    if (flag)
      l = mi;
    else
      r = mi;
  }
  return l + 1;
}
int main() {
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; i++) {
      scanf(" %s", &na[i]);
      scanf("%d", &E[i].x);
      E[i].b = i;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%d", a + i);
    for (int i = m; i < n; i++) a[i] = 0;
    sort(a, a + n);
    scanf(" %s", who);
    int le = strlen(who);
    for (int i = 0; i < n; i++)
      if (strlen(na[i]) == le) {
        bool flag = 1;
        for (int j = 0; j < le; j++)
          if (who[j] != na[i][j]) {
            flag = 0;
            break;
          }
        if (flag) {
          id = i;
          break;
        }
      }
    printf("%d ", workhigh());
    printf("%d\n", worklow());
  }
}
