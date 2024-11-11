#include <bits/stdc++.h>
using namespace std;
bool isFibonacci(int testedNumber, int a = 1, int b = 1);
int main() {
  int n;
  cin >> n;
  bool c[1000] = {false};
  for (int i = 1; i < n + 1; i++) {
    c[i] = isFibonacci(i, 1, 1);
  }
  for (int i = 1; i < n + 1; i++) {
    if (c[i] == true)
      cout << 'O';
    else
      cout << 'o';
  }
  return 0;
}
bool isFibonacci(int testedNumber, int a, int b) {
  if (testedNumber == 0 || testedNumber == 1) return true;
  int nextFib = a + b;
  if (nextFib > testedNumber)
    return false;
  else if (nextFib == testedNumber)
    return true;
  else
    isFibonacci(testedNumber, b, nextFib);
}
