#include <bits/stdc++.h>
const int MOD = 1e9 + 9;
int A[3600], p, a, len, n = 0;
char B[3600];
int f[3600][3600][2][2];
void reverse(int *a, int l) {
  for (int i = 1, j = l, tmp; i < j; i++, j--) {
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
  }
}
void reverse(char *a, int l) {
  char tmp;
  for (int i = 1, j = l; i < j; i++, j--) {
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
  }
}
int div(char *a, int p) {
  int r = 0;
  for (int i = len; i; i--) {
    long long bak = r * 10LL + a[i];
    r = bak % p;
    a[i] = bak / p;
  }
  for (; len && !a[len]; len--)
    ;
  return r;
}
int mul(int a, int b) { return a * 1ll * b % MOD; }
int dec(int a, int b) { return (a - b + MOD) % MOD; }
int gp(int c, int r, int nr) {
  if (r) return dec(p, gp(c, 0, nr));
  return c - nr + 1;
}
int gs(int c, int r, int nr) {
  if (r) return dec(mul(c + 1, p), gs(c, 0, nr));
  if (c & 1) return dec(mul(c + 2, (c + 1) >> 1), nr * (c + 1));
  return dec(mul(c + 1, (c + 2) >> 1), nr * (c + 1));
}
int strlen(char *a) {
  int n = 0;
  while (*a != '\0') {
    n++;
    a++;
  }
  return n;
}
void inc(int &a, int b) { a = (a + b) % MOD; }
int main() {
  scanf("%d %d", &p, &a);
  scanf("%s", B + 1);
  len = strlen(B + 1);
  for (int i = 1; i <= len; i++) B[i] -= 48;
  reverse(B, len);
  for (; len;) A[++n] = div(B, p);
  reverse(A, n);
  if (a > n) {
    printf("0\n");
    return 0;
  }
  f[1][0][1][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= a; j++)
      for (int eq = 0; eq < 2; eq++)
        for (int rem = 0; rem < 2; rem++)
          if (f[i][j][eq][rem]) {
            int cur = f[i][j][eq][rem];
            for (int nr = 0; nr < 2; nr++) {
              int nj = (((j + nr) < (a)) ? (j + nr) : (a));
              if (!eq)
                inc(f[i + 1][nj][eq][nr], mul(cur, gs(p - 1, rem, nr)));
              else {
                inc(f[i + 1][nj][eq][nr], mul(cur, gp(A[i], rem, nr)));
                if (A[i])
                  inc(f[i + 1][nj][0][nr], mul(cur, gs(A[i] - 1, rem, nr)));
              }
            }
          }
  int ans = 0;
  for (int eq = 0; eq < 2; eq++) inc(ans, f[n + 1][a][eq][0]);
  printf("%d\n", ans);
  return 0;
}
