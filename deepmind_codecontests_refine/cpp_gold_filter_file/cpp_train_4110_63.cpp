#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, M, V;
  cin >> a >> b >> c >> d;
  M = max((3 * a) / 10, a - (a / 250) * c);
  V = max((3 * b) / 10, b - (b / 250) * d);
  if (M > V) {
    cout << "Misha";
  } else if (V > M) {
    cout << "Vasya";
  } else {
    cout << "Tie";
  }
  return 0;
}
