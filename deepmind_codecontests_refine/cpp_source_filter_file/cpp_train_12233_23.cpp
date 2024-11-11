#include <bits/stdc++.h>
using namespace std;
int maxi(long long int a, long long int b) { return (a > b ? a : b); }
int mini(long long int a, long long int b) { return (a < b ? a : b); }
int prime[1000001] = {0};
void sieve_of_erastosthenes(long long int n) {
  long long int p;
  for (p = 2; p * p <= n; p++) {
    if (prime[p] == 0) {
      for (long long int i = p * 2; i <= n; i += p) prime[i] = 1;
    }
  }
}
string toBinary(int n) {
  std::string r;
  while (n != 0) {
    r = (n % 2 == 0 ? "0" : "1") + r;
    n /= 2;
  }
  return r;
}
long long int fac(long long int x, long long int y) {
  long long int product = 1;
  long long int j = 1;
  for (int i = max(y, x - y) + 1; i <= x; i++) {
    product *= i;
    product /= j;
    j++;
  }
  return product;
}
vector<long long int> seet;
void primes(long long int n) {
  long long int i = 3;
  if (n % 2 == 0) {
    seet.push_back(2);
  }
  while (n % 2 == 0) n /= 2;
  while (i < sqrt(n)) {
    if (n % i == 0) seet.push_back(i);
    while (n % i == 0) n /= i;
    i += 2;
  }
  if (n > 1) seet.push_back(n);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  long long int result = 1;
  primes(n);
  for (long long int i = 0; i < seet.size(); i++) {
    result *= seet[i];
  }
  cout << result;
  return 0;
}
