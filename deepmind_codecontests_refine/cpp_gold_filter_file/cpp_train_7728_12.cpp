#include <bits/stdc++.h>
using namespace std;
long long int c = 998244353;
long long int power(int a, long int n) {
  if (n == 0) return 1;
  if (n == 1) return a;
  long long int p = power(a, n / 2) % c;
  return (((p * p) % c) * power(a, n % 2)) % c;
}
int main() {
  long int n;
  cin >> n;
  for (long int i = 1; i <= n; i++) {
    if (i != n)
      cout << (2 * 10 * 9 * power(10, n - i - 1) +
               (n - i - 1) * 9 * 9 * power(10, n - i - 1)) %
                  c
           << " ";
    else
      cout << 10;
  }
  return 0;
}
