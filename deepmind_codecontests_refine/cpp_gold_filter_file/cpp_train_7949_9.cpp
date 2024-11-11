#include <bits/stdc++.h>
int d[10];
int C[10];
const int MOD = 1000000007;
void count(int n, int (&d)[10]) {
  memset(d, 0, sizeof(d));
  if (n == 0) {
    d[0] = 1;
    return;
  }
  int i;
  for (i = 9; i >= 1; i--)
    if (n >= C[i]) break;
  int e[10];
  count(C[i] - 1, e);
  int m = n / C[i];
  for (int j = 0; j < m; j++) {
    if (j == 4 || j == 7) {
      for (int k = 1; k < 10; k++) d[k] += e[k - 1];
    } else {
      for (int k = 0; k < 10; k++) d[k] += e[k];
    }
  }
  count(n % C[i], e);
  if (m == 4 || m == 7) {
    for (int k = 1; k < 10; k++) d[k] += e[k - 1];
  } else {
    for (int k = 0; k < 10; k++) d[k] += e[k];
  }
}
int P(int n, int m) {
  int r = 1;
  for (int i = n; i > n - m; i--) {
    r = (long long)r * i % MOD;
  }
  return r;
}
int f[10][10][10];
int mm(int x, int c, int m) {
  if (~f[x][c][m]) return f[x][c][m];
  if (x == 0) {
    if (c <= d[0]) return f[x][c][m] = P(d[0], c);
    return f[x][c][m] = 0;
  }
  int r = 0;
  for (int i = 0; i <= c && i <= d[x] && i * x <= m; i++) {
    int t = (long long)mm(x - 1, c - i, m - i * x) * P(d[x], i) % MOD *
            (P(c, i) / P(i, i)) % MOD;
    r = (r + t) % MOD;
  }
  return f[x][c][m] = r;
}
int cc(int n) {
  int c = 0;
  while (n > 0) {
    int t = n % 10;
    if (t == 4 || t == 7) c++;
    n /= 10;
  }
  return c;
}
void test() {
  int d[10] = {1};
  for (int i = 1; i <= 1000000000; i++) {
    if (i % 10000 == 0) printf("%d\n", i);
    int e[10];
    count(i, e);
    int c = cc(i);
    for (int j = 0; j < 10; j++) {
      if (j == c && e[j] != d[j] + 1 || j != c && e[j] != d[j]) {
        printf("ss%d\n", i);
        while (1) {
        }
      }
    }
    memcpy(d, e, sizeof(d));
  }
  puts("aa");
}
int main() {
  C[1] = 1;
  for (int i = 2; i <= 9; i++) C[i] = C[i - 1] * 10;
  memset(f, -1, sizeof(f));
  int n;
  scanf("%d", &n);
  count(n, d);
  d[0]--;
  int dd[10] = {6, 2, 1};
  int ans = 0;
  for (int i = 1; i < 10; i++) {
    if (d[i] >= 1) {
      int t = (long long)mm(i - 1, 6, i - 1) * d[i] % MOD;
      ans = (ans + t) % MOD;
    }
  }
  printf("%d\n", ans);
  return 0;
}
