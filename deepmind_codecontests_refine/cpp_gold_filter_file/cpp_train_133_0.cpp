#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long number) {
  if (number == 2) return true;
  if (number < 2 || number % 2 == 0) return false;
  for (long long i = 3; i * i <= number; i += 2) {
    if (number % i == 0) return false;
  }
  return true;
}
long long findPrimeDivisor(long long number) {
  vector<long long> primes;
  long long divisor = 0, temp = number;
  for (long long i = 2; i * i <= temp; i += 2) {
    if (temp % i == 0) {
      primes.push_back(i);
      temp /= i;
      if (isPrime(temp)) {
        primes.push_back(temp);
      }
      i = 0;
    }
    if (i == 2) {
      i = 1;
    }
    if (primes.size() >= 2) {
      divisor = primes[0] * primes[1];
      if (divisor == number) return 0;
      return divisor;
    }
  }
  return divisor;
}
long long findWinner(long long number) {
  long long divisor;
  if (number == 1 || isPrime(number)) {
    return 0;
  }
  divisor = findPrimeDivisor(number);
  if (divisor == 0) {
    return 2;
  }
  return divisor;
}
int main() {
  long long q;
  cin >> q;
  long long winner = findWinner(q);
  if (winner != 2) cout << "1" << endl;
  cout << winner;
  return 0;
}
