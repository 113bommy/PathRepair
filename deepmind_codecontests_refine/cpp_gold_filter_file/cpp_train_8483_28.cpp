#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (a >= b) {
    cout << b;
    cout << " ";
    cout << (a - b) / 2;
  }
  if (a < b) {
    cout << a;
    cout << " ";
    cout << (b - a) / 2;
    return 0;
  }
}
