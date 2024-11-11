#include <bits/stdc++.h>
using namespace std;
typedef int arr[52][52];
arr a;
long long step;
int b[52], p[1000];
int n, cnt;
void matrixmul1(arr a, arr b, arr c) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++) c[i][j] = (c[i][j] + a[i][k] * b[k][j]) & 1;
}
void matrixmul2(int a[], arr b, int c[]) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) c[i] = (c[i] + a[j] * b[j][i]) & 1;
}
bool matrixpow(long long p) {
  arr m, res, tmp;
  int c[52];
  memcpy(m, a, sizeof(m));
  memset(res, 0, sizeof(res));
  for (int i = 1; i <= n; i++) res[i][i] = 1;
  for (; p; p >>= 1) {
    if (p & 1)
      memset(tmp, 0, sizeof(tmp)), matrixmul1(res, m, tmp),
          memcpy(res, tmp, sizeof(tmp));
    memset(tmp, 0, sizeof(tmp)), matrixmul1(m, m, tmp),
        memcpy(m, tmp, sizeof(tmp));
  }
  memset(c, 0, sizeof(c));
  matrixmul2(b, res, c);
  for (int i = 1; i <= n; i++)
    if (b[i] != c[i]) return 0;
  return 1;
}
bool check() {
  if (!matrixpow(step)) return 0;
  for (int i = 1; i <= cnt; i++)
    if (matrixpow(step / p[i])) return 0;
  return 1;
}
int main() {
  scanf("%d", &n);
  srand(time(0));
  step = (1ll << n) - 1;
  long long x = step;
  for (int i = 2; 1ll * i * i <= x; i++)
    if (x % i == 0) {
      p[++cnt] = i;
      for (; x % i == 0; x /= i)
        ;
    }
  if (x > 1) p[++cnt] = x;
  for (int i = 1; i <= n; i++) b[i] = 1;
  for (int i = 1; i < n; i++) a[i][i + 1] = 1;
  for (;;) {
    for (int i = 1; i <= n; i++) a[n][i] = rand() % 2;
    if (check()) break;
  }
  for (int i = 1; i <= n; i++) printf("%d ", a[n][i]);
  printf("\n");
  for (int i = 1; i <= n; i++) printf("1 ");
  printf("\n");
}
