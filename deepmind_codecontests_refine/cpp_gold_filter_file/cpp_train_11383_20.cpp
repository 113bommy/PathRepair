#include <bits/stdc++.h>
int N, i, l, r, mid;
int f[20];
long long A[100005];
int main() {
  f[0] = 1;
  for (i = 1; i <= 19; ++i) f[i] = f[i - 1] * 2;
  scanf("%d", &N);
  for (i = 1; i <= N; ++i) scanf("%I64d", &A[i]);
  for (i = 1; i <= N; ++i) {
    for (l = 0, r = 19; l < r;) {
      mid = (l + r + 1) / 2;
      if (i + f[mid] <= N)
        l = mid;
      else
        r = mid - 1;
    }
    mid = (l + r + 1) / 2;
    A[i + f[mid]] += A[i];
  }
  for (i = 2; i <= N; ++i) A[i] += A[i - 1];
  for (i = 1; i < N; ++i) printf("%I64d\n", A[i]);
  return 0;
}
