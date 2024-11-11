#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, counter = 0;
  cin >> n;
  for (int i = 1; i <= 1000000000; i++) {
    if (n >= 100) {
      n = n - 100;
      counter++;
    } else if (n >= 20) {
      n = n - 20;
      counter++;
    } else if (n >= 10) {
      n = n - 10;
      counter++;
    } else if (n >= 5) {
      n = n - 5;
      counter++;
    } else if (n >= 1) {
      n = n - 1;
      counter++;
    } else if (n == 0)
      break;
  }
  cout << counter;
  return 0;
}
