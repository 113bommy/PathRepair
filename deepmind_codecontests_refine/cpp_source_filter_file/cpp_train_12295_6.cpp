#include <bits/stdc++.h>
using namespace std;
long long modulo(long long a, long long b) {
  long long r = a % b;
  return r < 0 ? r + b : r;
}
bool prime[1000006];
void seive() {
  memset(prime, sizeof(prime), true);
  for (long long i = 2; i * i <= 1000006; i++) {
    if (prime[i])
      for (long long j = i * i; i <= 1000006; j += i) prime[i] = false;
  }
}
int main() {
  long long t = 1;
  if (0) cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    if (k % n == 0)
      cout << k / n << endl;
    else
      cout << k / (n + 1) << endl;
  }
}
