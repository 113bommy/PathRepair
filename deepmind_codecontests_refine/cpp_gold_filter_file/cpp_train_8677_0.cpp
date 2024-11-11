#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
auto start = high_resolution_clock::now();
bool isInteger(double N) {
  int X = N;
  double temp2 = N - X;
  if (temp2 > 0) {
    return false;
  }
  return true;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    double key = sqrt(n);
    long long modifiedNumber;
    if (isInteger(key)) {
      modifiedNumber = key;
      if (isPrime(modifiedNumber)) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
