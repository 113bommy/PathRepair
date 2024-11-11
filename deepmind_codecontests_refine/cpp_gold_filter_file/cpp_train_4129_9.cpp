#include <bits/stdc++.h>
using namespace std;
long long n, m, a, b, indexa, indexb;
int main() {
  cin >> n >> m >> a >> b;
  indexa = a / m;
  if (a % m == 0) indexa -= 1;
  indexb = b / m;
  if (b % m == 0) indexb -= 1;
  if (m == 1)
    cout << '1' << endl;
  else if (indexa == indexb) {
    cout << '1' << endl;
  } else if (b == n) {
    if (a % m == 1)
      cout << '1' << endl;
    else
      cout << '2' << endl;
  } else if (indexb - indexa == 1) {
    if (a % m == 1 && b % m == 0)
      cout << '1' << endl;
    else
      cout << '2' << endl;
  } else {
    if (a % m == 1 && b % m == 0)
      cout << '1' << endl;
    else if (a % m == 1 || b % m == 0)
      cout << '2' << endl;
    else if ((a - indexa * m - 1) == (b - indexb * m))
      cout << '2' << endl;
    else
      cout << '3' << endl;
  }
}
