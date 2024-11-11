#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    double sum1 = 0, sum2 = 0;
    for (int j = 0; j < 250; j++) {
      long long x;
      scanf("%lld", &x);
      sum1 += x, sum2 += x * x;
    }
    sum1 /= 250;
    sum2 /= 250;
    sum2 -= sum1 * sum1;
    if (sum2 / sum1 > 1)
      printf("uniform\n");
    else
      printf("poisson\n");
  }
  return 0;
}
