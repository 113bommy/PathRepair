#include <bits/stdc++.h>
using namespace std;
const int N = 5005, M = 95;
int n, T[N][5], fl[N][5];
int PP[5], GG[5], ans;
int f[M][M][M];
int g[M][M][M];
void UPD(int &x, int y) { x < y ? x = y : 233; }
int main() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(3); j++) {
      scanf("%d", &T[i][j]);
      if (T[i][j] == 0)
        T[i][j] = 250;
      else {
        ++PP[j];
        if (T[i][j] < 0) {
          ++GG[j];
          fl[i][j] = 1;
          T[i][j] *= -1;
        }
      }
      T[i][j] = 250 - T[i][j];
    }
  if (PP[1] + PP[2] + PP[3] >= 90) return puts("1"), 0;
  const int P[] = {0, 3000, 2500, 2000, 1500, 1000, 500};
  const int lim[] = {-1, n / 32, n / 16, n / 8, n / 4, n / 2, n};
  for (int a = (int)(1); a <= (int)(6); a++)
    if (PP[1] > lim[a - 1] && PP[1] - GG[1] <= lim[a])
      for (int b = (int)(1); b <= (int)(6); b++)
        if (PP[2] > lim[b - 1] && PP[2] - GG[2] <= lim[b])
          for (int c = (int)(1); c <= (int)(6); c++)
            if (PP[3] > lim[c - 1] && PP[3] - GG[3] <= lim[c]) {
              int p = P[a] * T[1][1] + P[b] * T[1][2] + P[c] * T[1][3];
              int la = min(GG[1], PP[1] - lim[a - 1] - 1), sa = 0;
              int lb = min(GG[2], PP[2] - lim[b - 1] - 1), sb = 0;
              int lc = min(GG[3], PP[3] - lim[c - 1] - 1), sc = 0;
              p += (la + lb + lc) * 250 * 100;
              int stk = 0;
              memset(f, 0, sizeof(f));
              memset(g, 0, sizeof(g));
              for (int i = (int)(2); i <= (int)(n); i++) {
                int va = P[a] * T[i][1];
                int vb = P[b] * T[i][2];
                int vc = P[c] * T[i][3];
                if (!fl[i][1] && !fl[i][2] && !fl[i][3]) {
                  stk += (p >= (va + vb + vc));
                  continue;
                }
                for (int Sa = (int)(0); Sa <= (int)(sa); Sa++)
                  for (int Sb = (int)(0); Sb <= (int)(sb); Sb++)
                    for (int Sc = (int)(0); Sc <= (int)(sc); Sc++) {
                      UPD(g[Sa][Sb][Sc], f[Sa][Sb][Sc] + (p >= (va + vb + vc)));
                      if (fl[i][1])
                        UPD(g[Sa + 1][Sb][Sc],
                            f[Sa][Sb][Sc] + (p >= (vb + vc)));
                      if (fl[i][2])
                        UPD(g[Sa][Sb + 1][Sc],
                            f[Sa][Sb][Sc] + (p >= (va + vc)));
                      if (fl[i][3])
                        UPD(g[Sa][Sb][Sc + 1],
                            f[Sa][Sb][Sc] + (p >= (va + vb)));
                      if (fl[i][1] && fl[i][2])
                        UPD(g[Sa + 1][Sb + 1][Sc], f[Sa][Sb][Sc] + (p >= vc));
                      if (fl[i][1] && fl[i][3])
                        UPD(g[Sa + 1][Sb][Sc + 1], f[Sa][Sb][Sc] + (p >= vb));
                      if (fl[i][2] && fl[i][3])
                        UPD(g[Sa][Sb + 1][Sc + 1], f[Sa][Sb][Sc] + (p >= va));
                      if (fl[i][1] && fl[i][2] && fl[i][3])
                        UPD(g[Sa + 1][Sb + 1][Sc + 1],
                            f[Sa][Sb][Sc] + (p >= 0));
                    }
                sa = min(sa + fl[i][1], la);
                sb = min(sb + fl[i][2], lb);
                sc = min(sc + fl[i][3], lc);
                for (int Sa = (int)(0); Sa <= (int)(sa); Sa++)
                  for (int Sb = (int)(0); Sb <= (int)(sb); Sb++)
                    for (int Sc = (int)(0); Sc <= (int)(sc); Sc++) {
                      f[Sa][Sb][Sc] = g[Sa][Sb][Sc];
                      g[Sa][Sb][Sc] = 0;
                    }
              }
              ans = max(ans, f[la][lb][lc] + stk);
            }
  printf("%d\n", n - ans);
}
