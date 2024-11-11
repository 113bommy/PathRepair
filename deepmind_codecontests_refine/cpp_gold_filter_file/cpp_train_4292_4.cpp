#include <bits/stdc++.h>
int main() {
  int t;
  std::cin >> t;
  for (; t > 0; t--) {
    long n;
    std::cin >> n;
    int i = 2;
    std::vector<int> primes;
    while (i * i <= n) {
      if (n % i == 0) {
        while (n % i == 0) {
          primes.push_back(i);
          n /= i;
        }
      }
      i++;
    }
    if (n != 1) {
      primes.push_back(n);
    }
    if (primes.size() < 3) {
      std::cout << "NO\n";
      continue;
    }
    long a = primes[0];
    long b = primes[1];
    int next_prime = 2;
    if (a == b) {
      b *= primes[next_prime++];
    }
    if (primes.size() <= next_prime) {
      std::cout << "NO\n";
      continue;
    }
    long c = primes[next_prime++];
    while (next_prime < primes.size()) {
      c *= primes[next_prime++];
    }
    if (c == a or c == b) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
      std::cout << a << " " << b << " " << c << "\n";
    }
  }
}
