#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a;
  scanf("%lld", &a);
  long long rm = (unsigned long long)1e17 % a * 45 % a * 18 % a;
  printf("%lld %lld\n", a - rm, (long long)1e18 - 1 + a - rm);
  return 0;
}
