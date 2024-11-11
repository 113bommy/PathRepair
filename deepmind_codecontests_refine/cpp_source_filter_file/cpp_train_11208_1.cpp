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
bool isPerfectSquare(long double x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
long long highestPowerof2(long long n) {
  if (n < 1) return 0;
  int res = 1;
  for (int i = 0; i < 8 * sizeof(unsigned int); i++) {
    int curr = 1 << i;
    if (curr > n) break;
    res = curr;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long i, j, m, b, t, k;
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long x = 1;
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1] && s[i] == 'x') {
      x++;
    } else {
      if (x > 2) {
        ans += x - 2;
      }
      x = 0;
    }
  }
  if (x > 2) ans += x - 2;
  cout << ans << endl;
}
