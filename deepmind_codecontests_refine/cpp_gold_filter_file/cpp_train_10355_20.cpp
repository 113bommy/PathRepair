#include <bits/stdc++.h>
int DBG = 0;
using namespace std;
int HP[2], ATK[2], DEF[2], h, a, d;
bool Check(int x, int y, int z) {
  HP[0] += x;
  ATK[0] += y;
  DEF[0] += z;
  int d1 = max(0, ATK[0] - DEF[1]), d2 = max(0, ATK[1] - DEF[0]);
  int t1, t2;
  if (d1 > 0)
    t1 = HP[1] / d1 + (HP[1] % d1 > 0);
  else
    t1 = 1000000007;
  if (d2 > 0)
    t2 = HP[0] / d2 + (HP[0] % d2 > 0);
  else
    t2 = 1000000007;
  HP[0] -= x;
  ATK[0] -= y;
  DEF[0] -= z;
  return t2 > t1;
}
int main() {
  scanf("%d%d%d", &HP[0], &ATK[0], &DEF[0]);
  scanf("%d%d%d", &HP[1], &ATK[1], &DEF[1]);
  scanf("%d%d%d", &h, &a, &d);
  int res = 1000000007;
  for (int i = 0, _n = 1000; i < _n; ++i)
    for (int j = 0, _n = 201; j < _n; ++j)
      for (int k = 0, _n = 201; k < _n; ++k)
        if (Check(i, j, k)) {
          res = min(res, i * h + j * a + k * d);
        }
  printf("%d\n", res);
}
