#include <bits/stdc++.h>
long long A[21];
int main() {
  int n;
  int a;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    A[a + 10]++;
  }
  long long ans = 0LL;
  for (int i = 0; i <= 10; i++) {
    if (i == 0)
      ans += A[i + 10] * (A[i + 10] - 1LL) / 2LL;
    else {
      int x = i + 10;
      int y = -i + 10;
      ans += A[x] * A[y];
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
