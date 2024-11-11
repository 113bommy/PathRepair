#include <bits/stdc++.h>
using namespace std;
int read() {
  int x;
  scanf("%d", &x);
  return x;
}
int n, m;
int g[1000005];
int num[15];
int f[1000005][15];
int solve(int k) {
  memset(num, 0, sizeof(num));
  int t = 0, x = k, x1 = 1;
  while (x) {
    num[++t] = x % 10;
    x /= 10;
  }
  for (int i = 1; i <= t; i++)
    if (num[i] != 0) x1 *= num[i];
  if (!g[x1])
    return solve(x1);
  else
    return g[x1];
}
void readin() {
  for (int i = 1; i < 10; i++) g[i] = i;
  for (int i = 11; i <= 1000000; i++) {
    if (!g[i]) g[i] = solve(i);
  }
  for (int i = 1; i <= 1000000; i++) {
    for (int j = 1; j < 10; j++) f[i][j] = f[i - 1][j] + (g[i] == j);
  }
}
int q;
void work() {
  q = read();
  int l, r, k;
  for (int i = 1; i <= q; i++) {
    l = read(), r = read(), k = read();
    printf("%d\n", f[r][k] - f[l - 1][k]);
  }
}
int main() {
  readin();
  work();
  return 0;
}
