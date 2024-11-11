#include <bits/stdc++.h>
using namespace std;
const int MaxB = 3, MaxN = 7, MaxL = 1 << MaxN, MaxBuf = 128, MaxC = 0x3F3F3F3F,
          NA = -1;
const char name[MaxN][MaxBuf] = {"Anka",   "Chapay", "Cleo",       "Troll",
                                 "Dracul", "Snowy",  "Hexadecimal"};
bool a[MaxN][MaxN];
char buf[3][MaxBuf];
int x[MaxB];
int n;
int main(void) {
  int i, j, k, l, m, curx, cury, resx, resy;
  while (scanf(" %d", &n) != EOF) {
    memset(a, 0, sizeof(a));
    for (i = 0; i < n; i++) {
      scanf(" %s %s %s", buf[0], buf[1], buf[2]);
      assert(!strcmp(buf[1], "likes"));
      for (j = 0; j < MaxN; j++)
        if (!strcmp(buf[0], name[j])) break;
      assert(j < MaxN);
      for (k = 0; k < MaxN; k++)
        if (!strcmp(buf[2], name[k])) break;
      assert(k < MaxN);
      assert(j != k);
      a[j][k] = true;
    }
    scanf(" %d %d %d", &x[0], &x[1], &x[2]);
    resx = MaxC;
    resy = NA;
    for (i = 1; i < MaxL; i++)
      for (j = 1; j < MaxL; j++)
        if ((i & j) == 0)
          for (k = 1; k < MaxL; k++)
            if ((i & k) == 0)
              if ((j & k) == 0)
                if ((i | j | k) == MaxL - 1) {
                  cury = 0;
                  for (l = 0; l < MaxN; l++)
                    if (i & (1 << l))
                      for (m = 0; m < MaxN; m++)
                        if (i && (1 << m)) cury += a[l][m];
                  for (l = 0; l < MaxN; l++)
                    if (j & (1 << l))
                      for (m = 0; m < MaxN; m++)
                        if (j && (1 << m)) cury += a[l][m];
                  for (l = 0; l < MaxN; l++)
                    if (k & (1 << l))
                      for (m = 0; m < MaxN; m++)
                        if (k && (1 << m)) cury += a[l][m];
                  vector<int> v;
                  v.push_back(x[0] / __builtin_popcount(i));
                  v.push_back(x[1] / __builtin_popcount(j));
                  v.push_back(x[2] / __builtin_popcount(k));
                  sort(v.begin(), v.end());
                  curx = v[2] - v[0];
                  if (resx > curx || (resx == curx && resy < cury)) {
                    resx = curx;
                    resy = cury;
                  }
                }
    printf("%d %d\n", resx, resy);
  }
  return 0;
}
