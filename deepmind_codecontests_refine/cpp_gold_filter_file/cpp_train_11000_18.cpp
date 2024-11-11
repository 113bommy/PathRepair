#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a = 0;
  int b;
  cin >> n;
  while (n / 100 >= 1) {
    b = n / 100;
    a += b;
    n -= b * 100;
  }
  while (n >= 20) {
    n -= 20;
    a++;
  }
  while (n >= 10) {
    n -= 10;
    a++;
  }
  while (n >= 5) {
    n -= 5;
    a++;
  }
  while (n > 0) {
    n--;
    a++;
  }
  cout << a << "\n";
  return 0;
}
