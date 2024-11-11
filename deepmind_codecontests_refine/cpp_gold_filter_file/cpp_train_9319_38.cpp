#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[1005], b[1005], n, result = -1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) scanf("%d", b + i);
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++) {
      int sum1 = a[j], sum2 = b[j];
      for (int k = j + 1; k <= i; k++) sum1 |= a[k], sum2 |= b[k];
      result = max(result, sum1 + sum2);
    }
  printf("%d", result);
}
