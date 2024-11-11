#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c, d, ans, sum, p = 3.14159265358;
  cin >> a >> b >> c >> d;
  a = a / 2.0;
  sum = a * a * p * d;
  if (c - sum <= 0) {
    cout << "NO";
    return 0;
  }
  cout << "YES" << endl << sum / d * b / (c - sum) << endl;
}
