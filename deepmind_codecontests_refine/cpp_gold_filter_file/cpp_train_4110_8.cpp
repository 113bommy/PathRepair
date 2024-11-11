#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, mi, va;
int main() {
  cin >> a >> b >> c >> d;
  mi = max(3 * a / 10, a - a / 250 * c);
  va = max(3 * b / 10, b - b / 250 * d);
  if (mi > va) {
    cout << "Misha";
  } else if (va > mi) {
    cout << "Vasya";
  } else {
    cout << "Tie";
  }
  return 0;
}
