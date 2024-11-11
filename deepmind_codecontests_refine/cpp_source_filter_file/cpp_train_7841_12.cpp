#include <bits/stdc++.h>
using namespace std;
int divisor(int n) {
  int i, j;
  if (n % 2 == 0) {
    return n / 2;
  }
  j = sqrt(i);
  for (i = 3; i <= j; i += 2) {
    if (n % i == 0) return n / i;
  }
  return 1;
}
int main() {
  int n;
  long long m;
  cin >> n;
  m = n;
  while (n > 1) {
    n = divisor(n);
    m += n;
  }
  cout << m;
  return 0;
}
