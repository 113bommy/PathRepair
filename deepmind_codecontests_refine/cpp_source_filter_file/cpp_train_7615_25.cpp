#include <bits/stdc++.h>
using namespace std;
int nxt() {
  int x;
  cin >> x;
  return x;
}
long long int nxtl() {
  long long int x;
  cin >> x;
  return x;
}
void SieveOfEratosthenes(int n, vector<int> &primes) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prime[p]) primes.push_back(p);
}
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int power(long long int x, long long int y, long long int mod) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2, mod);
  if (y % 2 == 0)
    return (temp * temp) % mod;
  else
    return (((x * temp) % mod) * temp) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = nxt();
  while (t--) {
    long long int n = nxtl(), k = nxt();
    long long int x = 0;
    while (n > 0) {
      long long int r = n % k;
      n -= r;
      x += r;
      if (n > 0) {
        n /= k;
        x++;
      }
    }
    cout << x << endl;
  }
  return 0;
}
