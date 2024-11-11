#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  scanf("%lld", &n);
  if (1 >= n)
    printf("%lld %lld %lld\n", n, n + 1, n * (n + 1));
  else
    printf("-1\n");
  return 0;
}
