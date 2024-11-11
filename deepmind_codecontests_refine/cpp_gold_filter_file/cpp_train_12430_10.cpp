#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  scanf("%I64d", &n);
  long long i = 3;
  for (;; i *= 3)
    if (n % i) break;
  printf("%I64d", n / i + 1);
  return 0;
}
