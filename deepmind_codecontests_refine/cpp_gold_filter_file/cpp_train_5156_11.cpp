#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  while (~scanf("%I64d", &n)) {
    int e = n % 10;
    n /= 10;
    int d = n % 10;
    n /= 10;
    int c = n % 10;
    n /= 10;
    int b = n % 10;
    n /= 10;
    n = n * 10000 + c * 1000 + e * 100 + d * 10 + b;
    long long ans = n * n % 100000 * n % 100000 * n % 100000 * n % 100000;
    printf("%05I64d\n", ans);
  }
  return 0;
}
