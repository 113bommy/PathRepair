#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    long long p = cbrt(a * b);
    if (p * p * p == a * b && a % p == 0 && b % p == 0) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}
