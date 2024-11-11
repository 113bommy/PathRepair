#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d;
  cin >> a;
  cin >> b >> c;
  d = b + c;
  if (d - 2 > (2 * a) - d)
    cout << "Black";
  else {
    cout << "White";
  }
}
