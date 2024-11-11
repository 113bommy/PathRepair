#include <bits/stdc++.h>
using namespace std;
int year(int y) {
  int a = y % 10;
  int b = (y / 10) % 10;
  int c = (y / 100) % 10;
  int d = (y / 1000) % 10;
  if (a != b && a != c && a != d && b != c && b != d && c != d)
    return 1;
  else
    return 0;
}
int main() {
  int i, y;
  cin >> y;
  for (i = y + 1; i <= 9012; i++) {
    int x = year(i);
    if (x == 1) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
