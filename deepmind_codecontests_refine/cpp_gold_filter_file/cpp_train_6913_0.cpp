#include <bits/stdc++.h>
using namespace std;
long long prime[1000000];
void sieve() {
  prime[0] = 0;
  prime[1] = 0;
  for (int i = 2; i < 1000000; i++) prime[i] = 1;
  for (int i = 2; i * i < 1000000; i++)
    if (prime[i] == 1)
      for (int j = i * i; j < 1000000; j += i) prime[j] = 0;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i <= floor(sqrt(n)); i++)
    if (n % i == 0) return false;
  return true;
}
int countdigits(int N) {
  N = abs(N);
  while (N) {
    int dig = N % 10;
    if (dig == 8) {
      return 1;
    }
    N = N / 10;
  }
  return 0;
}
void solve() {
  int k, d;
  string S;
  cin >> k >> d;
  if (d == 0) {
    if (k == 1)
      cout << "0";
    else
      cout << "No solution";
  } else if (d > 0) {
    cout << d;
    for (int i = 1; i < k; i++) {
      cout << 0;
    }
  } else
    cout << "No solution";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
