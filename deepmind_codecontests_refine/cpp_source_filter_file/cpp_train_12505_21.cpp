#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, x;
  cin >> x;
  if (x < 4)
    cout << -1 << endl;
  else {
    if (x % 2 == 0) {
      cout << x << " " << 2 << endl;
    } else {
      cout << x - 1 << " " << 2 << endl;
    }
  }
  return 0;
}
