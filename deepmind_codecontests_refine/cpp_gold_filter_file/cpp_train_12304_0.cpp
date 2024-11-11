#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (b - a != 0 && b - a != 1 && ((a != 9) || b != 1)) {
    cout << -1;
  } else {
    if (a - b == 0)
      cout << (a * 10) << " " << (b * 10) + 1;
    else
      cout << (b * 10) - 1 << " " << (b * 10);
  }
  return 0;
}
