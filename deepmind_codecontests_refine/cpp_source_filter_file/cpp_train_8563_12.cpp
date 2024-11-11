#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a < b) return gcd(b, a);
  while (b > 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int ret = 0;
  for (int i = 2; i < n; i++) {
    int base = i;
    int v = n;
    while (base < v) base *= i;
    base /= i;
    while (base > 0) {
      ret += v / base;
      v %= base;
      base /= i;
    }
  }
  int g = gcd(ret, n - 2);
  cout << ret / g << "/" << (n - 2) / g << endl;
}
