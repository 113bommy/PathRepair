#include <bits/stdc++.h>
using namespace std;
int operation(long num) {
  int temp = 0;
  while (num != 0) {
    int x = num % 10;
    if (x == 1) {
      temp += 2;
    }
    if (x == 2) {
      temp += 5;
    }
    if (x == 3) {
      temp += 5;
    }
    if (x == 4) {
      temp += 4;
    }
    if (x == 5) {
      temp += 5;
    }
    if (x == 6) {
      temp += 6;
    }
    if (x == 7) {
      temp += 3;
    }
    if (x == 8) {
      temp += 8;
    }
    if (x == 9) {
      temp += 7;
    }
    if (x == 0) {
      temp += 6;
    }
    num /= 10;
  }
  return temp;
}
int main() {
  long a;
  long b;
  cin >> a >> b;
  long counter = 0;
  for (a; a <= b; a++) {
    counter += operation(a);
  }
  cout << counter;
}
