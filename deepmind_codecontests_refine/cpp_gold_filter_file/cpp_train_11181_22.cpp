#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
using namespace std;
char s[100010], t[100010], ans[100010];
int arcs[30][30], d[30][30];
void Floyd() {
  int i, j, k;
  int n = 25;
  for (i = 0; i <= n; i++)
    for (j = 0; j <= n; j++) d[i][j] = arcs[i][j];
  for (k = 0; k <= n; k++)
    for (i = 0; i <= n; i++)
      for (j = 0; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
int main() {
  std::ios::sync_with_stdio(false);
  int n, w, sumw, tw, lens, lent, i, j;
  char c1, c2;
  scanf(" %s %s", s, t);
  scanf("%d", &n);
  for (i = 0; i < 30; i++)
    for (j = 0; j < 30; j++) {
      if (i == j)
        arcs[i][j] = 0;
      else
        arcs[i][j] = INF;
    }
  for (i = 0; i < n; i++) {
    scanf(" %c %c %d", &c1, &c2, &w);
    int x1 = c1 - 'a', y1 = c2 - 'a';
    arcs[x1][y1] = min(arcs[x1][y1], w);
  }
  lens = strlen(s);
  lent = strlen(t);
  Floyd();
  if (lens != lent) {
    printf("-1\n");
    return 0;
  } else {
    sumw = 0;
    bool flag = false;
    for (i = 0; i < lens; i++) {
      tw = INF;
      int x1 = s[i] - 'a', x2 = t[i] - 'a';
      for (j = 0; j < 26; j++) {
        int t1 = d[x1][j], t2 = d[x2][j];
        if (t1 != INF && t2 != 1e5 && t1 + t2 < tw) {
          tw = t1 + t2;
          ans[i] = j + 'a';
        }
      }
      if (tw == INF) {
        flag = true;
        break;
      }
      sumw += tw;
    }
    if (flag)
      printf("-1\n");
    else {
      ans[lens] = '\0';
      printf("%d\n", sumw);
      printf("%s\n", ans);
    }
  }
  return 0;
}
