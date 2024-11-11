#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int misha = max(((3 * a) / 10), (a - ((a * c) / 250)));
  int vasya = max(((3 * b) / 10), (b - ((b * d) / 250)));
  if (misha > vasya)
    cout << "Misha" << endl;
  else if (misha < vasya)
    cout << "Vasya" << endl;
  else
    cout << "Tie" << endl;
  return 0;
}
