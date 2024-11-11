#include <bits/stdc++.h>
using namespace std;
long long f[61 + 1], g[61 + 1], x, k;
int Q, op, pos;
int main() {
  scanf("%d", &Q);
  f[0] = 1;
  for (int i = 1; i < 61; i++) f[i] = f[i - 1] * 2;
  while (Q--) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%I64d%I64d", &x, &k);
      for (int i = 0; i < 61; i++)
        if (f[i] >= x) {
          pos = i;
          break;
        } else
          x -= f[i];
      g[pos] = (g[pos] + k) % f[pos];
    }
    if (op == 2) {
      scanf("%I64d%I64d", &x, &k);
      for (int i = 0; i < 61; i++)
        if (f[i] >= x) {
          pos = i;
          break;
        } else
          x -= f[i];
      k %= f[pos];
      for (int i = pos; i < 61; i++) {
        g[i] = (g[i] + k) % f[i];
        k *= 2;
      }
    }
    if (op == 3) {
      scanf("%I64d", &x);
      printf("%I64d", x);
      long long tmp = x;
      for (int i = 0; i < 61; i++)
        if (f[i] >= x) {
          pos = i;
          break;
        } else
          x -= f[i];
      x = tmp;
      while (x != 1) {
        long long xx = x, fa;
        xx += g[pos];
        if (xx < f[pos]) xx += f[pos];
        if (xx >= f[pos + 1]) xx -= f[pos];
        fa = xx / 2;
        pos--;
        fa -= g[pos];
        if (fa < f[pos]) fa += f[pos];
        if (fa >= f[pos + 1]) fa -= f[pos];
        x = fa;
        printf(" %I64d", fa);
      }
      printf("\n");
    }
  }
}
