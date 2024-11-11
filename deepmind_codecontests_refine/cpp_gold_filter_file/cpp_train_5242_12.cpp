#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-6;
int main() {
  int x;
  scanf("%d", &x);
  if (x == 3)
    puts("5");
  else {
    for (int i = 1; true; i += 2) {
      if (((i * i + 1) >> 1) >= x) {
        printf("%d\n", i);
        break;
      }
    }
  }
  return 0;
}
