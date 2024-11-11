#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  cin >> a >> b >> n;
  if (a == 0) {
    if (b == 0)
      cout << "10" << endl;
    else
      cout << "No solution" << endl;
  } else if ((b % a) == 0) {
    if (b == 0)
      cout << "0" << endl;
    else {
      int c = b / a;
      double x = 1;
      for (int i = 1; i <= 10; i++)
        x = x - (pow(x, n) - c) / (n * pow(x, n - 1));
      int r = x;
      if (fabs(x - r) < 1e-6)
        cout << r << endl;
      else
        cout << "No solution" << endl;
    }
  } else
    cout << "No solution" << endl;
  return 0;
}
