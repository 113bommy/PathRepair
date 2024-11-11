#include <bits/stdc++.h>
using namespace std;
bool isprime(long long m) {
  long long p = sqrt(m + 1);
  if (m == 2) return true;
  if (m % 2 == 0) return false;
  for (long long i = 3; i < p; i += 2) {
    if (m % i == 0) return false;
  }
  return true;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, ans = 0;
    cin >> a >> b;
    if (abs(a - b) == 1 && isprime(a + b)) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
