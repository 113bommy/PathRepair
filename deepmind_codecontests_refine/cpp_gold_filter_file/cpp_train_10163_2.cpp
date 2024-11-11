#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  if (a == 1) {
    cout << 1 << " " << 1 << endl;
    cout << 1 << endl;
    return 0;
  }
  if (a % 2 == 0) {
    cout << (a * 2) - 1 << " " << 2 << endl;
    cout << 1 << " " << 2 << endl;
  } else {
    cout << ((a - 1) * 2) << " " << 2 << endl;
    cout << 1 << " " << 2 << endl;
  }
  return 0;
}
