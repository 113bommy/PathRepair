#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main() {
  int i, j, fl, test;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  long long sum = 0;
  sort(a, a + n);
  for (i = n - 1; i >= 0; i--) {
    if (i == n - 1)
      sum += a[i];
    else {
      if (a[i] >= a[i + 1]) {
        a[i] = a[i + 1] - 1;
        if (a[i] <= 0) break;
      }
      sum += a[i];
    }
  }
  printf("%lld\n", sum);
  return 0;
}
