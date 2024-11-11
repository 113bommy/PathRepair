#include <bits/stdc++.h>
using namespace std;
const int S = 500000;
const int MAX = 1000000010;
bool isPrime(int x) {
  if (x == 1) {
    return false;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  int k;
  cin >> k;
  if (k == 3) {
    cout << 1 << endl << 3 << endl;
    return 0;
  }
  vector<int> primes;
  for (int i = 2; i < MAX; i++) {
    if (isPrime(i)) {
      primes.push_back(i);
      i += S;
    }
  }
  int x;
  for (int i = primes.size() - 1; i >= 0; i--) {
    if (k >= primes[i]) {
      x = primes[i];
      break;
    }
  }
  k -= x;
  if (k == 0) {
    cout << 1 << endl;
    cout << x << endl;
    return 0;
  }
  if (isPrime(k)) {
    cout << 2 << endl;
    cout << x << " " << k << endl;
    return 0;
  }
  for (int i = 2;; i++) {
    int j = k - i;
    if (isPrime(i) && isPrime(j)) {
      cout << 3 << endl;
      cout << x << " " << i << " " << j << endl;
      return 0;
    }
  }
  return 0;
}
