#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main() {
  cin >> n >> k;
  if (k / 2 + 1 > n) {
    cout << "0";
    return 0;
  }
  if (k < n) {
    cout << (k - 1) / 2;
    return 0;
  }
  if (n == 1) {
    cout << "0";
    return 0;
  }
  if (n == k) {
    cout << (n - 1) / 2;
    return 0;
  }
  if (n + 1 == k && n % 2 == 1) {
    cout << k / 2 - 1;
    return 0;
  }
  if (n + 1 == k && n % 2 == 0) {
    cout << k / 2;
    return 0;
  }
  long long half = k / 2;
  cout << n - half;
  return 0;
}
