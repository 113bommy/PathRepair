#include <bits/stdc++.h>
long long int C[100001], DT[100001], n, ans, bound;
long long int max(long long int a, long long int b) { return a > b ? a : b; }
int main() {
  scanf("%lld", &n);
  for (int i = 0, t; i < n; i++) scanf("%d", &t), C[t]++, bound = max(bound, t);
  for (int i = 0; i < 100001; i++)
    if (i == 0)
      DT[i] = C[i] * i;
    else if (i == 1)
      DT[i] = max(DT[0], C[i] * i);
    else
      DT[i] = max(DT[i - 2] + C[i] * i, DT[i - 2]);
  for (int i = 0; i < 100001; i++) ans = max(ans, DT[i]);
  printf("%lld", ans);
}
