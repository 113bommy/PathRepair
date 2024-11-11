#include <bits/stdc++.h>
using namespace std;
int summ(int n) {
  int p;
  while (n) {
    p = n % 10;
    n = n / 10;
  }
  return p;
}
int main() {
  int a;
  cin >> a;
  for (int i = a;; i++) {
    if (summ(a) % 4 == 0) {
      cout << i;
      break;
    }
  }
}
