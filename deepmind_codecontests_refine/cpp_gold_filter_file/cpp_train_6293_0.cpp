#include <bits/stdc++.h>
using namespace std;
double szh[100100];
double szz[500];
int numx;
int maxz;
int len;
int main() {
  double ans;
  int f1;
  int f2;
  scanf("%d%d%d", &len, &maxz, &numx);
  szh[numx] = 0;
  for (f1 = numx - 1; f1 >= 0; f1--)
    szh[f1] = szh[f1 + 1] + log(maxz - f1) - log(numx - f1);
  szz[0] = 0;
  for (f1 = 1; f1 <= len; f1++)
    szz[f1] = szz[f1 - 1] + log(len - f1 + 1) - log(f1);
  ans = 0;
  for (f1 = 0; f1 <= len; f1++)
    for (f2 = 0; f2 <= len; f2++)
      if ((f1 + f2) * len - f1 * f2 <= numx)
        ans += exp(szz[f1] + szz[f2] + szh[(f1 + f2) * len - f1 * f2] - szh[0]);
  if (ans > 1e99)
    printf("1e99\n");
  else
    printf("%.12lf\n", ans);
  return 0;
}
