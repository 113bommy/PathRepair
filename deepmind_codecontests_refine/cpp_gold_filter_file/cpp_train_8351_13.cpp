#include <bits/stdc++.h>
using namespace std;
const int M = 200;
int n, a[20][20], b[20], c[20][20], c1[20], c2[20], p[20], f[M][20], f1[M][20],
    f2[M][20];
long long ans[1 << 14];
char s[20];
inline void sol(int S, int o) {
  int m = 0;
  for (int i = (0); i < (n); ++i)
    if (S >> i & 1) b[m++] = i;
  for (int i = (0); i < (m); ++i)
    for (int j = (0); j < (m); ++j) c[i][j] = a[b[i]][b[j]];
  for (int i = (0); i < (m); ++i) p[i] = i;
  do {
    int t = 0;
    for (int i = (0); i < (m - 1); ++i) t = t << 1 | (c[p[i]][p[i + 1]]);
    if (o)
      f[t][b[p[0]]]++;
    else
      f[t][b[p[m - 1]]]++;
  } while (next_permutation(p, p + m));
}
int main() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) {
    scanf("%s", s);
    for (int j = (0); j < (n); ++j) a[i][j] = s[j] - '0';
  }
  int nn = 1 << n, n1 = n / 2, n2 = n - n1;
  int nn1 = 1 << (n1 - 1), nn2 = 1 << (n2 - 1);
  for (int S1 = (0); S1 < (nn); ++S1) {
    int s = 0, m1 = 0, m2 = 0;
    for (int j = (0); j < (n); ++j)
      if (S1 >> j & 1) s++;
    if (s != n1) continue;
    int S2 = ((1 << n) - 1) ^ S1;
    sol(S1, 0);
    for (int i = (0); i < (nn1); ++i)
      for (int j = (0); j < (n); ++j) f1[i][j] = f[i][j], f[i][j] = 0;
    sol(S2, 1);
    for (int i = (0); i < (nn2); ++i)
      for (int j = (0); j < (n); ++j) f2[i][j] = f[i][j], f[i][j] = 0;
    for (int i = (0); i < (n); ++i)
      if (S1 >> i & 1) c1[m1++] = i;
    for (int i = (0); i < (n); ++i)
      if (S2 >> i & 1) c2[m2++] = i;
    for (int t1 = (0); t1 < (m1); ++t1)
      for (int t2 = (0); t2 < (m2); ++t2) {
        int o1 = c1[t1], o2 = c2[t2], t = a[o1][o2];
        for (int i = (0); i < (nn1); ++i)
          if (f1[i][o1]) {
            int o = (i << 1 | t) << (n2 - 1), w = f1[i][o1];
            for (int j = (0); j < (nn2); ++j)
              if (f2[j][o2]) ans[o | j] += 1ll * w * f2[j][o2];
          }
      }
  }
  nn = 1 << (n - 1);
  for (int i = (0); i < (nn); ++i) printf("%lld ", ans[i]);
  return 0;
}
