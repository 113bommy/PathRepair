#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int X, Y;
  cin >> X >> Y;
  cout << abs(X - Y) <= 1 ? "Brown" : "Alice" << endl;
  return 0;
}
