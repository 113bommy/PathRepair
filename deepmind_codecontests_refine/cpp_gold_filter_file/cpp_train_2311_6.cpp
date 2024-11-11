#include <bits/stdc++.h>
using namespace std;
const int maxn = 15;
int ss[maxn][maxn], tot;
int to[maxn * maxn];
double f[maxn * maxn];
void init() {
  for (register int i = 10; i; i--)
    if (i & 1)
      for (register int j = 10; j; j--) ss[i][j] = ++tot;
    else
      for (register int j = 1; j <= 10; j++) ss[i][j] = ++tot;
}
int main() {
  int x;
  init();
  for (register int i = 1; i <= 10; i++)
    for (register int j = 1; j <= 10; j++) {
      scanf("%d", &x);
      to[ss[i][j]] = ss[i - x][j];
    }
  for (register int i = 99; i >= 94; i--) f[i] = 6;
  for (register int i = 93; i; i--) {
    for (register int j = i + 1; j <= i + 6; j++) f[i] += min(f[j], f[to[j]]);
    f[i] = f[i] / 6.0 + 1;
  }
  printf("%.10lf\n", f[1]);
  return 0;
}
