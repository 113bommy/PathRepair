#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main() {
  int n;
  long long sum;
  while (scanf("%d", &n) != EOF) {
    sum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (i == 1)
        sum += abs(a[i]);
      else if (a[i] != a[i - 1])
        sum += abs(a[i] - a[i - 1]);
    }
    printf("%I64d\n", sum);
  }
  return 0;
}
