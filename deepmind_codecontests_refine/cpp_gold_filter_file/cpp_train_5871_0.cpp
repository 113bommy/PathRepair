#include <bits/stdc++.h>
using namespace std;
int n, num[205], P, N, Z, ans, mn = 1001, sum;
int main() {
  scanf("%d", &n);
  n = 2 * n - 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &num[i]);
    if (num[i] < 0) N++, num[i] = -num[i];
    mn = min(mn, num[i]);
    sum += num[i];
  }
  if ((n + 1) % 4 == 0 && N % 2 == 1)
    printf("%d\n", sum - 2 * mn);
  else
    printf("%d\n", sum);
  return 0;
}
