#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
double a, b, c;
int main() {
  cin >> a >> b >> c;
  double s = b * b - 4 * a * c;
  if (a == b && b == c && a == 0) return puts("-1"), 0;
  if (a == 0 && b == 0) return puts("0"), 0;
  if (a == 0) {
    cout << 1 << endl;
    printf("%.6lf\n", (-c) / b);
    return 0;
  }
  if (s < 0) return puts("0"), 0;
  if (s == 0) {
    cout << 1 << endl;
    printf("%.6lf\n", (-b) / (2 * a));
  } else {
    cout << 2 << endl;
    double x = (-b + sqrt(s)) / (2 * a);
    double y = (-b - sqrt(s)) / (2 * a);
    if (x < y) {
      printf("%.6lf\n", x);
      printf("%.6lf\n", y);
    } else {
      printf("%.6lf\n", y);
      printf("%.6lf\n", x);
    }
  }
  return 0;
}
