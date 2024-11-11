#include <bits/stdc++.h>
using namespace std;
long long int x[1000500];
int main() {
  long long int sum, n, i, r, t;
  while (~scanf("%lld", &n)) {
    sum = 0;
    memset(x, 0, sizeof(x));
    for (i = 0; i < n; i++) {
      scanf("%lld", &r);
      x[r]++;
    }
    for (i = 0; i <= 1000000; i++) {
      t = x[i] % 2;
      x[i + 1] = x[i + 1] + x[i] / 2;
      sum = t + sum;
    }
    printf("%lld\n", sum);
  }
}
