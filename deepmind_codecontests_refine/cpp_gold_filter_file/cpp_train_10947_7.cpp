#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a;
    scanf("%lld", &a);
    int sum = 0;
    while (true) {
      if (a % 2 == 0) {
        a /= 2;
      } else if (a % 3 == 0) {
        a = a / 3 * 2;
      } else if (a % 5 == 0) {
        a = a / 5 * 4;
      } else {
        break;
      }
      sum++;
    }
    if (a == 1) {
      printf("%d\n", sum);
    } else {
      printf("-1\n", sum);
    }
  }
  return 0;
}
