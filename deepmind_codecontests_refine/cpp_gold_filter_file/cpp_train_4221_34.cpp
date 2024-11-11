#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, x = 0;
  cin >> a;
  while (a) {
    if (a % 8 == 1) {
      x++;
    }
    a /= 8;
  }
  cout << x;
}
