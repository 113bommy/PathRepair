#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c = 0;
  cin >> a >> b;
  int x[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  for (int i = a; i <= b; i++) {
    int y = i;
    while (y != 0) {
      c += x[y % 10];
      y = y / 10;
    }
  }
  cout << c;
  return 0;
}
