#include <bits/stdc++.h>
using namespace std;
int n, m, k, p[21];
char s1[21], s2[21], a[21], b[21];
int f[2][1 << 21], ans = 0, ansl, ansr;
int turn(char *s) {
  int re = 0;
  for (int i = 0; i < k; i++) re |= ((s[i] == '1') << i);
  return re;
}
int count(int x) {
  int re = 0;
  for (int i = 0; i < k; i++)
    if (x >> i & 1) re++;
  return re;
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  scanf("%s %s", s1, s2);
  for (int i = 0; i < k; i++) p[i] = i;
  for (int i = 0; i < (1 << k); i++) f[0][i] = 999999999, f[1][i] = -999999999;
  f[0][turn(s1)] = f[1][turn(s2)] = 0;
  for (int i = 1, x, y; i <= n; i++) {
    scanf("%d %d", &x, &y);
    x--;
    y--;
    swap(p[x], p[y]);
    for (int j = 0; j < k; j++) {
      a[p[j]] = s1[j];
      b[p[j]] = s2[j];
    }
    f[0][turn(a)] = min(f[0][turn(a)], i);
    f[1][turn(b)] = i;
  }
  for (int i = (1 << k) - 1; i >= 0; i--) {
    if (f[1][i] - f[0][i] >= m && count(i) > ans)
      ans = count(i), ansl = f[0][i] + 1, ansr = f[1][i];
    for (int j = 0; j < k; j++)
      if (i >> j & 1) {
        f[0][i ^ (1 << j)] = min(f[0][i ^ (1 << j)], f[0][i]);
        f[1][i ^ (1 << j)] = max(f[1][i ^ (1 << j)], f[1][i]);
      }
  }
  printf("%d\n%d %d", k + 2 * ans - count(turn(s1)) - count(turn(s2)), ansl,
         ansr);
}
