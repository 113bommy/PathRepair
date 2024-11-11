#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (a > b) {
    int c = a - b;
    cout << b << " " << c / 2;
  } else {
    int c = a - b;
    cout << a << " " << abs(c / 2);
  }
  return 0;
}
