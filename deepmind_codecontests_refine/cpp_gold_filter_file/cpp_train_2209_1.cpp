#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, sum = 0, carry = 0;
    cin >> n;
    long long num = n;
    while (n >= 10) {
      long long a = (n / 10) * 10;
      carry = n % 10;
      sum += a;
      carry += (n / 10);
      n = carry;
    }
    if (num < 10)
      cout << num << "\n";
    else
      cout << sum + carry << "\n";
  }
}
