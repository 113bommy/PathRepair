#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  scanf("%lld%lld", &n, &k);
  n--;
  long long s = k + n - 1;
  long long p = sqrt(s) + 2;
  while (p * (p + 3) / 2 > s) p--;
  printf("%lld\n", n - p);
}
