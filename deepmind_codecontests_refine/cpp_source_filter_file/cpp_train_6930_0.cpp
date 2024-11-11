#include <bits/stdc++.h>
using namespace std;
bool Is_Prime(int x) {
  int s;
  s = sqrt((double)(x));
  for (int i = 2; i <= s; i++) {
    if (x % i == 0) {
      return true;
    }
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  if (n % 2 == 1) {
    if (n == 1) {
      cout << 3;
    } else {
      cout << 1;
    }
  } else {
    int index;
    index = 1;
    while (true) {
      if (Is_Prime(3 * index + 1) == false) {
        cout << index;
        break;
      }
      index++;
    }
  }
  return 0;
}
