#include <bits/stdc++.h>
using namespace std;
const int N = 23, M = 1e5 + 5, Limit = 1100005, INF = 0x3f3f3f3f;
long long B[Limit], val[M], map[N][M], A[Limit];
char str[N][M];
void build(int len) {
  int n = 1 << len;
  for (int i = 0; i < n; i++) B[i] = B[i >> 1] + (i & 1);
  for (int i = 0; i < n; i++) B[i] = min(len - B[i], B[i]);
}
void FWT(long long a[], int len, int flag) {
  for (int i = 1; i < len; i <<= 1) {
    for (int j = 0; j < len; j += i << 1) {
      for (int k = 0; k < i; k++) {
        long long x = a[j + k], y = a[i + j + k];
        a[j + k] = x + y;
        a[i + j + k] = x - y;
        if (flag == 2) a[j + k] >>= 1, a[i + j + k] >>= 1;
      }
    }
  }
}
void Fast(long long a[], long long b[], int len) {
  FWT(a, len, 1);
  FWT(b, len, 1);
  for (int i = 0; i < len; i++) a[i] = a[i] * b[i];
  FWT(a, len, 2);
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  build(n);
  for (int i = 1; i <= n; i++) scanf("%s", str[i]);
  for (int i = 0; i < m; i++) {
    for (int j = n; j >= 1; j--) val[i] = (val[i] << 1) | (str[j][i] - '0');
    A[val[i]]++;
  }
  Fast(A, B, 1 << n);
  long long ans = INF;
  for (int i = 0; i < (1 << n); i++) ans = min(ans, A[i]);
  printf("%d\n", ans);
  return 0;
}
