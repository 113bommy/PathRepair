#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<long long> prime_factors;
  for (long long i = 2; i * i < n; i++) {
    if (n % i == 0) {
      n /= i;
      prime_factors.push_back(i);
    }
  }
  if (n > 1) prime_factors.push_back(n);
  if (prime_factors.size() <= 1) {
    cout << "1\n0";
    return 0;
  }
  if (prime_factors.size() == 2) {
    cout << 2;
    return 0;
  }
  cout << "1\n" << prime_factors[0] * prime_factors[1];
}
