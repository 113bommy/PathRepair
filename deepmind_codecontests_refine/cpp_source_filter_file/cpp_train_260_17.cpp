#include <bits/stdc++.h>
using namespace std;
int n, m;
void FWT(long long *a, int n) {
  for (int d = 1; d < n; d <<= 1) {
    for (int m = d << 1, i = 0; i < n; i += m) {
      for (int j = 0; j < d; ++j) {
        long long x = a[i + j], y = a[i + j + d];
        a[i + j] = x + y;
        a[i + j + d] = x - y;
      }
    }
  }
}
void UFWT(long long *a, int n) {
  for (int d = 1; d < n; d <<= 1) {
    for (int m = d << 1, i = 0; i < n; i += m) {
      for (int j = 0; j < d; ++j) {
        long long x = a[i + j], y = a[i + j + d];
        a[i + j] = (x + y) / 2;
        a[i + j + d] = (x - y) / 2;
      }
    }
  }
}
void Sovle(long long *a, long long *b, int n) {
  FWT(a, n);
  FWT(b, n);
  for (int i = 0; i < n; ++i) a[i] = a[i] * b[i];
  UFWT(a, n);
}
int a[20][100000];
long long A[1 << 20];
long long B[1 << 20];
int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%1d", &a[i][j]);
      }
    }
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    for (int j = 0; j < m; j++) {
      int sum = 0;
      for (int i = 0; i < n; i++) {
        sum <<= 1;
        sum |= a[i][j];
      }
      A[sum]++;
    }
    for (int i = 0; i < (1 << n); i++) {
      int cnt = 0;
      for (int j = 0; j < m; j++) {
        if ((i >> j) & 1) cnt++;
      }
      B[i] = min(cnt, n - cnt);
    }
    Sovle(A, B, 1 << n);
    long long ret = 20 * 100000;
    for (int i = 0; i < (1 << n); i++) ret = min(ret, A[i]);
    printf("%lld\n", ret);
  }
  return 0;
}
