#include <bits/stdc++.h>
using namespace std;
int n, d, m;
int a[1000];
int main() {
  while (scanf("%d%d", &n, &d) != EOF) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    scanf("%d", &m);
    int k = min(n, m);
    int sum = 0;
    for (int i = 1; i <= k; i++) {
      sum += a[i];
    }
    sum += (m - k) * (-d);
    printf("%d\n", sum);
  }
  return 0;
}
