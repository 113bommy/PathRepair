#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1010][1010];
int b[1010][1010], d[1010][1010];
int mc[1010], mr[1010];
struct qwe {
  int v;
  int id;
} c[1010];
bool cmp(qwe x, qwe y) { return x.v < y.v; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      c[j].id = j;
      c[j].v = a[i][j];
    }
    sort(c + 1, c + m + 1, cmp);
    b[i][c[1].id] = 1;
    for (int j = 2; j <= m; j++) {
      if (c[j].v > c[j - 1].v)
        b[i][c[j].id] = b[i][c[j - 1].id] + 1;
      else
        b[i][c[j].id] = b[i][c[j - 1].id];
    }
    mr[i] = b[i][c[m].id];
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      c[j].id = j;
      c[j].v = a[j][i];
    }
    sort(c + 1, c + n + 1, cmp);
    d[c[1].id][i] = 1;
    for (int j = 2; j <= n; j++) {
      if (c[j].v > c[j - 1].v)
        d[c[j].id][i] = d[c[j - 1].id][i] + 1;
      else
        d[c[j].id][i] = d[c[j - 1].id][i];
    }
    mc[i] = d[c[n].id][i];
  }
  int ans;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (b[i][j] == d[i][j]) {
        if (mr[i] > mc[j])
          ans = mr[i];
        else
          ans = mc[j];
      } else if (b[i][j] > d[i][j]) {
        if (mr[i] < mc[j] + b[i][j] - d[i][j])
          ans = mc[j] + b[i][j] - d[i][j];
        else
          ans = mr[i];
      } else {
        if (mr[i] + d[i][j] - b[i][j] > mc[j])
          ans = mr[i] + d[i][j] - b[i][j];
        else
          ans = mc[j];
      }
      printf("%d ", ans);
    }
    printf("\n");
  }
}
