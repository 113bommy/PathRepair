#include <bits/stdc++.h>
using namespace std;
int f(int x) {
  if (x == 1) {
    return 1;
  } else {
    return x + f(x - 1);
  }
}
int main() {
  int number, i, j;
  cin >> number;
  for (i = 1;; i++) {
    j = f(i);
    if (j > number) {
      break;
    }
  }
  cout << i - 1;
}
