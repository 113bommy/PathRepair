#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void findAns() {
  int n;
  cin >> n;
  string a = "FastestFinger";
  string b = "Ashishgup";
  if (n == 1) {
    cout << a << "\n";
    return;
  }
  if (n == 2) {
    cout << b << "\n";
    return;
  }
  if (n % 2 == 1) {
    cout << b << "\n";
    return;
  }
  if ((n & (n - 1)) == 0) {
    cout << a << "\n";
    return;
  }
  if ((n & 4) != 0 and isPrime(n / 2))
    cout << a << "\n";
  else
    cout << b << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  long long int t;
  cin >> t;
  while (t--) findAns();
}
