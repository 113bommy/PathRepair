#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long int n, a, b, c, temp;
  scanf("%u %u %u %u", &n, &a, &b, &c);
  switch (n % 4) {
    case 0:
      printf("0");
      break;
    case 1:
      temp = min(c, (a + b));
      printf("%u", min((3 * a), temp));
      break;
    case 2:
      temp = min(b, (2 * c));
      printf("%u", min((2 * a), temp));
      break;
    case 3:
      temp = min(a, (3 * c));
      printf("%u", min(temp, (b + c)));
      break;
  }
  return 0;
}
