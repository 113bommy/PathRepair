#include <bits/stdc++.h>
using namespace std;
long long int n;
int main() {
  scanf("%lld", &n);
  for (long long int i = 1; i <= n; i++) {
    long long int a, b;
    scanf("%lld%lld", &a, &b);
    if (a * 2 > b)
      printf("-1 -1\n");
    else
      printf("%lld %lld\n", a, a * 2);
  }
  return 0;
}
