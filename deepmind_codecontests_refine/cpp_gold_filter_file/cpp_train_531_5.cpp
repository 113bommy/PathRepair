#include <bits/stdc++.h>
using namespace std;
int occ[102][2] = {0}, frow[2] = {0}, m, cen, dis, mdis = 0, rans = 0, cans = 0,
    tmpd = 0, n, k, i, j, rst, ren, md;
int main() {
  int dl, dr, dy;
  scanf("%d %d", &n, &k);
  frow[0] = (k + 1) / 2;
  frow[1] = (k + 1) / 2;
  cen = (k + 1) / 2;
  for (i = 1; i <= n; i++) {
    scanf("%d", &m);
    rst = max(frow[0], 1);
    ren = min(frow[1], k);
    mdis = -1;
    rans = -1;
    cans = -1;
    for (j = rst; j <= ren; j++) {
      dis = 0;
      if (j == frow[0] || j == frow[1]) {
        if (m % 2 == 0) {
          md = (m / 2) - 1;
          dis += (m / 2) + (md + 1) * md;
        } else {
          md = m / 2;
          dis += (md + 1) * md;
        }
        dis += (m * abs(j - cen));
        if (dis < mdis || mdis == -1) {
          mdis = dis;
          rans = j;
          cans = -1;
        }
      } else {
        dis += (m * abs(j - cen));
        dy = abs(occ[j][0] - cen);
        dl = ((dy + dy + m - 1) * m) / 2;
        if ((dis + dl < mdis || mdis == -1) && occ[j][0] - m >= 0) {
          mdis = dis + dl;
          rans = j;
          cans = 0;
        }
        dy = abs(occ[j][1] - cen);
        dr = ((dy + dy + m - 1) * m) / 2;
        if ((dis + dr < mdis || mdis == -1) && occ[j][1] + m <= k + 1) {
          mdis = dis + dr;
          rans = j;
          cans = 1;
        }
      }
    }
    if (rans == frow[0] || rans == frow[1]) {
      int l = cen - (m / 2) - 1;
      int r = l + m + 1;
      printf("%d %d %d\n", rans, l + 1, r - 1);
      occ[rans][0] = l;
      occ[rans][1] = r;
      if (rans == frow[0]) frow[0]--;
      if (rans == frow[1]) frow[1]++;
    } else if (rans == -1) {
      printf("-1\n");
    } else {
      if (cans == 1) {
        printf("%d %d %d\n", rans, occ[rans][1], occ[rans][1] + m - 1);
        occ[rans][1] += m;
      }
      if (cans == 0) {
        printf("%d %d %d\n", rans, occ[rans][0] + 1 - m, occ[rans][0]);
        occ[rans][0] -= m;
      }
    }
  }
  return 0;
}
