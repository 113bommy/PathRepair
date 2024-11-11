#include <bits/stdc++.h>
using namespace std;
int modulo(int a, int b, int n) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % n;
    }
    y = (y * y) % n;
    b /= 2;
  }
  return x % n;
}
int main() {
  long long n;
  cin >> n;
  cout << modulo(5, n, 100);
}
