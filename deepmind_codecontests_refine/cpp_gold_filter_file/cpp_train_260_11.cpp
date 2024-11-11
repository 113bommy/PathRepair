#include <bits/stdc++.h>
using namespace std;
inline int getint() {
  int num = 0, flag = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = -1;
  while (c >= '0' && c <= '9') num = num * 10 + c - 48, c = getchar();
  return num * flag;
}
int n, m;
long long ans = 0;
char s[22][100005];
long long A[1 << 22], B[1 << 22];
inline void FWT_xor(long long *a, int inv) {
  for (int mid = 1; mid < n; mid <<= 1)
    for (int j = 0, tmp = mid << 1; j < n; j += tmp)
      for (int k = 0; k < mid; ++k) {
        long long x = a[j + k], y = a[mid + j + k];
        a[j + k] = x + y, a[mid + j + k] = x - y;
        if (inv == -1) a[j + k] /= 2, a[mid + j + k] /= 2;
      }
}
int main() {
  n = getint(), m = getint();
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < m; i++) {
    int tmp = 0;
    for (int j = 0; j < n; j++) tmp |= (s[j][i] - 48) << j;
    A[tmp]++;
  }
  for (int i = 0; i < (1 << n); i++) {
    int tmp = i, num = 0;
    while (tmp) num += tmp & 1, tmp >>= 1;
    B[i] = min(num, n - num);
  }
  n = 1 << n;
  FWT_xor(A, 1), FWT_xor(B, 1);
  for (int i = 0; i < n; i++) A[i] *= B[i];
  FWT_xor(A, -1);
  ans = 0x3f3f3f3f3f3f3f3fll;
  for (int i = 0; i < n; i++) ans = min(ans, A[i]);
  printf("%I64d\n", ans);
}
