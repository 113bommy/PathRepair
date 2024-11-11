#include <bits/stdc++.h>
using namespace std;
bool isprime(long long n) {
  long long i;
  if (n < 2) return false;
  if (n < 4) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (a - b == 1 && isprime(a + b))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
