#include <bits/stdc++.h>
using namespace std;
int gnum(int, int);
int gnum(int a, int b) {
  if (a >= b)
    return a;
  else
    return b;
}
int main() {
  int num1, num2, num;
  cin >> num1 >> num2;
  num = gnum(num1, num2);
  switch (num1) {
    case 1:
      cout << 1 << "/" << 1;
      break;
    case 2:
      cout << 5 << "/" << 6;
      break;
    case 3:
      cout << 2 << "/" << 3;
      break;
    case 4:
      cout << 1 << "/" << 2;
      break;
    case 5:
      cout << 1 << "/" << 3;
      break;
    case 6:
      cout << 1 << "/" << 6;
      break;
  }
}
