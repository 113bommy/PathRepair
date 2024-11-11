#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y;
  cin >> x >> y;
  double A = y * log(x);
  double B = x * log(y);
  if (fabs(A - B) < 0.0000000001) {
    cout << "=" << endl;
  } else if (A > B)
    cout << ">" << endl;
  else if (A < B)
    cout << "<" << endl;
  return 0;
}
