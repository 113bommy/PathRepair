#include <bits/stdc++.h>
using namespace std;
const int maxN = 200 + 10;
int N, L, K;
double p[maxN], f1[maxN], now[maxN][maxN], last[maxN][maxN];
int a[maxN], n1[maxN], n2[maxN];
int main() {
  scanf("%d %d %d", &N, &L, &K);
  int x;
  for (int i = 0; i < N; ++i) scanf("%d", &x), p[i] = (double)x / 100;
  ;
  int l1 = 0, l2 = 0;
  for (int i = 0; i < N; ++i) {
    scanf("%d", &a[i]);
    if (a[i] == -1)
      n1[l1++] = i;
    else
      n2[l2++] = i;
  }
  for (int i = 0; i < l1 + 1; ++i) f1[i] = 0;
  f1[0] = 1;
  for (int i = 0; i < l1; ++i)
    for (int j = i + 2 - 1; j >= 0; --j)
      if (j == 0)
        f1[j] *= 1 - p[n1[i]];
      else
        f1[j] = f1[j - 1] * p[n1[i]] + f1[j] * (1 - p[n1[i]]);
  last[0][0] = 1;
  for (int i = 0; i < l2; ++i) {
    for (int j = 0; j < l1 + 1; ++j)
      for (int k = 0; k < i + 1; ++k) now[j][k] = last[j][k] * (1 - p[n2[i]]);
    for (int j = 0; j < l1 + 1; ++j)
      for (int k = 0; k < i + 1; ++k)
        now[(l1 < j + a[n2[i]] ? l1 : j + a[n2[i]])][k + 1] +=
            last[j][k] * p[n2[i]];
    for (int j = 0; j < l1 + 1; ++j)
      for (int k = 0; k < i + 2; ++k) last[j][k] = now[j][k];
  }
  double ans = 0;
  for (int i = 0; i < l1 + 1; ++i)
    for (int j = (0 > i - K ? 0 : i - K); j <= l1; ++j)
      for (int k = (0 > L - i ? 0 : L - i); k <= l2; ++k)
        ans += f1[i] * last[j][k];
  printf("%.8lf\n", ans);
  return 0;
}
