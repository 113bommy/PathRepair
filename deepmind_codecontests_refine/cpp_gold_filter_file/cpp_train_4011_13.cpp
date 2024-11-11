#include <bits/stdc++.h>
using namespace std;
int a[50], b[50], g[5][5];
int main() {
  long long sum, xr;
  scanf("%I64d%I64d", &sum, &xr);
  for (int i = 40; i >= 0; i--) a[i] = (sum >> i) & 1, b[i] = (xr >> i) & 1;
  for (int i = 40; i >= 0; i--)
    if ((a[i] & 1) != (b[i] & 1)) {
      if (i == 0) {
        printf("0\n");
        return 0;
      }
      a[i]--;
      a[i - 1] += 2;
      if (a[i] == -1) {
        printf("0\n");
        return 0;
      }
    }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) g[i + j][i ^ j]++;
  long long ans = 1;
  for (int i = 40; i >= 0; i--) ans = ans * g[a[i]][b[i]];
  if (sum == xr) ans -= 2;
  printf("%I64d\n", ans);
  return 0;
}
