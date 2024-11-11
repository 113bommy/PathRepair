#include <bits/stdc++.h>
using namespace std;
bool isIrreducible(int x, int y) {
  bool res = true;
  for (int i = 2; i <= x; i++) {
    if ((x % i == 0) and (y % i == 0)) res = false;
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  int a = n / 2;
  int b = n - a;
  while (true) {
    if (isIrreducible(a, b))
      break;
    else {
      a = a - 1;
      b = b + 1;
    }
  }
  cout << a << " " << b << endl;
  return 0;
}
