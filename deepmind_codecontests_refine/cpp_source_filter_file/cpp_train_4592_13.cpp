#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long a) {
  long long i;
  for (i = 2; i < (long long)sqrt(a); i++) {
    if (a % i == 0) return false;
  }
  return true;
}
int main() {
  long long t;
  cin >> t;
  while (t-- > 0) {
    long long a, b, area = 0;
    cin >> a >> b;
    if (a - b == 1 && isPrime(a + b))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
