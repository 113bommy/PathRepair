#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b, a, s, d, sum = 0;
  cin >> n >> b;
  s = n;
  while (n >= b) {
    sum = sum + n / b;
    d = n % b;
    a = n / b;
    n = a + d;
  }
  cout << s + sum;
}
