#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n) {
  if (n <= 1) return false;
  if (n == 2 || n == 3 || n == 5 || n == 7)
    return true;
  else if (n % 2 == 0 || n % 3 == 0)
    return false;
  else {
    int r = 5;
    while (r * r <= n) {
      if (n % r == 0) return false;
      r += 2;
      if (n % r == 0) return false;
      r += 4;
    }
    return true;
  }
}
int ModExp(int x, int n, int M) {
  int result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % M;
    x = (x * x) % M;
    n = n / 2;
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << (abs(b - a) / 10) + (abs(b - a) % 10 != 0) << endl;
  }
  return 0;
}
