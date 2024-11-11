#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int m1 = 3 * a / 10;
  int m2 = a - a * c / 250;
  int v1 = 3 * b / 10;
  int v2 = b - b * d / 250;
  int m = m1 > m2 ? m1 : m2;
  int v = v1 > v2 ? v1 : v2;
  if (m1 > v1)
    cout << "Misha" << endl;
  else if (m1 < v1)
    cout << "Vasya" << endl;
  else
    cout << "Tie" << endl;
}
