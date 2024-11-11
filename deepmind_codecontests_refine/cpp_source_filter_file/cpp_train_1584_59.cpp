#include <bits/stdc++.h>
using namespace std;
bool isprime(int n) {
  if (n <= 1) {
    return false;
  }
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  long long n;
  cin >> n;
  long long a = 4;
  long long b;
  while (1) {
    b = a + n;
    if (isprime(a) || isprime(b)) {
      b++;
      a++;
    } else {
      break;
    }
  }
  cout << a << " " << b;
  return 0;
}
