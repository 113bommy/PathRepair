#include <bits/stdc++.h>
using namespace std;
long long n;
bool prime(long long x) {
  if (x <= 1) return 0;
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}
int main() {
  cin >> n;
  if (n == 3) cout << 1, exit(0);
  if (n == 4) cout << 2, exit(0);
  for (long long i = 1; i <= 10000; i++) {
    if (!prime(n * i + 1)) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
