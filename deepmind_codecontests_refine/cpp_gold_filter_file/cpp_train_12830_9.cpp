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
  int count = 0;
  while (N) {
    count++;
    N = N / 10;
  }
  return count;
}
void solve() {
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(A, A + n);
  for (int i = n - 1; i >= 0; i--) {
    if (A[i] <= i + 1) {
      cout << i + 2 << "\n";
      return;
    }
  }
  cout << 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
