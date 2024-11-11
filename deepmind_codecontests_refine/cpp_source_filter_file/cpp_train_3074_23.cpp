#include <bits/stdc++.h>
using namespace std;
const int maxl = 32;
long long SUM, X, ans;
int a[40], b[40];
long long f[40][2];
int main() {
  scanf("%I64d%I64d", &SUM, &X);
  if (SUM == X)
    ans -= 2;
  else
    ans = 0;
  for (int i = 1; i <= maxl; i++) a[i] = SUM & 1, SUM >>= 1;
  for (int i = 1; i <= maxl; i++) b[i] = X & 1, X >>= 1;
  f[0][0] = 1;
  for (int i = 0; i < maxl; i++)
    for (int j = 0; j < 2; j++)
      if (f[i][j])
        for (int t1 = 0; t1 < 2; t1++)
          for (int t2 = 0; t2 < 2; t2++)
            if (((t1 + t2 + j) & 1) == a[i + 1] && (t1 ^ t2) == b[i + 1])
              f[i + 1][(t1 + t2 + j) >> 1] += f[i][j];
  ans += f[maxl][0];
  printf("%I64d", ans);
}
