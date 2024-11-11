#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = (ans * a);
    }
    a = (a * a);
    b >>= 1;
  }
  return ans;
}
vector<long long> primes;
void prime(long long n) {
  long long i;
  int isprime[10000000 + 1];
  for (i = 0; i < n + 1; i++) isprime[i] = 1;
  for (i = 2; i * i <= n; i++) {
    if (isprime[i]) {
      for (long long j = i * i; j <= n; j += i) {
        isprime[j] = 0;
      }
    }
  }
  primes.push_back(2);
  for (i = 3; i <= n; i += 2) {
    if (isprime[i]) primes.push_back(i);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, j, i, l = 0, s = 0, m;
  cin >> n >> m;
  long long a[n];
  long long b[m];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < m; i++) cin >> b[i];
  for (i = 0, j = 0; j < m, i < n;) {
    if (a[i] <= b[j]) {
      l++;
      i++;
      j++;
    } else
      i++;
  }
  cout << l;
  return 0;
}
