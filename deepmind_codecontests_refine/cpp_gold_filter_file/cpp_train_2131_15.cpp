#include <bits/stdc++.h>
using namespace std;
bool check(long long int n) {
  while (n != 0) {
    if (n % 10 == 8) return 1;
    n = n / 10;
  }
  return 0;
}
int main() {
  long long int n, res;
  cin >> n;
  if (n >= -8 && n < 0) {
    for (int i = 1; i <= 16; i++) {
      res = n + i;
      if (check(res)) {
        cout << i;
        break;
      }
    }
  } else {
    for (int i = 1; i <= 10; i++) {
      res = n + i;
      if (check(abs(res))) {
        cout << i;
        break;
      }
    }
  }
}
