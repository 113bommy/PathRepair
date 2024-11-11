#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, n;
  cin >> a >> b >> n;
  int digit;
  digit = a * 10 / b;
  if ((a * 10) % b == 0) {
    digit = a * 10;
  } else if (a % b) {
    digit = (b * digit + b);
    if ((digit / 10) != a) {
      printf("%d", -1);
      return 0;
    }
  } else {
    digit = a;
    n++;
  }
  printf("%d", digit);
  while (--n) {
    printf("0");
  }
  return 0;
}
