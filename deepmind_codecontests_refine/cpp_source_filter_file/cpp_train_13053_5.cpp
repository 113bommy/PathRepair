#include <bits/stdc++.h>
using namespace std;
const int ma = 100005;
int rmq[ma][21], mc[ma << 1], s[ma << 1], ss[ma], fs[ma], ne[ma], extend[ma], i,
    j, g, k, n, m, an, l, r, mid, z, f[3][2], w;
char c;
int RMQ(int l, int r) {
  int z = floor(log(r - l + 1) / log(2));
  return mc[rmq[l][z]] > mc[rmq[l - (1 << z) + 1][z]]
             ? rmq[l][z]
             : rmq[l - (1 << z) + 1][z];
}
int midans(int L, int R) {
  for (l = 0, r = (R - L) >> 1; l < r;) {
    mid = l + r + 1 >> 1;
    if (mc[RMQ(L + mid, R - mid)] >= mid)
      l = mid, w = RMQ(L + mid, R - mid);
    else
      r = mid - 1;
  }
  return l;
}
int main() {
  do c = getchar();
  while (c < 'a' || c > 'z');
  while (c >= 'a' && c <= 'z') fs[g++] = c - 'a' + 1, c = getchar();
  s[0] = 27, fs[g] = 29;
  for (i = 0; i < g; i++) ss[i] = fs[g - i - 1];
  for (i = 0; i < g; i++) s[++ ++k] = ss[i];
  s[++ ++k] = 28;
  for (ne[0] = g, z = i = 1; i < g; i++) {
    ne[i] = min(max(0, z + ne[z] - i), ne[i - z]);
    if (i + ne[i] >= z + ne[z])
      for (z = i; ss[i + ne[i]] == ss[ne[i]]; ++ne[i])
        ;
  }
  for (z = 0, i = 0; i < g; i++) {
    extend[i] = min(max(0, z + extend[z] - i), ne[i - z]);
    if (i + extend[i] >= z + extend[z])
      for (z = i; fs[i + extend[i]] == ss[extend[i]]; ++extend[i])
        ;
  }
  for (mc[1] = 1, z = mc[2] = 2, i = 3; i < k; i++) {
    mc[i] = min(z + mc[z] - i, mc[(z << 1) - i]);
    while (s[i + mc[i]] == s[i - mc[i]]) ++mc[i];
    if (i + mc[i] > z + mc[z]) z = i;
  }
  for (i = 1; i <= g; i++) {
    mc[i] = mc[i << 1] >> 1, rmq[i][0] = i;
    if (an < (mc[i] << 1) - 1)
      an = (mc[i] << 1) - 1, f[0][0] = i - mc[i] + 1, f[0][1] = an;
  }
  for (j = 1; g >> j; j++)
    for (i = g - (1 << j) + 1; i; i--)
      rmq[i][j] = mc[rmq[i][j - 1]] > mc[rmq[i + (1 << j - 1)][j - 1]]
                      ? rmq[i][j - 1]
                      : rmq[i + (1 << j - 1)][j - 1];
  for (i = 0; i < g; i++)
    if (extend[i] && extend[i] << 1 < g - i) {
      z = midans(extend[i], g - (i + extend[i]) + 1);
      if (an < (extend[i] << 1) + (z << 1) - 1)
        an = (extend[i] << 1) + (z << 1) - 1, f[0][0] = 1,
        f[0][1] = f[2][1] = extend[i], f[2][0] = g - (i + extend[i]) + 1,
        f[1][0] = w - z + 1, f[1][1] = (z << 1) - 1;
    }
  if (f[1][0])
    j = 2;
  else
    j = 0;
  printf("%d\n", j + 1);
  for (; j + 1; j--) printf("%d %d\n", g - (f[j][0] + f[j][1]) + 2, f[j][1]);
  return 0;
}
