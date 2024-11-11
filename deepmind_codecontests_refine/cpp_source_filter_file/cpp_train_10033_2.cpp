#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
bool isAlmostPrime(int n) {
  int cnt = 0;
  for (int i = 2; i <= n; i++) {
    if (n % i == 0 && isPrime(i)) cnt++;
  }
  return cnt >= 2;
}
int main() {
  ios::sync_with_stdio(false);
  int n, cnt = 0;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    if (isAlmostPrime(i)) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
