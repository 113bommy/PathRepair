#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (a > b || (b - a) % 2) {
    cout << -1;
    return 0;
  }
  if (a == b) {
    if (a == 0)
      cout << 0;
    else
      cout << 1 << "\n" << a;
  } else if (((a + (b - a) / 2) ^ ((b - a) / 2)) == a) {
    cout << 2 << "\n" << a + (b - a) / 2 << " " << (b - a) / 2;
  } else
    cout << 3 << endl << a << " " << (b - a) / 2 << " " << (b - a) / 2;
}
