#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, i, j, k, y, x, a, b;
  cin >> x;
  bool primes[1000001] = {false};
  for (i = 2; i <= 100000; i++) {
    if (primes[i] == false) {
      for (j = i; i * j <= 100000; j++) {
        primes[i * j] = true;
      }
    }
  }
  vector<long long int> factors;
  n = x;
  for (j = 2; j * j <= x; j++) {
    if (x % j == 0) {
      factors.push_back(j);
      while (x % j == 0) x /= j;
    }
  }
  if (x != 1) factors.push_back(x);
  long long int result = INT_MAX;
  for (j = 0; j < factors.size(); j++) {
    y = (n / factors[j] - 1) * factors[j];
    for (k = y + 1; k <= n; k++) {
      a = k;
      if (primes[a] == true) {
        for (b = 2; b * b <= a; b++) {
          if (a % b == 0) {
            result = min(result, (k / b - 1) * b + 1);
            while (a % b == 0) a /= b;
          }
        }
        if (a != 1) result = min(result, (k / a - 1) * a + 1);
      }
    }
  }
  cout << result;
  return 0;
}
