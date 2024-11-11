#include <bits/stdc++.h>
using namespace std;
int n;
int prime(int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  cin >> n;
  for (int i = 1; i <= 10e7; i++) {
    if (prime(i)) {
      cout << i << ' ';
      n--;
    }
    if (n == 0) return 0;
  }
  return 0;
}
