#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  int a, b;
  long long yu, sumyu, sumchai, sum;
  scanf("%lld%lld%d%d", &n, &m, &a, &b);
  if (n % m == 0) {
    printf("0\n");
  } else {
    yu = n % m;
    sumyu = (m - yu) * a;
    sumchai = yu * b;
    sum = min(sumyu, sumchai);
    printf("%lld\n", sum);
  }
  return 0;
}
