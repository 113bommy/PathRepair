#include <bits/stdc++.h>
using namespace std;
int main() {
  double d, dis, a, b;
  int n;
  cin >> n;
  cout << fixed << setprecision(9);
  for (int i = 0; i < n; i++) {
    cin >> d;
    if (d == 0)
      cout << "Y 0.000000000 0.000000000" << endl;
    else if (d < 4)
      cout << "N" << endl;
    else {
      dis = pow(d, 2) - 4 * d;
      a = (d + sqrt(dis)) / 2.0;
      b = (d - sqrt(dis)) / 2.0;
      cout << "Y " << a << " " << b << endl;
    }
  }
  return (0);
}
