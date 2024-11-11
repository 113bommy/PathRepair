#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  double misha, vasya;
  misha = max((3 * a) / 10, a - (a * c) / 250);
  vasya = max((3 * b) / 10, b - (a * d) / 250);
  if (vasya == misha)
    cout << "Tie";
  else if (vasya > misha)
    cout << "Vasya";
  else
    cout << "Misha";
}
