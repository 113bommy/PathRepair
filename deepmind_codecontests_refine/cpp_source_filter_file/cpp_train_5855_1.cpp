#include <bits/stdc++.h>
using namespace std;
bool prime(int n) {
  if (n < 2) {
    return false;
  }
  for (int i = 2; i <= (int)sqrt(n * 1.0); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  int n;
  scanf("%d", &n);
  int l = 1, r = n;
  for (int i = 1; i <= (int)ceil(sqrt(n * 1.0)); i++) {
    if (n % i == 0 && prime(i) && prime(n / i)) {
      if (n / i - i < r - l) {
        l = i;
        r = n / i;
      }
    }
  }
  printf("%d%d", l, r);
  return 0;
}
