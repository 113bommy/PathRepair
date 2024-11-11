#include <bits/stdc++.h>
using namespace std;
int n;
long long a[500100], A[500100], B[500100];
char s[500100];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  scanf("%s", s + 1);
  A[0] = B[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'A') {
      A[i] = A[i - 1] + a[i];
      B[i] = B[i - 1];
    } else {
      B[i] = B[i - 1] + a[i];
      A[i] = A[i - 1];
    }
  }
  long long ans = max(B[n], A[n]);
  for (int i = 1; i <= n; i++) {
    long long x = A[n] - A[i - 1];
    long long y = B[n] - B[i - 1];
    ans = max(ans, B[i - 1] + x);
    ans = max(ans, A[i - 1] + y);
  }
  printf("%I64d\n", ans);
  return 0;
}
