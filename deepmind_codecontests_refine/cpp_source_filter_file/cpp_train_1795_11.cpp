#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> a;
  for (int i = 0; i < 11; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  for (int i = 10; i >= 0; i--) {
    int x = a[i];
    double a = sqrt(abs(x));
    double b = x * x * x * 5;
    double r = a + b;
    if (r > 40) {
      printf("f(%d) = MAGNA NIMIS!\n", x);
    } else {
      printf("f(%d) = %.2f\n", x, r);
    }
  }
  return 0;
}
