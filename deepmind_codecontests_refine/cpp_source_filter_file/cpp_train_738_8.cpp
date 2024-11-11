#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 9;
long long isPrime(long long n) {
  if (n < 2) return 0;
  if (n == 2) return 1;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long n;
  cin >> n;
  if (n % 2 == 0) cout << n / 2;
  if (isPrime(n))
    cout << 1;
  else {
    for (long long i = 3; i * i <= n; i += 2) {
      if (n % i == 0) {
        cout << (n - i) / 2 + 1 << "\n";
        return 0;
      }
    }
  }
}
