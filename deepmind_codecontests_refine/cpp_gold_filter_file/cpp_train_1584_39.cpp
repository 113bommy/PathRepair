#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long int n) {
  if (n <= 1) {
    return false;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  long long int n;
  cin >> n;
  for (long long int i = 2; i <= 1000000000; i++) {
    if (isPrime(i) == false && isPrime(i + n) == false) {
      cout << i + n << " " << i << endl;
      break;
    }
  }
  return 0;
}
