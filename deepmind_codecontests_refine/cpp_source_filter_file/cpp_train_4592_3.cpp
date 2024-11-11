#include <bits/stdc++.h>
using namespace std;
bool isprime(long long a) {
  if (a <= 1) return false;
  if (a <= 3) return true;
  for (long long i = 2; i * i < sqrt(a); i++) {
    if (a % i == 0) return false;
  }
  return true;
}
int main() {
  long long n, q, a, b, t;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a - b == 1 && isprime(a + b))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
