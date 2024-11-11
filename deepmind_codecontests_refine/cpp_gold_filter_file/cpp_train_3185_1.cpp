#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int x = 0;
  while (a <= b) {
    a = 3 * a;
    b = b * 2;
    x++;
  }
  cout << x;
}
