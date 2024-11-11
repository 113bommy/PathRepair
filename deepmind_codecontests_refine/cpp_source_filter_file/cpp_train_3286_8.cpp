#include <bits/stdc++.h>
using namespace std;
bool prime(long int x) {
  if (x == 2) return 1;
  if (x % 2 == 0) return 0;
  for (long i = 3; i * i <= x; i += 2)
    if (!x % i) return 0;
  return 1;
}
int main() {
  long int x;
  scanf("%lld", &x);
  if (prime(x))
    printf("1\n");
  else if (x % 2 == 0 || prime(x - 2))
    printf("2\n");
  else
    printf("3\n");
  return 0;
}
