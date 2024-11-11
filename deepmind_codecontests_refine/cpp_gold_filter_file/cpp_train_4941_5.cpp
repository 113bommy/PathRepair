#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  scanf("%I64d", &n);
  long long x = n % 3;
  x = 3 - x;
  long long cou = 0;
  for (long long i = x; i * (i + 1) / 2 * 3 <= (n + i); i = i + 3) {
    cou++;
  }
  printf("%I64d\n", cou);
  return 0;
}
