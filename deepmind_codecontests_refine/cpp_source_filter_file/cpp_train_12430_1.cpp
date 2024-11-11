#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  while (x % 3 == 0) {
    x /= 3;
  }
  cout << x / 3 + 1 << endl;
  return 0;
}
