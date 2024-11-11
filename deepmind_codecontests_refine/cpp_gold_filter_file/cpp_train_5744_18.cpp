#include <bits/stdc++.h>
using namespace std;
int summ(int n) {
  int p = 0;
  while (n) {
    p += n % 10;
    n = n / 10;
  }
  return p;
}
int main() {
  int a;
  cin >> a;
  for (int i = a;; i++) {
    if (summ(i) % 4 == 0) {
      cout << i;
      break;
    }
  }
}
