#include <bits/stdc++.h>
using namespace std;
const long long maxx = 1e12 + 5;
int main() {
  long long n;
  scanf("%lld", &n);
  long long sum = 0;
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      while (!(n % i)) {
        n /= i;
      }
      if (n > 1) {
        printf("1\n");
        return 0;
      } else {
        printf("%lld\n", i);
        return 0;
      }
    }
  }
  printf("%lld\n", n);
  return 0;
}
