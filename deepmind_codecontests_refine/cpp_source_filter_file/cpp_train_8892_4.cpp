#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, d;
  int n;
  cin >> a >> d >> n;
  for (int i = 0; i < n; i++) {
    double temp = fmod((i + 1) * d, 4 * a);
    if (temp < a)
      printf("%.9f %.9f\n", temp, 0.0);
    else if (temp < a * 2)
      printf("%.9f %.9f\n", a, temp - a);
    else if (temp < a * 3)
      printf("%.9f %.9f\n", 3 * a - temp, a);
    else
      printf("%.9f %.9f", 0.0, 4 * a - temp);
  }
  return 0;
}
