#include <bits/stdc++.h>
using namespace std;
long long int N = 1e5 + 10;
long long int prime[30000];
bool mark[100010];
long long int primelen;
void sieve() {
  long long int limit = sqrt(N * 1.0) + 2;
  for (long long int i = 4; i <= N; i += 2) mark[i] = 1;
  prime[primelen++] = 2;
  for (long long int i = 3; i <= N; i += 2) {
    if (!mark[i]) {
      prime[primelen++] = i;
      if (i <= limit) {
        for (long long int j = i * i; j <= N; j += i) mark[j] = 1;
      }
    }
  }
}
bool isprime(long long int n) {
  if (n < 2) return false;
  if (!(n % 2) && n != 2) return false;
  long long int limit = sqrt(n * 1.0) + 2;
  for (long long int i = 2; i <= limit; i += 2) {
    if (!(n % 2)) return false;
  }
  return true;
}
int main() {
  sieve();
  long long int n;
  long long int res = 0;
  cin >> n;
  while (n) {
    if (isprime(n)) {
      res++;
      break;
    }
    if (!(n % 2)) {
      res += n / 2;
      break;
    }
    for (long long int i = 0; i < primelen; i++) {
      if (!(n % prime[i])) {
        n -= prime[i];
        res++;
        break;
      }
    }
  }
  cout << res << endl;
  return 0;
}
