#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  if (x % 2 == 0) {
    cout << 4 << " " << x - 4;
  } else {
    cout << 9 << " " << x - 9;
  }
}
