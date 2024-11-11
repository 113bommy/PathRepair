#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 20;
double p[30];
pair<double, double> f[maxn];
int n, m, k;
inline int num(int j) {
  int t = 0;
  for (int i = 0; i < n; i++)
    if (j & (1 << i)) t++;
  return t;
}
int main() {
  int s;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lf", p + i);
  s = 0;
  for (int i = 0; i < n; i++)
    if (p[i] != 0) s++;
  if (s < k) {
    for (int i = 0; i < n; i++)
      if (p[i] != 0)
        printf("1 ");
      else
        printf("0 ");
    return 0;
  }
  m = 1 << n;
  for (int i = 0; i < m; i++) {
    f[i].second = 0;
    for (int j = 1, t = 0; t < n; t++, j <<= 1)
      if (i & j) f[i].second += p[t];
  }
  for (int i = 0; i < n; i++) f[1 << i].first = p[i];
  for (int i = 1; i < k; i++)
    for (int j = 1; j < m; j++)
      if (num(j) == i) {
        for (int k = 0; k < n; k++)
          if (!(j & (1 << k))) {
            f[j | (1 << k)].first += f[j].first / (1 - f[j].second) * p[k];
          }
      }
  for (int i = 0; i < n; i++) {
    double ret = 0;
    for (int j = 1; j < m; j++)
      if (num(j) == k && j & (1 << i)) ret += f[j].first;
    printf("%.9lf ", ret);
  }
  puts("");
}
