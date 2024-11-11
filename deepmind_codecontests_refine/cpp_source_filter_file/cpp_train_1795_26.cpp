#include <bits/stdc++.h>
using namespace std;
int main() {
  stack<int> s;
  for (int i = 1; i <= 11; ++i) {
    int x;
    cin >> x;
    s.push(x);
  }
  for (int i = 1; i <= 11; ++i) {
    int x = s.top();
    s.pop();
    double a = sqrt(abs(1.0 * x));
    double b = pow(x, 3) * 5;
    double res = a + b;
    if (res < 400)
      printf("f(%d) = %.2lf\n", x, res);
    else
      printf("f(%d) = MAGNA NIMIS!", x);
  }
}
