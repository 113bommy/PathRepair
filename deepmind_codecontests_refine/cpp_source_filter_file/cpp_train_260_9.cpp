#include <bits/stdc++.h>
using namespace std;
void FWT(long long a[], int l, int on) {
  for (int d = 1; d < l; d <<= 1) {
    for (int m = d << 1, i = 0; i < l; i += m) {
      for (int j = 0; j < d; j++) {
        int x = a[i + j], y = a[i + j + d];
        a[i + j] = x + y;
        a[i + j + d] = x - y;
        if (on < 0) {
          a[i + j] >>= 1;
          a[i + j + d] >>= 1;
        }
      }
    }
  }
}
int n, m;
char str[100005];
int A[100005];
long long num[1 << 21];
long long B[1 << 21];
long long C[1 << 21];
int main() {
  scanf("%d%d", &n, &m);
  long long ans = n * m;
  for (int i = 1, x; i <= n; i++) {
    scanf("%s", str + 1);
    for (int j = 1; j <= m; j++) {
      x = str[j] - '0';
      A[j] = (A[j] << 1) + x;
    }
  }
  for (int i = 1; i <= m; i++) {
    num[A[i]]++;
  }
  int l = (1 << n);
  for (int i = 0; i < l; i++) {
    B[i] = B[i >> 1] + (i & 1);
    C[i] = min(B[i], n - B[i]);
  }
  FWT(num, l, 1);
  FWT(C, l, 1);
  for (int i = 0; i < l; i++) {
    C[i] = C[i] * num[i];
  }
  FWT(C, l, -1);
  for (int i = 0; i < l; i++) {
    ans = min(ans, C[i]);
  }
  printf("%I64d\n", ans);
  return 0;
}
