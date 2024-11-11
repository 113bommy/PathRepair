#include <bits/stdc++.h>
using namespace std;
double f[2102][2102][2][2];
int bdl[2102][2], bdr[2102][2];
int lft[2102], rgt[2102];
int pos[2102];
int n, h;
double p;
double sch(int l, int r, int fl, int fr) {
  double ret = 0;
  if (f[l][r][fl][fr] > -1) return f[l][r][fl][fr];
  if (l > r) return 0;
  double pll, plr, prl, prr;
  int rlc, lrc;
  rlc = max(l, lft[r]);
  lrc = min(r, rgt[l]);
  pll = 0.5 * p;
  plr = 0.5 * (1 - p);
  prl = 0.5 * p;
  prr = 0.5 * (1 - p);
  ret += pll * (sch(l + 1, r, 0, fr) + (double)min(pos[l] - bdl[l - 1][fl], h));
  ret += plr * (sch(rgt[l] + 1, r, 1, fr) +
                (double)(min(pos[lrc] - pos[l] + h, bdr[r + 1][fr] - pos[l])));
  ret += prl * (sch(l, lft[r] - 1, fl, 0) +
                (double)(min(pos[r] - pos[rlc] + h, pos[r] - bdl[l - 1][fl])));
  ret += prr * (sch(l, r - 1, fl, 1) + (double)min(bdr[r + 1][fr] - pos[r], h));
  f[l][r][fl][fr] = ret;
  return ret;
}
void input() {
  scanf("%d%d%lf", &n, &h, &p);
  for (int i = 1; i <= n; i++) scanf("%d", &pos[i]);
  sort(pos + 1, pos + n + 1);
  pos[0] = -500000000, pos[n + 1] = 500000000;
  lft[0] = 0;
  for (int i = 1; i <= n; i++)
    if (pos[i] - pos[i - 1] < h)
      lft[i] = lft[i - 1];
    else
      lft[i] = i;
  rgt[n + 1] = n + 1;
  for (int i = n; i >= 1; i--)
    if (pos[i + 1] - pos[i] < h)
      rgt[i] = rgt[i + 1];
    else
      rgt[i] = i;
  for (int i = 0; i <= n + 1; i++)
    bdl[i][0] = pos[i], bdl[i][1] = pos[i] + h, bdr[i][0] = pos[i] - h,
    bdr[i][1] = pos[i];
}
int main() {
  input();
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= n + 1; j++)
      f[i][j][0][0] = f[i][j][0][1] = f[i][j][1][0] = f[i][j][1][1] = -1;
  printf("%.15f\n", sch(1, n, 0, 1));
  return 0;
}
