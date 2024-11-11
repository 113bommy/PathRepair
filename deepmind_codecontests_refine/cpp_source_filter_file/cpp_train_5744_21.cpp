#include <bits/stdc++.h>
using namespace std;
bool checksum(int a) {
  int m, b = 0;
  while (a != 0) {
    m = a % 10;
    b = b + m;
    a = a / 10;
  }
  if (b % 4 == 0)
    return true;
  else
    return false;
}
int main() {
  int a;
  cin >> a;
  for (int i = a; i < 1001; i++) {
    bool b = checksum(i);
    if (b) {
      cout << i << endl;
      break;
    }
  }
}
