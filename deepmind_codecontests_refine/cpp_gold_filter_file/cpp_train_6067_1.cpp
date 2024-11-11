#include <bits/stdc++.h>
using namespace std;
const int N = 50001;
const int M = 1e9 + 7;
vector<int> isprime(1e6 + 1, 1);
vector<int> primes;
void sieve() {
  isprime[0] = isprime[1] = 0;
  for (int i = 2; i * i <= 1e6; i++) {
    if (isprime[i]) {
      for (int j = i * i; j <= 1e6 + 1; j += i) {
        isprime[j] = 0;
      }
    }
  }
}
void get_primes() {
  sieve();
  for (int i = 3; i <= 1e6; i++)
    if (isprime[i]) primes.push_back(i);
}
int bs(long long int n) {
  n -= (n % 2 == 0);
  long long int l = 1;
  long long int h = n;
  while (h - l > 0) {
    long long int mid = l + (h - l) / 2;
    mid -= ((mid & 1) == 0);
    if (mid < 0) return 1;
    if (mid * mid == n) return mid;
    if (mid * mid > n)
      h = mid - 2;
    else
      l = mid + 2;
  }
  h -= (h % 2 == 0);
  l -= (l % 2 == 0);
  if (h * h <= n)
    return h;
  else if (l * l <= n)
    return l;
  return l - 2;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  get_primes();
  while (t--) {
    int n;
    cin >> n;
    if (n < 4) {
      cout << n << "\n";
      continue;
    }
    if (n <= 8) {
      cout << (n + 1 - (n % 2 == 0)) / 2 << "\n";
      continue;
    }
    int x1 = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
    int x2 = upper_bound(primes.begin(), primes.end(), bs(n)) - primes.begin();
    cout << x1 - x2 + 1 << "\n";
  }
  return 0;
}
