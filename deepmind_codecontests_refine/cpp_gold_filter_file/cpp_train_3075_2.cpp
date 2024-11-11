#include <bits/stdc++.h>
using namespace std;
int ta[5005], tb[5005], tc[5005];
bool hacka[5005], hackb[5005], hackc[5005];
int waa, wab, wac, la, lb, lc, ans;
int f[90][90][90];
int g[90][90][90];
void upd(int &x, int y) { x < y ? x = y : 0; }
int main() {
  int n;
  scanf("%d", &n);
  waa = wab = wac = n;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (!x)
      x = 250, waa--;
    else if (x < 0) {
      la++;
      x = -x;
      hacka[i] = 1;
    }
    ta[i] = 250 - x;
    scanf("%d", &x);
    if (!x)
      x = 250, wab--;
    else if (x < 0) {
      lb++;
      x = -x;
      hackb[i] = 1;
    }
    tb[i] = 250 - x;
    scanf("%d", &x);
    if (!x)
      x = 250, wac--;
    else if (x < 0) {
      lc++;
      x = -x;
      hackc[i] = 1;
    }
    tc[i] = 250 - x;
  }
  if (la + lb + lc >= 90) return puts("1"), 0;
  const int po[7] = {0, 3000, 2500, 2000, 1500, 1000, 500};
  const int lim[7] = {-1, n / 32, n / 16, n / 8, n / 4, n / 2, n};
  for (int a = 1; a <= 6; a++)
    if (lim[a - 1] < waa && waa - la <= lim[a])
      for (int b = 1; b <= 6; b++)
        if (lim[b - 1] < wab && wab - lb <= lim[b])
          for (int c = 1; c <= 6; c++)
            if (lim[c - 1] < wac && wac - lc <= lim[c]) {
              int sa = 0, sb = 0, sc = 0;
              f[0][0][0] = 0;
              int p = po[a] * ta[1] + po[b] * tb[1] + po[c] * tc[1];
              p += min(waa - lim[a - 1] - 1, la) * 100 * 250;
              p += min(wab - lim[b - 1] - 1, lb) * 100 * 250;
              p += min(wac - lim[c - 1] - 1, lc) * 100 * 250;
              for (int i = 2; i <= n; i++) {
                int pa = po[a] * ta[i];
                int pb = po[b] * tb[i];
                int pc = po[c] * tc[i];
                for (int ea = 0; ea <= sa; ea++)
                  for (int eb = 0; eb <= sb; eb++)
                    for (int ec = 0; ec <= sc; ec++) {
                      int k = f[ea][eb][ec];
                      upd(g[ea][eb][ec], k + (p >= (pa + pb + pc)));
                      if (hacka[i])
                        upd(g[ea + 1][eb][ec], k + (p >= (pb + pc)));
                      if (hackb[i])
                        upd(g[ea][eb + 1][ec], k + (p >= (pa + pc)));
                      if (hackc[i])
                        upd(g[ea][eb][ec + 1], k + (p >= (pa + pb)));
                      if (hacka[i] && hackb[i])
                        upd(g[ea + 1][eb + 1][ec], k + (p >= pc));
                      if (hacka[i] && hackc[i])
                        upd(g[ea + 1][eb][ec + 1], k + (p >= pb));
                      if (hackb[i] && hackc[i])
                        upd(g[ea][eb + 1][ec + 1], k + (p >= pa));
                      if (hacka[i] && hackb[i] && hackc[i])
                        upd(g[ea + 1][eb + 1][ec + 1], k + 1);
                    }
                sa += hacka[i];
                sb += hackb[i];
                sc += hackc[i];
                for (int ea = 0; ea <= sa; ea++)
                  for (int eb = 0; eb <= sb; eb++)
                    for (int ec = 0; ec <= sc; ec++)
                      f[ea][eb][ec] = g[ea][eb][ec], g[ea][eb][ec] = 0;
              }
              ans = max(ans, f[min(waa - lim[a - 1] - 1, la)]
                              [min(wab - lim[b - 1] - 1, lb)]
                              [min(wac - lim[c - 1] - 1, lc)]);
            }
  printf("%d", n - ans);
}
