#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, n, i, c;
  scanf("%lld %lld", &a, &b);
  c = b - a;
  if (c == 0) {
    printf("%lld\n", a);
  } else if (c == 3 && c % 3 == 0) {
    printf("3\n");
  } else {
    printf("2\n");
  }
  return 0;
}
