#include <bits/stdc++.h>
using namespace std;
int main() {
  double l3, l4, l5;
  cin >> l3 >> l4 >> l5;
  double area3 = l3 * l3;
  area3 *= l3;
  area3 /= (6.0);
  area3 /= sqrt(2);
  double area4 = l4 * l4;
  area4 *= l4;
  area4 /= (6.0);
  area4 /= sqrt(2);
  area4 *= 2;
  double area5 = l5 * l5;
  area5 *= l5;
  area5 *= 0.301502832395831588;
  cout << fixed << setprecision(12) << area3 + area4 + area5 << endl;
  return 0;
}
