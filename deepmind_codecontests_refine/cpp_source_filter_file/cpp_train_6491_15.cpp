#include <bits/stdc++.h>
using namespace std;
int main() {
  long long p, d, i, k;
  scanf("%lld%lld", &p, &d);
  p++;
  for (i = 10;; i = i * 10) {
    if (p % i > d) break;
    k = p - p % i;
  }
  printf("%lld", k - 1);
  return 0;
}
