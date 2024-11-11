#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  scanf("%lld%lld", &a, &b);
  long long x = b / a;
  if (a % b != 0) x++;
  printf("%lld\n", x);
  return 0;
}
