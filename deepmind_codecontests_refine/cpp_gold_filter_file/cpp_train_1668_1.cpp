#include <iostream>
using namespace std;

int main() {
  int ans;
  int x, y;

  cin >> x >> y;

  while (x % y != 0) {
    int tmp = x;
    x = y;
    y = tmp % y;
  }

  cout << y << endl;
}