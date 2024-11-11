#include <bits/stdc++.h>
using namespace std;
int for_int(int c);
int main() {
  int n;
  cin >> n;
  cout << for_int(n / 10) * for_int(n - 10 * (n / 10));
  return 0;
}
int for_int(int c) {
  switch (c) {
    case 1:
      return 9;
    case 2:
      return 2;
    case 3:
      return 3;
    case 4:
      return 3;
    case 5:
      return 4;
    case 6:
      return 2;
    case 7:
      return 5;
    case 8:
      return 1;
    case 9:
      return 2;
    case 0:
      return 2;
    default:
      return 0;
  }
}
