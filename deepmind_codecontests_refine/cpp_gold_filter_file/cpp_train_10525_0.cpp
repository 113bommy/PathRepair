#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N], b[N];
int x[N];
int main() {
  int n;
  long long t;
  scanf("%d %I64d", &n, &t);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  for (int i = 2; i <= n; i++) {
    if (x[i] < max(x[i - 1], i)) {
      printf("No\n");
      return 0;
    }
  }
  for (int i = 1, j; i <= n; i = j) {
    j = i;
    while (j <= n && x[j] == x[i]) j++;
    for (int k = i; k < j; k++) {
      if (x[k] > k)
        b[k] = a[k + 1] + t;
      else
        b[k] = max(b[k - 1] + 1, a[k] + t);
    }
    if (x[j - 1] != j - 1 || (j <= n && b[j - 1] >= a[j] + t)) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  for (int i = 1; i <= n; i++) printf("%I64d ", b[i]);
  printf("\n");
  return 0;
}
