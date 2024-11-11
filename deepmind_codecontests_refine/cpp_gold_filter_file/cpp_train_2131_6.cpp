#include <bits/stdc++.h>
using namespace std;
bool check8(long long int a) {
  bool result = false;
  int b = 0;
  for (int i = 11 - 1; i >= 0; i--) {
    b = a / pow(10, i) - b * 10;
    if (b == 8 || b == -8) {
      result = true;
      break;
    }
    b = a / pow(10, i);
  }
  return result;
}
int main() {
  long long int a;
  cin >> a;
  for (int i = 1; i <= 16; i++) {
    if (check8(a + i)) {
      cout << i;
      return 0;
    }
  }
}
