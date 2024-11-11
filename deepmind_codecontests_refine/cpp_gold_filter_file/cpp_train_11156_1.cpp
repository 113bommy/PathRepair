#include <bits/stdc++.h>
using namespace std;
int power(long long int x, long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
bool prime_check(long long int n) {
  long long int i, j;
  if (n == 1) {
    return false;
  }
  for (i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
long long int fact(long long int n) {
  long long int prod = 1;
  for (long long int i = 1; i <= n; i++) {
    prod = (prod * i) % 1000000007;
  }
  return prod;
}
bool vowl(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
bool prime[2000];
void sieve() {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= 1900; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= 1900; i += p) prime[i] = false;
    }
  }
}
int main() {
  int n;
  cin >> n;
  sieve();
  int ans;
  if (prime[n] == true) {
    ans = n;
  } else {
    int p;
    for (int i = n + 1; i < 1900; i++) {
      if (prime[i] == true) {
        p = i;
        break;
      }
    }
    ans = p;
  }
  cout << ans << "\n";
  for (int i = 1; i < n; i++) cout << i << " " << i + 1 << "\n";
  cout << 1 << " " << n << "\n";
  ans -= n;
  for (int i = 1; i <= ans; i++) cout << i << " " << i + n / 2 << "\n";
}
