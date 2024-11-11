#include <bits/stdc++.h>
using namespace std;
double n, a;
int main() {
  cin >> n >> a;
  double c = (180 * (n - 2) / n);
  double d = (180 - c) / 2;
  if (a <= d)
    cout << 2 << " " << 1 << " " << 3 << endl;
  else if (a >= c)
    cout << 2 << " " << 1 << " " << n << endl;
  else {
    int t = a / d;
    double a1 = t * d, a2 = t * d + d;
    if ((a - a1) >= (a2 - a))
      cout << 2 << " " << 1 << " " << t + 3 << endl;
    else
      cout << 2 << " " << 1 << " " << t + 2 << endl;
  }
}
