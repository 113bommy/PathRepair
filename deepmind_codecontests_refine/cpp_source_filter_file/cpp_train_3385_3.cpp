#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const int M = 2e6 + 7;
const int inf = 1e9;
int n, m, mx, p[N], minn[N], D[M][2], sum = 0;
int a[N][N];
bool check() {
  for (int t = 0, tE = (1 << mx) - 1; t <= tE; t++) {
    int ds = 0, bs = 0;
    for (int i = 1, iE = mx; i <= iE; i++)
      if (t & (1 << (i - 1))) ds += p[i];
    if (!ds) continue;
    for (int i = 1, iE = mx; i <= iE; i++)
      if (t & (1 << (i - 1)))
        for (int j = 1, jE = mx; j <= jE; j++)
          if (t & (1 << (j - 1))) bs += a[i][j];
    if (bs >= ds) return 0;
  }
  return 1;
}
int Cnt(int x) { return x == 0 ? 0 : Cnt(x / 10) + 1; }
char sa[N], sb[N];
bool get() {
  for (int x = 1, xE = mx; x <= xE; x++)
    for (int i = 1, iE = mx; i <= iE; i++)
      if (a[x][i]) {
        if (p[i] > 0) {
          a[x][i]--, p[x]--;
          if (check()) return printf("%d %d\n", minn[x] + p[x], minn[i]), 1;
          a[x][i]++, p[x]++;
        }
        if (p[i] > 0) {
          a[x][i]--, p[i]--;
          if (check()) return printf("%d %d\n", minn[x], minn[i] + p[i]), 1;
          a[x][i]++, p[i]++;
        }
      }
  return 0;
}
int main() {
  scanf("%d", &n), mx = Cnt(n);
  for (int i = 1, iE = n; i <= iE; i++) p[Cnt(i)]++;
  minn[1] = 1;
  for (int i = 2, iE = mx; i <= iE; i++) minn[i] = minn[i - 1] * 10;
  for (int i = 1, iE = n - 1; i <= iE; i++)
    scanf("%s%s", sa, sb), D[i][0] = strlen(sa), D[i][1] = strlen(sb),
                           a[D[i][0]][D[i][1]]++;
  if (!check()) return puts("-1"), 0;
  while (get()) sum++;
  return 0;
}
