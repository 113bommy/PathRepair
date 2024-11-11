#include <bits/stdc++.h>
using namespace std;
const int Maxm = 1e5 + 5;
struct node {
  int x, y;
} p[Maxm];
bool cmp(node a, node b) { return (a.x == b.x) ? a.y < b.y : a.x < b.x; }
int n, m, ival[2 * Maxm][2], ival_cnt, tmp[2 * Maxm][2], tmp_cnt;
void solve() {
  ival[0][0] = 1, ival[0][1] = n;
  ival_cnt = 1;
  for (int i = 0, j; i < m; i = j) {
    tmp_cnt = 0;
    j = i + 1;
    while (j < m && p[j].x == p[i].x) j++;
    if (p[i].x == 1) {
      ival[0][0] = 1;
      ival_cnt = 1;
      if ((j < m && p[i].x < p[j].x - 1) || (j == m && p[i].x != n))
        ival[0][1] = n;
      else
        ival[0][1] = p[j - 1].y - 1;
      continue;
    }
    int ymin = ival[0][0];
    int p1 = 0;
    for (int k = i; k < j; k++) {
      while (p1 < ival_cnt && ival[p1][1] < p[k].y) p1++;
      if (p1 == ival_cnt) {
        tmp[tmp_cnt][0] = ymin;
        tmp[tmp_cnt++][1] = p[k].y - 1;
        break;
      }
      if (p[k].y < ival[p1][0] && p[k].y > ymin) {
        tmp[tmp_cnt][0] = ymin;
        tmp[tmp_cnt++][1] = p[k].y - 1;
        ymin = ival[p1][0];
      } else if (p[k].y >= ival[p1][0]) {
        if (p[k].y > ymin) {
          tmp[tmp_cnt][0] = ymin;
          tmp[tmp_cnt++][1] = p[k].y - 1;
        }
        ymin = p[k].y + 1;
        ival[p1][0] = ymin;
        if (ival[p1][0] > ival[p1][1]) {
          p1++;
          if (p1 == ival_cnt)
            break;
          else
            ymin = ival[p1][0];
        }
      }
    }
    if (p1 < ival_cnt) {
      tmp[tmp_cnt][0] = ymin;
      tmp[tmp_cnt++][1] = n;
    }
    if (tmp_cnt == 0) {
      puts("-1");
      return;
    }
    if ((j < m && p[i].x < p[j].x - 1) || (j == m && p[i].x < n)) {
      ival_cnt = 1;
      ival[0][0] = tmp[0][0];
      ival[0][1] = n;
    } else {
      ival_cnt = tmp_cnt;
      for (int k = 0; k < tmp_cnt; k++)
        ival[k][0] = tmp[k][0], ival[k][1] = tmp[k][1];
    }
  }
  if (p[m - 1].x != n || (p[m - 1].x == n && ival[ival_cnt - 1][1] == n))
    printf("%d\n", 2 * (n - 1));
  else
    puts("-1");
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) scanf("%d%d", &p[i].x, &p[i].y);
  sort(p, p + m, cmp);
  solve();
  return 0;
}
