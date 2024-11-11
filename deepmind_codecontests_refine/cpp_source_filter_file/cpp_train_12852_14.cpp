#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a[100000];
  while (scanf("%d %d", &n, &k) == 2) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int m = (n % k == 0) ? n / k : n % k;
    int sum = 0;
    for (int j = m - 1; j < n; j += k) {
      sum += 2 * (a[j] - 1);
    }
    printf("%d\n", sum);
  }
  return 0;
}
