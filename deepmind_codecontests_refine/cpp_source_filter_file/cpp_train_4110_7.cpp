#include <bits/stdc++.h>
using namespace std;
int main() {
  long int a, b, c, d;
  cin >> a >> b >> c >> d;
  long int Misha;
  long int Vasya;
  long result1Misha = (3 * a) / 10;
  long result1Vasya = (3 * b) / 10;
  long result2Misha = ((a - (a / 250)) * c);
  long result2Vasya = ((b - (b / 250)) * d);
  Misha = max(result1Misha, result2Misha);
  Vasya = max(result1Vasya, result2Vasya);
  if (Misha > Vasya)
    cout << "Misha" << endl;
  else if (Misha < Vasya)
    cout << "Vasya" << endl;
  else if (Misha == Vasya)
    cout << "Tie" << endl;
  return 0;
}
