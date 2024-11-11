#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
const long long MAX_SIZE = 1000001;
vector<long long> isprime(MAX_SIZE, true);
vector<long long> prime;
vector<long long> SPF(MAX_SIZE);
void manipulated_seive(int N) {
  isprime[0] = isprime[1] = false;
  for (long long int i = 2; i < N; i++) {
    if (isprime[i]) {
      prime.push_back(i);
      SPF[i] = i;
    }
    for (long long int j = 0;
         j < (int)prime.size() && i * prime[j] < N && prime[j] <= SPF[i]; j++) {
      isprime[i * prime[j]] = false;
      SPF[i * prime[j]] = prime[j];
    }
  }
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res % p;
}
int main() {
  long long i, j, n, m, b, t, x;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    long long a[n], sum = 0;
    map<long long, long long> mp;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]]++;
    }
    long long pre = 1;
    for (auto it = mp.begin(); it != mp.end(); it++) {
      b = it->first - pre;
      if (x >= b) {
        sum = it->first;
        x = x - b;
        pre = it->first;
      } else {
        sum += b;
        x = 0;
        break;
      }
    }
    if (x != 0) {
      sum += x;
    }
    cout << sum << "\n";
  }
  return 0;
}
