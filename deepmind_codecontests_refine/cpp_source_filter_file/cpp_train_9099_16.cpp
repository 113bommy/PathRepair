#include <bits/stdc++.h>
using namespace std;
int n, m, s;
int a[7010][5];
int l[7010], r[7010], pl[100010], c[7010];
bool v[7010];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &a[i][0]);
    if (a[i][0] == 1) {
      scanf("%d %d %d %d", &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
      c[++s] = a[i][4];
    } else
      scanf("%d %d", &a[i][1], &a[i][2]);
  }
  sort(c + 1, c + s + 1);
  s = unique(c + 1, c + s + 1) - c - 1;
  for (int i = 1; i <= m; ++i)
    if (a[i][0] == 1) a[i][4] = lower_bound(c + 1, c + s + 1, a[i][4]) - c;
  pl[0] = 0;
  for (int i = 1, j = 0; i <= 100000; ++i) {
    pl[i] = pl[i - 1];
    if (i == (1 << j)) ++pl[i], ++j;
  }
  int level;
  for (int i = 1; i <= m; ++i) {
    if (a[i][0] == 1) continue;
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    level = a[i][1];
    l[level] = r[level] = a[i][2];
    for (int j = level; j < n; ++j) {
      l[j + 1] = l[j] + pl[l[j] - 1];
      r[j + 1] = r[j] + pl[r[j]];
    }
    for (int j = 1; j <= s; ++j) v[j] = false;
    int num = 0, nl, nr;
    for (int j = 1; j < i; ++j)
      if (a[j][0] == 1) {
        nl = l[a[j][1]], nr = r[a[j][1]];
        if (nl > a[j][3] || a[j][2] > nr) continue;
        if (!v[a[j][4]]) {
          ++num;
          v[a[j][4]] = true;
        }
      }
    printf("%d\n", num);
  }
  return 0;
}
