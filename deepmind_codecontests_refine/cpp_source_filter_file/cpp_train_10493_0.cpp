#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, x;
  double h;
  cin >> a >> b >> x;
  h = (double)x / (a * a);
  if (h * 2 >= b)
    cout << setprecision(16) << atan2((b - h) * 2, a) / M_PI * 180 << endl;
  else
    cout << setprecision(16) << atan2(b, h * a / b) / M_PI * 180 << endl;
}
