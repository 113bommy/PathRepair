#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector<long long> di;
int main() {
  scanf("%I64d", &n);
  scanf("%I64d", &k);
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      di.push_back(i);
      if (i != n / i) di.push_back(n / i);
    }
  }
  sort(di.begin(), di.end());
  reverse(di.begin(), di.end());
  long long x;
  for (long long gcd : di) {
    x = n / gcd;
    if (k <= 1000000 && x >= ((k * (k + 1)) / 2)) {
      for (int i = 1; i < k; i++) {
        x -= i;
        long long y = i * gcd;
        printf("%I64d ", y);
      }
      long long y = x * gcd;
      printf("%I64d\n", y);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
