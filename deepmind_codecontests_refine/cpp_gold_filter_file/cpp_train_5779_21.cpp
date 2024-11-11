#include <bits/stdc++.h>
using namespace std;
long long int n, m;
bool isPrime(int n) {
  if (n == 2) return true;
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  if (n < 6) {
    if (n == 3) {
      cout << 1 << endl;
      cout << 3;
    } else {
      cout << 2 << endl;
      cout << 2 << " " << (n - 2);
    }
    return 0;
  }
  int p = 0;
  for (int i = (n - 4); i > 0; i--) {
    if (isPrime(i)) {
      p = i;
      break;
    }
  }
  int x = n - p;
  int y = 0;
  int z = 0;
  for (int i = 2; i < x; i++) {
    if (isPrime(i) && isPrime(x - i)) {
      y = i;
      z = x - i;
      break;
    }
  }
  cout << 3 << endl;
  cout << p << " " << y << " " << z;
}
