#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
void io_f() {}
int next_prime(int n) {
  for (int i = n; i < n + 1e5; i++) {
    int f = 0;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        f = 1;
        break;
      }
    }
    if (f == 0) {
      return i;
    }
  }
  return 7;
}
int main() {
  io_f();
  int n, k;
  cin >> n >> k;
  vector<int> res(n);
  int f = n % 2;
  if (n / 2 > k) {
    cout << -1;
    return 0;
  }
  if (n == 1 && k != 0) {
    cout << -1;
    return 0;
  }
  int k_prime = k - ((n - 2) / 2);
  cout << k_prime << " ";
  int x = 2 * k_prime;
  for (int i = 1; i < n; i++) {
    cout << x++ << " ";
  }
  return 0;
}
