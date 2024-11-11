#include <bits/stdc++.h>
using namespace std;
int power(long long base, int exponent) {
  int b = base;
  base = 1;
  for (int i = 1; i <= exponent; ++i) {
    base = 1ll * base * b;
    base %= 1000000009;
  }
  return base;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k == 1 || k > n)
    cout << power(m, n);
  else if (k == n)
    cout << power(m, (n + 1) / 2);
  else if (k % 2 == 1)
    cout << m * m;
  else if (k % 2 == 0)
    cout << m;
  return 0;
}
