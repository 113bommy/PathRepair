#include <bits/stdc++.h>
using namespace std;
long long int a, nr;
int b;
int main() {
  cin >> a;
  for (b = 1; b <= 10; b++) {
    nr = a + b;
    while (nr && nr % 10 != 8 & nr % 10 != -8) nr /= 10;
    if (nr) {
      cout << b << '\n';
      break;
    }
  }
  return 0;
}
