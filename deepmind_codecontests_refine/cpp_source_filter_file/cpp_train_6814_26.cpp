#include <bits/stdc++.h>
using namespace std;
unsigned long long A, sum, x;
int main() {
  cin >> A;
  sum = 9;
  unsigned long long tmp = 10;
  for (int i = 2; i <= 19; i++) {
    sum = ((sum + sum * 9 % A) % A + 45 * tmp % A) % A;
    tmp = tmp * 10 % A;
  }
  sum += 1;
  unsigned long long t = A - (sum % A);
  x = 1000000000;
  x = x * x;
  x *= 10;
  cout << 1 + t << ' ' << x + t << endl;
  return 0;
}
