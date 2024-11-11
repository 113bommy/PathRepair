#include <bits/stdc++.h>
using namespace std;
int getint() {
  char c;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    ;
  int t = c - 48;
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) t = t * 10 + c - 48;
  return t;
}
void putint(int n) {
  char a[9];
  int size = 0;
  if (n == 0) putchar('0');
  while (n) {
    a[size++] = n % 10 + 48;
    n /= 10;
  }
  for (int i = size - 1; i >= 0; i--) putchar(a[i]);
  putchar('\n');
}
const int MO = 1e9 + 7;
struct mat {
  int p[101][101];
  mat() { memset(p, 0, sizeof(p)); }
  mat operator*(const mat& A) const {
    mat B;
    for (int i = 0; i <= 100; i++)
      for (int j = 0; j <= 100; j++)
        for (int k = 0; k <= 100; k++)
          B.p[i][j] = ((long long)p[i][k] * A.p[k][j] % MO + B.p[i][j]) % MO;
    return B;
  }
};
mat po(mat x, int y) {
  mat t;
  for (int i = 0; i <= 100; i++) t.p[i][i] = 1;
  for (; y; y >>= 1) {
    if (y & 1) t = t * x;
    x = x * x;
  }
  return t;
}
int n, t, x, a[200];
mat A, B;
int main() {
  scanf("%d%d", &n, &x);
  if (x == 0) {
    puts("1");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t);
    a[t]++;
  }
  for (int i = 0; i < 100; i++) B.p[i][0] = a[i + 1];
  for (int i = 0; i < 100; i++) B.p[i][i + 1] = 1;
  A.p[0][0] = A.p[0][100] = B.p[100][100] = B.p[100][0] = 1;
  B = po(B, x);
  A = A * B;
  printf("%d\n", A.p[0][0]);
  return 0;
}
