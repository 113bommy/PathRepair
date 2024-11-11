#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c;
  cin >> a >> b >> c;
  double d = b * b - 4 * a * c;
  if (a == 0 && b == 0 && c == 0) {
    cout << "-1\n";
    return 0;
  }
  if (a == 0 && b == 0) {
    cout << "0\n";
    return 0;
  }
  if (a == 0) {
    cout << "1\n";
    printf("%.5lf\n", -c / b);
    return 0;
  }
  if (d < 0) {
    cout << "0\n";
    return 0;
  }
  if (d == 0) {
    cout << "1\n";
    printf("%.5lf\n", -b / (2 * a));
    return 0;
  }
  cout << "2\n";
  printf("%.5lf\n", min((-b + sqrt(d)) / (2 * a), (-b - sqrt(d)) / (2 * a)));
  printf("%.5lf\n", max((-b + sqrt(d)) / (2 * a), (-b - sqrt(d)) / (2 * a)));
  return 0;
}
