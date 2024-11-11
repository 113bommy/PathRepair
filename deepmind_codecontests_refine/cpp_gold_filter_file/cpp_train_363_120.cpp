#include <bits/stdc++.h>
using namespace std;
long long fastPower(int a, long long b, int n) {
  long long res = 1;
  while (b > 0) {
    if ((b & 1) != 0) {
      res = ((res * a) % n) % n;
    }
    a = (a % n * a % n) % n;
    b = b >> 1;
  }
  return res;
}
int main() {
  long long n;
  cin >> n;
  cout << fastPower(5, n, 100);
}
