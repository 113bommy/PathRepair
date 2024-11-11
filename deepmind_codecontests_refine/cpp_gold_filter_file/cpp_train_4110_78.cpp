#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  float max1 = 1.0 * a * 3 / 10 > a - a * c * 1.0 / 250 ? 1.0 * a * 3 / 10
                                                        : a - a * c * 1.0 / 250;
  float max2 = 1.0 * b * 3 / 10 > b - b * d * 1.0 / 250 ? 1.0 * b * 3 / 10
                                                        : b - b * d * 1.0 / 250;
  if (max1 < max2)
    cout << "Vasya";
  else if (max2 < max1)
    cout << "Misha";
  else
    cout << "Tie";
}
